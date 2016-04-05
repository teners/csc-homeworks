#include "matrices.hpp"

int main(int argc, char ** argv)
{
    if (argc % 2)
    {
       std::cerr << "Wrong arguments number.\n";
       return 1;
    }

    Matrix result;

    for (int arg = 0; arg < argc; arg += 2)
    {
        try
        {
            if (arg)
            {
                std::string operation = static_cast<std::string>(argv[arg]);
                if (operation == "--add")
                {
                    Matrix temp;
                    temp.read_from_file(argv[arg + 1]);
                    result += temp;
                }
                else if (operation == "--mult")
                {
                    Matrix temp;
                    temp.read_from_file(argv[arg + 1]);
                    result *= temp;
                }
                else
                {
                    throw std::runtime_error("no such operation is defined");
                }

            }
            else
            {
                result.read_from_file(argv[arg + 1]);
            }

        }
        catch(std::ifstream::failure const& e)
        {
            std::cerr << "Something bad with file: " << e.what() << std::endl;
            return 2;
        }
        catch(std::logic_error const& e)
        {
            std::cerr << "Failed to execute an operation: " << e.what() << std::endl;
            return 3;
        }
        catch(std::exception const& e)
        {
            std::cerr << "Something went wrong: " << e.what() << std::endl;
            return 4;
        }
    }

    std::cout << result;
	return 0;
}
