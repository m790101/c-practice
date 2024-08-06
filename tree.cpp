// g++ -std=c++11 tree.cpp -o tree

#include <iostream>
#include <vector>

struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

void printTree(TreeNode *node);

int main()
{

    std::vector<int> v = {1, 3, 7, 13, 43, 9, 61, 4, 11};
    // i is depth from root(0) to 2i+2 < v.size()
    // every time move current to node that present as root
    // add left and right to the node
    // change current to next node
    int i = 0;
    std::vector<TreeNode *> vQue = {};
    // initial first tree
    TreeNode *root = new TreeNode(v[0]);
    vQue.push_back(root);

    while (2 * i + 2 <= v.size())
    {
        TreeNode *current = vQue.front();
        vQue.erase(vQue.begin()); //??

        if (2 * i + 1 < v.size())
        {
            current->left = new TreeNode(v[2 * i + 1]);
            vQue.push_back(current->left);
        }
        if (2 * i + 2 < v.size())
        {
            current->right = new TreeNode(v[2 * i + 2]);
            vQue.push_back(current->right);
            i++;
        }
    }

    printTree(root);

    return 0;
}

void printTree(TreeNode *node)
{
    if (node->value == 0)
    {
        return;
    }

    std::cout << node->value << std::endl;

    if (node->left)
    {
        printTree(node->left);
    }
    if (node->right)
    {
        printTree(node->right);
    }
}










/*
Given an integer n, 
return all the structurally unique BST's (binary search trees), 
which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

Example 1:


Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
Example 2:

Input: n = 1
Output: [[1]]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
                unordered_map<int,vector<TreeNode*>> map;
        vector<TreeNode*> res;
        map[1] = {new TreeNode(1)};
        map[0] = {nullptr};
        for(int i = 1; i <= n; ++i)
        {
            vector<TreeNode*> nodeVec;
            for(int j  = 1; j < i; j++)
            {
                
                vector<TreeNode*> left = map[j];
                vector<TreeNode*> right = map[i-j-1];
                int leftIndex = 0;
                int rightIndex = 0;
                queue<TreeNode*> q;
                for(auto& node:left)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = node;
                    q.push(root);
                }
                while(!q.empty())
                {
                    TreeNode* leftSide = q.front();
                    for(auto& node:right)
                    {
                        TreeNode* ptr = leftSide;
                        ptr -> right = node;
                        res.push_back(ptr);
                        nodeVec.push_back(ptr);
                    }
                    q.pop();
                }
 
            }
                if(i > 1)
                {
                    map[i] = nodeVec;
                }
        }
        return res;
    }
};