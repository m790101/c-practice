// g++ -std=c++11 quick-sort.cpp -o quick-sort

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <random>
#include <string>

void quickSort(std::vector<int>& v, int low, int high);

int partition(std::vector<int>& v, int low, int high);

int main()
{
    std::vector<int> foo = {1, 5, 3, 7, 9};
    quickSort(foo,0,foo.size()-1);
}


void quickSort(std::vector<int>& v, int low, int high)
{
    if(low == high) {
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i] << std::endl;
        }
        return;
    }
    int p = partition(v, low, high);
    quickSort(v, low, p - 1);
    quickSort(v, p + 1, high);
}


int partition(std::vector<int>& v, int low, int high)
{
    int k = low;
    for (int i = low; i < high - 1; i++)
    {
        if (v[high] >= v[i])
        {
            if (i != k)
            {
                // swap
                int temp = v[i];
                v[i] = v[k];
                v[k] = temp;
            }
            k++;
        }
    }
    //swap
    int temp = v[high];
    v[high] = v[k];
    v[k] = temp;

    return k;
}

