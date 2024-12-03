#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
    // initilize variables
    int safe{0};

    // Read file
    std::ifstream file("input.txt");
    std::string line;

    while(std::getline(file, line))
    {
        std::stringstream report(line);

        int id, l1, l2, l3,l4,l5;

        report >> id >> l1 >> l2 >> l3 >> l4 >> l5;

        std::cout << id << " "
                    << l1 << " "
                    << l2 << " "
                    << l3 << " "
                    << l4 << " "
                    << l5 << std::endl;

    }

    return 0;
}