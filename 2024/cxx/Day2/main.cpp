#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

bool is_respecting_increase_decrease_rule(int n)
{
    return (n == 0 || abs(n) > 3) ? true : false;
}

std::vector<int>::iterator change_rule(std::vector<int> seq, bool is_increasing)
{
    auto viter = seq.begin();

    for (; viter != seq.end(); ++viter)
    {
        // check the change between next iterator

        int change = *(viter + 1) - *viter;

        if (!is_respecting_increase_decrease_rule)
            return viter; // means it changed direction

        bool change_rule = is_respecting_increase_decrease_rule(change);

        if (!change_rule)
        {
            return viter; // means that it did not reached end thus an error happened
        }
    }

    return seq.end(); // Return end means the sequence is good
}

bool change_by_n(std::vector<int> seq)
{
    /*
            Determine n, either -2,-1,1,2 or 3
    */

    int n = seq.at(1) - seq.at(0);

    if (is_respecting_increase_decrease_rule(n))
        return false; // means that it does not respect the rules

    // Now check that it is either increasing or decreasing
    bool increase = n > 0 ? true : false;

    for (long unsigned int i = 1; i < seq.size(); i++)
    {
        // 1) check the change of direction
        int ni = seq.at(i) - seq.at(i - 1);

        bool increase2 = ni > 0 ? true : false;

        if (increase != increase2)
            return false; // quit because its changing direction

        // 2) check the increase size

        if (is_respecting_increase_decrease_rule(ni))
            return false; // means that it does not respect the rules
    }

    return true; // if it gets here it means it as respected all condition

    // means increase was
}

std::vector<int>::iterator change_by_n2(std::vector<int> &seq)
{
    // check increase or decrease with begin and end
    bool is_increasing = *(seq.end()) > *(seq.begin()) ? true : false; //! Potentially an error if the first one is the one to remove (either too large or too small, same for the last one)

    auto seqiter = change_rule(seq, is_increasing);

    if (seqiter == seq.end())
    {
        return seq.end();
    }
    else
    {
        // damper
        std::remove(seq.begin(), seq.end(), seqiter);

        // call change rule again

        seqiter = change_rule(seq, is_increasing);

        return seqiter;
    }
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
        // vint.erase(vint.begin());

        // if (change_by_n2(vint) == vint.end())
        if (change_by_n2(vint) != vint.end())
        {
            safe++;
            std::cout << "line#:" << line_num << std::endl;
        }

        line_num++;
    }

    std::cout << "Safe count: " << safe << std::endl;

    return 0;
}