
// g++ -std=c++11 heap-sort.cpp -o heap-sort

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> heapify(std::vector<int> v, int i);
void heapSort(std::vector<int> v, int n, std::vector<int> vSort);

int main()
{
    std::vector<int> v{4, 5, 1, 10, 8, 9};
    std::vector<int> vSort = {};
    int length = v.size();

    heapSort(v, length, vSort);
    return 0;
}

std::vector<int> heapify(std::vector<int> v, int i)
{   
    if(i < 0){
        return v;
    }
    int length = v.size();
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <= length && v[i] < v[left])
    {
        int temp = v[i];
        v[i] = v[left];
        v[left] = temp;

    }
    if (right <= length && v[i] < v[right])
    {
        int temp = v[i];
        v[i] = v[right];
        v[right] = temp;
    }
    i--;
    return heapify(v,i);
}

void heapSort(std::vector<int> v, int n, std::vector<int> vSort)
{
    // if v is a empty vector
    if (n == 0)
    {
        std::cout << "n = 0!" << std::endl;
        for (int i = 0; i < vSort.size(); i++)
        {

            std::cout << vSort[i] << std::endl;
        }
        return;
    }
    int lastParent = (n - 1) / 2;

    // check every parent node
    std::vector<int> result = heapify(v,lastParent);

    // switch the top and the last 
    int temp = result[0];
    result[0] = result[n - 1];
    result[n - 1] = temp;    

    //push the last number to vSort and pop it from the result
    vSort.push_back(result[n-1]);
    result.pop_back();

    // redo it
    for (int i = 0; i < result.size(); i++)
    {

        std::cout<< "result:" << result[i] << std::endl;
    }

    for (int i = 0; i < vSort.size(); i++)
    {

        std::cout << "vSort" << vSort[i] << std::endl;
    }
    n--;
    return heapSort(result,n,vSort);
}
