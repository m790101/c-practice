
// g++ -std=c++11 heap-sort.cpp -o heap-sort

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int> v(4, 5, 1, 10, 8, 9);
     int length = v.size();
    heapSort(v.size);
    return 0;
}

void heapify(std::vector<int> v,int i )
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (v[i] < v[left])
    {
        swap(v[i], v[left]);
    }
    if (v[i] < v[right])
    {
        swap(v[i], v[right]);
    }
}

void heapSort(std::vector<int> v,int n){
    if(v.size() == 0){
        return;
    }
    int lastNodePosition = (n - 1)/2;
    heapify(v, lastNode);

    if((lastNodePosition-1)/2 >= 0){
        int preNode = lastNodePosition/2-1;
        heapSort(v, preNode)
    } else {
        std::vector<int> afterSortV= handleMax(v,sortV);
        heapSort(afterSortV, afterSortV.size());

    }
}






