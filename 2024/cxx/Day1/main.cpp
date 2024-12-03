#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <numeric>

int main()
{
    /*===============================
        PART 1
    ================================*/

    std::ifstream file("input.txt");
    std::string line;

    // Variables
    std::vector<int> left, right;

    unsigned int l,r; // variables for line read


    while (std::getline(file, line))
    {
        std::stringstream(line) >> l >> r;
        
        left.push_back(l); right.push_back(r);
    }

    // Sort arrays
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    // Compute difference
    std::vector<int> diff;
    unsigned int n{left.size()};

    for (unsigned int i=0; i<n ; i++)
        diff.push_back(abs(right.at(i) - left.at(i)));

    unsigned int sum = std::accumulate(diff.begin(), diff.end(), 0);

    std::cout << "sum: " << sum << std::endl;

    /*===============================
        PART 2
    ================================*/

    std::vector<unsigned int> similarity;

    for (auto i : left)
    {
        unsigned int same{0};

        for (auto j : right)
        {
            if (i == j)
            {
                same++;
            }
        }

        similarity.push_back(i * same);
        
    }

    int similarity_score = std::accumulate(similarity.begin(), similarity.end(), 0);

    std::cout << "Similarity score: " << similarity_score << std::endl;

    return 0;
}