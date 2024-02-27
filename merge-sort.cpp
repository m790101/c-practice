// g++ -std=c++11 merge-sort.cpp -o merge-sort

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <random>
#include <string>

std::vector<int> compare(std::vector<int> vectorR, std::vector<int> vectorL, int i, int j, std::vector<int> vSort);

int main()
{
    std::vector<int> foo = {1, 5, 3, 7, 9};

    int mid = foo.size() / 2;
    std::vector<int> vectorR(foo.begin() + mid, foo.end());
    std::vector<int> vectorL(foo.begin(), foo.begin() + mid);

    std::cout << "vectorL" << std::endl;
    for (int i = 0; i < vectorL.size(); i++)
    {
        std::cout << vectorL[i] << std::endl;
    }
    std::cout << "vectorR" << std::endl;
    for (int i = 0; i < vectorR.size(); i++)
    {
        std::cout << vectorR[i] << std::endl;
    }

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

void mergeSort(std::vector<int> v)
{
    // divide in half if there are more than 1 element
    if (v.size > 1)
    {
        int mid = foo.size() / 2;
        std::vector<int> vectorR(v.begin() + mid, v.end());
        return mergeSort(vectorR);
        std::vector<int> vectorL(v.begin(), v.begin() + mid);
        return mergeSort(vectorL);
    }

    // when it goes to the base case, compare left and right and merge them

    // compare left and right
    int i = 0;
    int j = 0;
    std::vector<int> vSort = {};
    compare(vectorR, vectorL, i, j);

    // merge: walk from both side index = 0, compare them
    // if one side is bigger , put the smaller side to the sorted vector and compare next one from smaller side with the bigger side
    // until both side are empty
}

std::vector<int> compare(std::vector<int> vectorR, std::vector<int> vectorL, int i, int j, std::vector<int> vSort)
{

    //  run out of both
    if (vectorL.size() <= i && vectorR.size() <= j)
    {
        return vSort;
    }

    if (vectorL.size() == 0 && vectorR.size() == 0)
    {
        return vSort;
    }
    //  run out of left and still have right
    if (vectorL.size() <= i && vectorR.size() > j)
    {
        vSort.push_back(vectorR[j]);
        j++;
    }
    //  run out of right and still have left
    if (vectorR.size() <= j && vectorL.size() > i)
    {
        vSort.push_back(vectorL[i]);
        i++;
    }

    if (vectorL.size() > i && vectorR.size() > j)
    {

        //  left less than right
        if (vectorL[i] < vectorR[j])
        {
            vSort.push_back(vectorL[i]);
            i++;
        }
        else //  right less than left
        {
            vSort.push_back(vectorR[j]);
            j++;
        }
    }

    return compare(vectorR, vectorL, i, j, vSort);
}
