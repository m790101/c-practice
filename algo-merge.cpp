// g++ -std=c++11 algo-merge.cpp -o algo-merge

#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <string>

void algo_mergesort();
std::vector<std::pair<std::string, int>> combine(std::vector<std::pair<std::string, int>> left, std::vector<std::pair<std::string, int>> right);
std::vector<std::pair<std::string, int>> merge_sort(std::vector<std::pair<std::string, int>> v);
std::vector<std::pair<std::string, int>> combine_from_fist_letter(std::vector<std::pair<std::string, int>> left, std::vector<std::pair<std::string, int>> right);
std::vector<std::pair<std::string, int>> merge_sort_letter(std::vector<std::pair<std::string, int>> v);
int main()
{

    algo_mergesort();

    return 0;
}

// Class 4: HW- merge sort
void algo_mergesort()
{
    // please refer to this explanation
    //  https://medium.com/karuna-sehgal/a-simplified-explanation-of-merge-sort-77089fe03bb2

    std::unordered_map<std::string, int> studentScores;
    studentScores["John"] = 50;
    studentScores["Apple"] = 70;
    studentScores["Ken"] = 30;
    studentScores["Adam"] = 70;
    studentScores["Halley"] = 90;
    studentScores["Tom"] = 100;
    studentScores["Kevin"] = 75;
    studentScores["Catty"] = 70;
    studentScores["Lora"] = 67;

    // Question 1: Please print student names and scores based on their scores at descending order.

    // make a pair in vector
    std::vector<std::pair<std::string, int>> v(studentScores.begin(), studentScores.end());

    // // merge sort with number
    std::vector<std::pair<std::string, int>> result = merge_sort(v);

    for (auto it = result.begin(); it != result.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

        std::cout << "-------------------------Q1 end----------------" << std::endl;

    // Question 2: Please print student names and scores based on their names at alphabet order.


    //merge sort with fist letter in key (string to ascii number)
    std::vector<std::pair<std::string, int>> result2 = merge_sort_letter(v);

    for (auto it = result2.begin(); it != result2.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

}

std::vector<std::pair<std::string, int>> merge_sort(std::vector<std::pair<std::string, int>> v)
{
    if (v.size() < 2)
    {
        return v;
    }
    int mid = v.size() / 2;
    std::vector<std::pair<std::string, int>> left(v.begin(), v.begin() + mid);
    std::vector<std::pair<std::string, int>> right(v.begin() + mid, v.end());

    return combine(merge_sort(left), merge_sort(right));
}

std::vector<std::pair<std::string, int>> merge_sort_letter(std::vector<std::pair<std::string, int>> v)
{
    if (v.size() < 2)
    {
        return v;
    }
    int mid = v.size() / 2;
    std::vector<std::pair<std::string, int>> left(v.begin(), v.begin() + mid);
    std::vector<std::pair<std::string, int>> right(v.begin() + mid, v.end());

    return combine_from_fist_letter(merge_sort_letter(left), merge_sort_letter(right));
}

std::vector<std::pair<std::string, int>> combine_from_fist_letter(std::vector<std::pair<std::string, int>> left, std::vector<std::pair<std::string, int>> right)
{
    int l = 0;
    int r = 0;
    std::vector<std::pair<std::string, int>> vSort;

    while (true)
    {

        //  run out of both
        if (left.size() <= l && right.size() <= r)
        {
            break;
        }

        if (left.size() == 0 && right.size() == 0)
        {
            break;
        }
        //  run out of left and still have right
        if (left.size() <= l && right.size() > r)
        {
            vSort.push_back(right[r]);
            r++;
        }
        //  run out of right and still have left
        if (right.size() <= r && left.size() > l)
        {
            vSort.push_back(left[l]);
            l++;
        }

        if (left.size() > l && right.size() > r)
        {

            //  left less than right
            if ((left[l].first[0]) < right[r].first[0])
            {
                vSort.push_back(left[l]);
                l++;
            }
            else //  right less than left
            {
                vSort.push_back(right[r]);
                r++;
            }
        }
    }

    return vSort;
}



std::vector<std::pair<std::string, int>> combine(std::vector<std::pair<std::string, int>> left, std::vector<std::pair<std::string, int>> right)
{
    int l = 0;
    int r = 0;
    std::vector<std::pair<std::string, int>> vSort;

    while (true)
    {

        //  run out of both
        if (left.size() <= l && right.size() <= r)
        {
            break;
        }

        if (left.size() == 0 && right.size() == 0)
        {
            break;
        }
        //  run out of left and still have right
        if (left.size() <= l && right.size() > r)
        {
            vSort.push_back(right[r]);
            r++;
        }
        //  run out of right and still have left
        if (right.size() <= r && left.size() > l)
        {
            vSort.push_back(left[l]);
            l++;
        }

        if (left.size() > l && right.size() > r)
        {

            //  left less than right
            if (left[l].second < right[r].second)
            {
                vSort.push_back(left[l]);
                l++;
            }
            else //  right less than left
            {
                vSort.push_back(right[r]);
                r++;
            }
        }
    }

    return vSort;
}
