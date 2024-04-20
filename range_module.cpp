
// g++ -std=c++11 range_module.cpp -o range_module
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

// 10 - 180
// 150 - 200

class RangeModule
{
private:
    std::map<int, int> schedule;

public:
    RangeModule()
    {
    }
    void addRange(int left, int right)
    {
        // check if there is data at start time
        if (schedule.find(left) != schedule.end())
        {
            // check if the new end time > end time
            if (right >= schedule[left])
            {
                schedule[left] = right;
            }
            return;
        }
        // add to the schedule and check later
        schedule[left] = right;
        auto it = schedule.find(left);

         // check next
        if (schedule.find(left) != prev(schedule.end()))
        {

            for (auto i = it; i != schedule.end(); i++)
            {
                if (i->first < right && i->second <= right)
                {
                    schedule.erase(i);
                    break;
                }
                // if next start time < right and end time > right
                if (i->first < right && i ->second > right)
                {
                    schedule[left] = i->second;
                    break;
                }

                // if next start time < righ and end time <= right
                if (i->first < right && i->second < right)
                {
                    schedule.erase(i);
                }
            }
        }

        // if its not the first one
        if (schedule.find(left) != schedule.begin())
        {
            if (prev(it)->first < left && prev(it)->second >= right)
            {
                schedule.erase(it);
                return;
            }

            printf("prev start %d, end %d\n", prev(it)->first, prev(it)->second);
            // check prev
            if (prev(it)->second > left && prev(it)->second < right)
            {
                printf("should go here\n");
                prev(it)->second = right;
                schedule.erase(it);
            }
        }

    }
    bool queryRange(int left, int right)
    {

        for (auto it = schedule.begin(); it != schedule.end(); it++)
        {
            printf("start:%d,end:%d\n", it->first, it->second);
        }

        // find the start time at left
        if (schedule.find(left) != schedule.end())
        {
            // check if right < end time
            if (right <= schedule[left])
            {
                return true;
            }
            return false;
        }

        // check every key
        for (auto &time : schedule)
        {
            // check if start time < left and end time > right
            if (time.first <= left && time.second >= right)
            {
                return true;
            }
        }

        return false; // replace with your own implementation
    }
    void removeRange(int left, int right)
    {
        // check if there is data at start time
        if (schedule.find(left) != schedule.end())
        {
            auto it = schedule.find(left);

            // if the right > end time
            if (right >= schedule[left])
            {
                // check next one
                // if there is next and right > next start time
                if (next(it) != schedule.end() && right > next(it)->first)
                {
                    schedule[right] = next(it)->second;
                    schedule.erase(next(it));
                }
                // delete the range
                schedule.erase(it);
            }
            else
            {
                schedule[right] = it->second;
                // delete the range
                schedule.erase(it);
            }
            return;
        }

        schedule[left] = right;
        auto it = schedule.find(left);

        // if not the last one
        if (schedule.find(left) != prev(schedule.end()))
        {
            for (auto i = next(it); i != schedule.end(); i++)
            {

                // if next start time < righ and end time <= right
                if (i->first < right && i->second < right)
                {
                    schedule.erase(i);
                    
                }
                if (i->first < right && i->second >= right)
                {
                    schedule[right] = i->second;
                    schedule.erase(i);
                    break;
                }
            }
        }

        // if not the first one
        if (schedule.find(left) != schedule.begin())
        {
            // check prev
            if (prev(it)->second > left && prev(it)->second < right)
            {
                prev(it)->second = left;
                schedule.erase(it);
                return;
            }
            // if prev start time < left and end time > right
            if (prev(it)->second > left && prev(it)->second > right)
            {
                schedule[right] = prev(it)->second;
                prev(it)->second = left;
                schedule.erase((it));
                return;
            }
        }
        schedule.erase(it);
    }
};

void leetcode_range_module()
{

    RangeModule *sol = new RangeModule;
    bool gotIt = false;

    // //------ example 1 -----------
    // addRange [10,20)
    sol->addRange(10, 20);

    // removeRange [14, 16)
    sol->removeRange(14, 16);

    // queryRange [10, 14) => true
    gotIt = sol->queryRange(10, 14);
    printf("(true)%s\n", gotIt ? "True" : "False");

    // queryRange [13, 15) => false
    gotIt = sol->queryRange(13, 15);
    printf("(false)%s\n", gotIt ? "True" : "False");

    // queryRange [16,17) =>true
    gotIt = sol->queryRange(16, 17);
    printf("(true)%s\n", gotIt ? "True" : "False");

    delete sol;
    //-------- example 2 ---------

    sol = new RangeModule;
    sol->addRange(10, 180);
    sol->addRange(150, 200);
    sol->addRange(250, 500);

    // queryRange [50, 100] => true
    gotIt = sol->queryRange(50, 100);
    printf("(true)%s\n", gotIt ? "True" : "False");

    // queryRange [180, 300] => false
    gotIt = sol->queryRange(180, 300);
    printf("(false)%s\n", gotIt ? "True" : "False");

    // // queryRange [600, 1000] => false
    gotIt = sol->queryRange(600, 1000);
    printf("(false)%s\n", gotIt ? "True" : "False");

    sol->removeRange(50, 150);

    // // queryRange [50, 100] => false
    gotIt = sol->queryRange(50, 100);
    printf("(false)%s\n", gotIt ? "True" : "False");

    delete sol;
}

int main()
{
    leetcode_range_module();
    return 0;
}

/*
A Range Module is a module that tracks ranges of numbers.
Design a data structure to track the ranges represented as
half-open intervals and query about them.

A half-open interval [left, right) denotes all the real numbers x where left <= x < right.

Implement the RangeModule class:

RangeModule()
 - Initializes the object of the data structure.
void addRange(int left, int right)
 - Adds the half-open interval [left, right),
   tracking every real number in that interval.
   Adding an interval that partially overlaps with currently tracked numbers
   should add any numbers in the interval [left, right) that are not already tracked.
boolean queryRange(int left, int right)
 - Returns true if every real number in the interval [left, right)
   is currently being tracked, and false otherwise.
void removeRange(int left, int right)
 - Stops tracking every real number currently being tracked in
   the half-open interval [left, right).


Example 1:

Input
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
Output
[null, null, null, true, false, true]

Explanation
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20); //[10, 20)
rangeModule.removeRange(14, 16); //[10, 14), [16, 20)
rangeModule.queryRange(10, 14); // return True,(Every number in [10, 14) is being tracked)
rangeModule.queryRange(13, 15); // return False,(Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
rangeModule.queryRange(16, 17); // return True, (The number 16 in [16, 17) is still being tracked, despite the remove operation)

*/