// g++ -std=c++11  maximal_rectangle.cpp -o maximal_rectangle

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

class CSolMaxRectangle
{
public:
    int maximalRectangle(std::vector<vector<char>> &matrix)
    {
        // there are only two ways can go -> go right or down
        // go from every point from  matrix[0][0]
        // check down
        // int xLength = goDown(0, 0, matrix, 0);
        int max = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
               int xLength = goRight(i, j, matrix, 0);
               printf("xLength = %d, \n", xLength);

               // check if this length can go down
               for(int k = 0; k < matrix.size(); k++)
               {
                   //check
               }
            }
        }
        return max;
    }
    int goDown(int x, int y, vector<vector<char>> &matrix, int times)
    {
        int timeSave = times;
        // printf("times = %d\n", times);
        // printf("x = %d, y = %d\n", x, y);
        // base case
        if (x == matrix.size() - 1)
        {
            // printf("x = matrix size -1\n");
            if (matrix[x][y] == 1)
            {
                timeSave++;
            }
            return timeSave;
        }
        if (matrix[x][y] == 0)
        {
            // printf("x is none\n");
            return timeSave;
        }
        if (matrix[x][y] == 1)
        {
            // printf("go here\n");
            timeSave++;
            return goDown(x + 1, y, matrix, timeSave);
        }
    }
    int goRight(int x, int y, vector<vector<char>> &matrix, int times)
    {
        int timeSave = times;
        // printf("times = %d\n", times);
        // printf("x = %d, y = %d\n", x, y);
        // base case
        if (y == matrix[x].size() - 1)
        {
            // printf("y = matrix size -1\n");
            if (matrix[x][y] == 1)
            {
                timeSave++;
            }
            return timeSave;
        }
        if (matrix[x][y] == 0)
        {
            // printf("y is none\n");
            return timeSave;
        }
        if (matrix[x][y] == 1)
        {
            // printf("go here\n");
            timeSave++;
            return goRight(x, y + 1, matrix, timeSave);
        }
    }
};

void leetcode_maximal_rectangle()
{
    /*
    Given a rows x cols binary matrix filled with 0's and 1's,
    find the largest rectangle containing only 1's and return its area.

    Example 1:
      1 0 1 0 0
      1 0 1 1 1
      1 1 1 1 1
      1 0 0 1 0

    Input: matrix = [["1","0","1","0","0"]
                    ,["1","0","1","1","1"]
                    ,["1","1","1","1","1"]
                    ,["1","0","0","1","0"]]
    Output: 6


    Example 2:
    Input: matrix = [["0"]]
    Output: 0

    Example 3:
    Input: matrix = [["1"]]
    Output: 1

    Example 4:
    0 1 1 0
    1 1 1 1
    1 1 1 1
    1 1 0 0
    Output :
    8
    */
    vector<vector<char>> matrix;

    matrix.push_back(vector<char>{0, 1, 1, 0});
    matrix.push_back(vector<char>{1, 1, 1, 1});
    matrix.push_back(vector<char>{1, 1, 1, 1});
    matrix.push_back(vector<char>{1, 1, 0, 0});

    CSolMaxRectangle *sol = new CSolMaxRectangle;
    int area = sol->maximalRectangle(matrix);

    printf("maximal area = %d (8)\n", area);

    delete sol;
}

int main()
{
    leetcode_maximal_rectangle();
    return 0;
}
