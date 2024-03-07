
// g++ -std=c++11 lee-code-merge-sort.cpp -o lee-code-merge-sort
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> coreMergeIntervals(std::vector<std::vector<int>> &intervals);

int main()
{

    std::vector<std::vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({8, 10});
    intervals.push_back({2, 6});
    intervals.push_back({15, 18});
    printf("intput intervales:");
    for (auto &it : intervals)
    {
        printf("[%d, %d] ", it[0], it[1]);
    }
    printf("\n");

    coreMergeIntervals(intervals);
}

bool mergeInterval(std::vector<int> a, std::vector<int> b)
{
    return a[0] < b[0];
}

std::vector<std::vector<int>> coreMergeIntervals(std::vector<std::vector<int>> &intervals)
{

    // do merge sort, if ex:[a1,a2],[b1,b2] a2> b1 then should merge to [a1,b2]

    std::sort(intervals.begin(), intervals.end(), mergeInterval);

    std::vector<std::vector<int>> vSort = {};

    for (int i = 0; i < intervals.size() - 1; i++)
    {
        // if a2> b1 then vector(i+1) = [a1,b2], if not then push it to vSort
        if (intervals[i][1] >= intervals[i + 1][0])
        {
            intervals[i + 1] = {intervals[i][0], intervals[i + 1][1]};
            if (i == intervals.size() - 2)
            {
                vSort.push_back(intervals[i+1]);
            }
        }
        else
        {
            
            vSort.push_back(intervals[i]);
            if (i == intervals.size() - 2)
            {
                vSort.push_back(intervals[i+1]);
            }
        }
    }

    for (auto &it : vSort)
    {
        printf("[%d, %d] ", it[0], it[1]);
    }

    return intervals; // remember to change your return values
}

// void leetcode_merge_interval()
// {

// /*
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
// and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104

// */

//     std::vector<std::vector<int>> intervals;
//     intervals.push_back({1, 3});
//     intervals.push_back({2, 6});
//     intervals.push_back({8, 10});
//     intervals.push_back({15, 18});
//     printf("intput intervales:");
//     for(auto& it: intervals)
//     {
//         printf("[%d, %d] ", it[0], it[1]);
//     }
//     printf("\n");

//     std::vector<std::vector<int>> outResults;
//     outResults= coreMergeIntervals(intervals);

//     printf("merged intervales:");
//     for(auto& it: outResults)
//     {
//         printf("[%d, %d] ", it[0], it[1]);
//     }
//     printf("\n");

// }

// bool myDecComp(int a, int b)
// {
//     return (a > b);
// }

// bool myDecByValue(std::pair<int, int>& ita, std::pair<int, int>& itb)
// {
//     return (ita.second > itb.second);
// }

// void algo_builtin_sort()
// {

//     std::vector<int> inVec{6, 1, 4, 7, 3, 5};

//     //C++ built-in sort : https://cplusplus.com/reference/algorithm/sort/
//     // sort() : O(nLog(n))

//     //ascending sort
//     printf("ascending sort:\n");
//     std::sort(inVec.begin(), inVec.end() );
//     for(auto& it : inVec)
//     {
//         printf("%d\n", it);
//     }
//     printf("\n");

//     //descending sort
//     printf("descending sort:\n");
//     std::sort(inVec.begin(), inVec.end(), myDecComp);
//     for(auto& it : inVec)
//     {
//         printf("%d\n", it);
//     }
//     printf("\n");

//     std::map<int, int> data;
//     data[9]= 19; //key = 9, value = 19
//     data[8]= 11;
//     data[6]= 23;
//     data[1]= 10;
//     data[5]= 98;
//     data[2]= 50;

//     printf("map output\n");
//     for(auto& it : data)
//     {
//         printf("<%d, %d>\n", it.first, it.second);
//     }
//     printf("\n");

//     //map -> pair for sorting by value
//     std::vector<std::pair<int, int>> vec;
//     for(auto& it:data)
//     {
//         std::pair<int, int> obj{it.first, it.second};
//         vec.push_back(obj);
//     }

//     std::sort(vec.begin(), vec.end(), myDecByValue);
//     printf("reorded\n");
//     for(auto& it : vec)
//     {
//         printf("<%d, %d>\n", it.first, it.second);
//     }
//     printf("\n");

// }