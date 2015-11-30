#include "huffman.hpp"
#include <queue>
#include <fstream>

using pr_queue = std::priority_queue<Tree*, std::vector<Tree*>, CompareNodes>;

un_map_i count_frequency(std::ifstream & ifstream)
{
    un_map_i frequency;
    char symbol = ' ';

    while (ifstream.peek() != std::ifstream::traits_type::eof() && ifstream.get(symbol))
    {
        ++frequency[symbol];
    }

    ifstream.seekg(0);

    return frequency;
}

Tree* build_tree(un_map_i const& frequency)
{
    pr_queue pqueue;
    for (auto it = frequency.begin(); it != frequency.end(); ++it)
    {
        pqueue.push(std::move(new Tree(it->first, it->second)));
    }

    while (pqueue.size() > 1)
    {
        Tree * left = pqueue.top();
        pqueue.pop();
        Tree * right = pqueue.top();
        pqueue.pop();
        pqueue.push(std::move(new Tree(left, right)));
    }
    auto ret_value(pqueue.top());
    return ret_value;
}

std::vector<bool> code;
void make_dictionary(Tree const& root,
                     un_map_b &  dictionary) noexcept
{
    if (root.m_left)
    {
        code.push_back(false);
        make_dictionary(*root.m_left, dictionary);
    }
    if (root.m_right)
    {
        code.push_back(true);
        make_dictionary(*root.m_right, dictionary);
    }
    else
    {
        if (code.empty())
        {
            code.push_back(false);
        }
        dictionary[root.letter] = code;
    }
    code.pop_back();
}

void pack_tree(Tree const&   root,
               std::string & fill_me) noexcept
{
    if (root.code == "")
    {
        fill_me += '0';
    }
    if (root.m_left && root.m_right)
    {
        pack_tree(*root.m_left, fill_me);
        pack_tree(*root.m_right, fill_me);
    }
    else
    {
        fill_me += '1';
        fill_me += root.letter;
    }
}

void compress_file(std::string const& input,
                   std::string const& output)
{
    std::ifstream ifstream(input, std::ios::binary);
    std::ofstream ofstream(output, std::ios::binary);
    if (ifstream.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "0\n0\n0\n";
        return;
    }

    auto frequency = count_frequency(ifstream);
    Tree* root = build_tree(frequency);

    un_map_b dictionary;
    make_dictionary(*root, dictionary);

    unsigned long long output_count = 0;
    unsigned long long packed_count = 0;
    std::string packed_tree         = "";

    pack_tree(*root, packed_tree);
    ofstream << packed_tree << '\n';
    packed_count += packed_tree.size();

    auto input_count = write_file(ifstream, ofstream, dictionary);

    std::cout << input_count << std::endl << output_count << std::endl << packed_count << std::endl;
}

unsigned write_file(std::ifstream & ifstream,
                    std::ofstream & ofstream,
                    un_map_b const& dictionary)
{
    unsigned output_count = 0;
    char               symbol;

    ifstream.seekg(0, std::ios::beg);

    int temp_count = 0;
    std::uint32_t temp = 0;
    std::vector<bool> symbol_code;

    while (ifstream.get(symbol))
    {
        symbol_code = dictionary.at(symbol);
        for (int i = 0; i < symbol_code.size(); ++i)
        {
            if (temp_count == 31)
            {
                ofstream << temp;
                temp_count = 0;
                temp = 0;
            }
            ++output_count;
            temp |= symbol_code[i] << temp_count++;
        }
    }
    ofstream << temp;
    return output_count;
}

Tree::Tree(Tree const& rhs) noexcept
{
    m_right = rhs.m_right;
    m_left  = rhs.m_left;
    weight  = rhs.weight;
    code    = rhs.code;
    letter  = rhs.letter;
}

Tree::Tree(char letter, int weight) noexcept
{
    m_left       = nullptr;
    m_right      = nullptr;
    this->weight = weight;
    this->letter = letter;
    code         = "";
}

Tree::Tree(Tree * left, Tree * right) noexcept
{
    m_left = left;
    m_right = right;
    letter = ' ';
    code = "";
    weight = left->weight + right->weight;
}

bool operator<(Tree const& lhs, Tree const& rhs) noexcept
{
    return lhs.weight < rhs.weight;
}

Tree::~Tree()
{
    erase_tree(m_left);
    erase_tree(m_right);
}

void erase_tree(Tree * root)
{
    if (root->m_left)
    {
        erase_tree(root->m_left);
    }
    if (root->m_right)
    {
        erase_tree(root->m_right);
    }
    delete root->m_left;
    delete root->m_right;
}