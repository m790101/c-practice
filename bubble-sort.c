#include<stdio.h>
#include <stdbool.h>


void core_bubble_sort(int *in, int num);

int main(){

    int array[8] = {3, 4, 5, 6, 9, 7, 13, 11};

    core_bubble_sort(array,8);

    printf("Sorted array: \n");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}


void core_bubble_sort(int *in, int num) //HW1 : finish implementation
{
    //computational complexity : O(n^2)

    // step 1: architecture
    // step 2: implementation
    // step 3: verification
    int i;
    int j;
    int temp;
    bool isSorted;
    int times = 0;

    // for first loop, every time only one number is sorted, 
    //ex: first time 9 will be the last num in array, second time 7, 9 will be last two nums in array.
    for (i = 0; i < num - 1; i++)
    {   isSorted = false;
        times++;
        for (j = 0; j < num - i - 1; j++)
        {
            // when i= 0, j = 0, in[0]=4, in[1]=3
            // in[0]>in[1], so swap
            // {3, 4, 5, 6, 9, 7, 0, 2} -> after first time
            // when i = 0,  j = 1, in[1]=4, in[1]=3
            if (in[j] > in[j + 1])
            {
                temp = in[j];
                in[j] = in[j + 1];
                in[j + 1] = temp;
                isSorted = true;
            }
        }
        if(!isSorted){
            break;
        }
    }
    printf("times: %d\n", times);
}