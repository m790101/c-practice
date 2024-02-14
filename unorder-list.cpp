// g++ -std=c++11 unorder-list.cpp -o unorder-list
#include <iostream>
#include<vector>

void twoSum(std::unordered_map<int, int> arrayMap, std::vector<int> array, int targetNum);

int main()
{
    std::vector<int>  vData = {3,9,2,7,13,1};
    std::unordered_map<int,int> mapData;
    
    int targetNum = 14;


    for(int i = 0;i< vData.size(); i++)
    {
        mapData[vData[i]] = i; 
    }
    twoSum(mapData,vData,targetNum);
    return 0;
}


void twoSum(std::unordered_map<int, int> arrayMap, std::vector<int> array, int targetNum)
{
    for(int i = 0; i < array.size(); i++)
    {
        int secondNum = targetNum - array[i];
        if(arrayMap.count(secondNum) == 1 && array[i] != secondNum)
        {
            int secondValIdx = arrayMap[secondNum];
            printf("these number are %d,%d\n",i,secondValIdx );
            return;
        }
    }

}



   //O(N)
//     int targetSum = 9;
//    for(int i=0; i< vData.size(); i++)
//    {
//         int firstVal = vData[i];
//         int secondVal = targetSum - firstVal;
//         if(hashData.count(secondVal) == 1)
//         {
//             int secondValIdx = hashData[secondVal];
//             printf("%d %d ", i, secondValIdx);
//         }
//    }

