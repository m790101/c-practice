// g++ -std=c++11 merge-sort.cpp -o merge-sort

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <random>
#include <string>

std::vector<int> compare(std::vector<int> vectorR, std::vector<int> vectorL, int i, int j, std::vector<int> vSort);

std::vector<int> mergeSort(std::vector<int> v);

int main()
{
    std::vector<int> foo = {1, 5, 3, 7, 9};
    std::vector<int> result = mergeSort(foo);

    std::cout << "vector" << std::endl;
    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << std::endl;
    }

    return 0;
}

std::vector<int> mergeSort(std::vector<int> v)
{
    if (v.size() < 2)
    {
        return v;
    }
    // divide in half if there are more than 1 element
    int mid = v.size() / 2;
    std::vector<int> vectorR(v.begin() + mid, v.end());
    std::vector<int> vectorL(v.begin(), v.begin() + mid);
    std::vector<int> vSort = {};

    int i = 0;
    int j = 0;
    return compare(mergeSort(vectorR), mergeSort(vectorL), i, j, vSort);


    // when it goes to the base case, compare left and right and merge them

    // compare left and right

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
