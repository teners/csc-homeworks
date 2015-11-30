#pragma once

#include <unordered_map>
#include <string>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

using un_map_i = std::unordered_map<char, int>;
using un_map_s = std::unordered_map<char, std::string>;
using un_map_b = std::unordered_map<char, std::vector<bool>>;

enum class Mode
{
    compress, extract
};

// comparison operators overloading is needed!
class Tree
{
public:
    Tree        * m_left;
    Tree        * m_right;
    char          letter;
    int           weight;
    std::string   code;

public:
    explicit Tree(Tree const& rhs) noexcept;
    explicit Tree(char letter, int weight) noexcept;
    explicit Tree(Tree * left, Tree * right) noexcept;
    Tree(Tree && rhs) = default;
    Tree & operator=(Tree && rhs) = default;
    ~Tree() noexcept;
    friend bool operator<(Tree const& lhs, Tree const& rhs) noexcept;
};


class CompareNodes
{
public:
    bool operator() (const Tree * lhs, const Tree * rhs) const
    {
        return lhs->weight > rhs->weight;
    }
};
void erase_tree(Tree * root);

void compress_file(std::string const& input,
                   std::string const& output);

void make_dictionary(Tree const*& root,
                     un_map_s &   dictionary) noexcept;

void pack_tree(Tree const&   root,
               std::string & fill_me) noexcept;

un_map_i count_frequency(std::ifstream & ifstream);

Tree* build_tree(un_map_i const& frequency);

unsigned write_file(std::ifstream & ifstream,
                    std::ofstream & ofstream,
                    un_map_b const& dictionary);

void extract_file(std::string const& input,
                  std::string const& output);
