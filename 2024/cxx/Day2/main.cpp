#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool change_by_n(std::vector<int> seq)
{
    /*
            Determine n, either -2,-1,1,2 or 3
    */

    int n = seq.at(1) - seq.at(0);

    if (n != -2 && n != -1 && n != 1 && n != 1 && n != 3)
        return false; // means that it does not respect the rules

    // Now check that it is either increasing or decreasing
    bool increase = n > 0 ? true : false;

    for (int i = 1; i < seq.size(); i++)
    {
        // 1) check the change of direction
        int ni = seq.at(i) - seq.at(i-1);

        bool increase2 = ni > 0 ? true : false;

        if (increase !=  increase2)
            return false; // quit because its changing direction

        // 2) check the increase size

        if (ni != -2 && ni != -1 && ni != 1 && ni != 1 && ni != 3)
            return false; // means that it does not respect the rules 
    }

    return true; // if it gets here it means it as respected all condition

    // means increase was
}

int main()
{
    // initilize variables
    int safe{0};
    int line_num{1};

    // Read file
    std::ifstream file("input.txt");
    std::string line;

    while (std::getline(file, line))
    {
        // Parse each line as sstream, parse each int of each line
        std::stringstream report(line);

        int val; // value to be read

        std::vector<int> vint; // container

        while (report >> val) // parse untill end
            vint.push_back(val);

        // Remove id, use the change_by_n function
        vint.erase(vint.begin());

        if (change_by_n(vint))
        {
            safe++;
            std::cout << "line#:" << line_num << std::endl;
        }

        line_num++;

    }

    std::cout << "Safe count: " << safe << std::endl;

    return 0;
}