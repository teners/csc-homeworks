#include "huffman.hpp"

int main (int argc, char ** argv)
{
    std::string input;
    std::string output;
    Mode mode;

    if (argc == 6)
    {
        for (size_t i = 1; i < argc; ++i)
        {
            if (argv[i] == std::string("-c"))
            {
                mode = Mode::compress;
            }
            else
            if (argv[i] == std::string("-u"))
            {
                mode = Mode::extract;
            }
            else
            if (argv[i] == std::string("-f") || argv[i] == std::string("--file"))
            {
                input = argv[++i];
            }
            else
            if (argv[i] == std::string("-o") || argv[i] == std::string("--output"))
            {
                output = argv[++i];
            }
            else
            {
                std::cerr << "Wrong command line arguments.\n";
                std::cerr << "Usage:\n" << "-c\tcompress file\n" << "-u\textract file\n" << "-f, --file filename\tpath to input file\n" << "-o, --output filename\tpath to output file\n";
                return 1;
            }
        }
    }
    else
    {
        std::cerr << "Wrong number of command line arguments.\n";
        std::cerr << "Usage:\n" << "-c\t\tcompress file\n" << "-u\t\textract file\n" << "-f, --file filename\tpath to input file\n" << "-o, --output filename\tpath to output file\n";
        return 2;
    }
    try
    {
        if (mode == Mode::compress)
        {
            compress_file(input, output);
        }
        else
        {
            //extract_file(input, output);
        }
    }
    catch (std::runtime_error const& exception)
    {
        //do something
    }    
    catch(std::exception const& exception)
    {
        //do something
    }
    return 0;
}
