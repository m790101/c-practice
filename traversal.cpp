// g++ -std=c++11 traversal.cpp -o traversal

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

void preOrder(TreeNode *node, std::vector<int> &v);
void inOrder(TreeNode *node, std::vector<int> &v);
void postOrder(TreeNode *node, std::vector<int> &v);

TreeNode *transferTreeInOrder(std::vector<int> v, int start, int end);
TreeNode* transferTreePreOrder(std::vector<int> v, int start, int end);
TreeNode* transferTreePostOrder(std::vector<int> v, int start, int end);

int main()
{

    std::vector<int> v = {1, 3, 7, 13, 43, 9, 61, 4, 11};
    std::vector<int> vPre = {};
    std::vector<int> vIn = {};
    std::vector<int> vPost = {};

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // preOrder(root, vPre);

    // for (int i = 0; i < vPre.size(); i++)
    // {
    //     std::cout << vPre[i] << " ";
    // }

    // std::cout << std::endl;

    // inOrder(root, vIn);

    // for (int i = 0; i < vIn.size(); i++)
    // {
    //     std::cout << vIn[i] << " ";
    // }
    // std::cout << std::endl;

    // postOrder(root, vPost);

    // for (int i = 0; i < vPost.size(); i++)
    // {
    //     std::cout << vPost[i] << " ";
    // }

    // transfer to tree

    TreeNode* rootInOrder = transferTreeInOrder(v, 0, v.size() - 1);
    inOrder(rootInOrder, vIn);

    for (int i = 0; i < vIn.size(); i++)
    {
        std::cout << vIn[i] << " ";
    }
    std::cout << std::endl;


    TreeNode* rootPreOrder =  transferTreePreOrder(v, 0, v.size() - 1);
    preOrder(rootPreOrder, vPre);

    for (int i = 0; i < vPre.size(); i++)
    {
        std::cout << vPre[i] << " ";
    }

    std::cout << std::endl;

    TreeNode* rootPostOrder = transferTreePostOrder(v, 0, v.size() - 1);
    postOrder(rootPostOrder, vPost);

    for (int i = 0; i < vPost.size(); i++)
    {
        std::cout << vPost[i] << " ";
    }

     std::cout << std::endl;

    return 0;
}

void preOrder(TreeNode *node, std::vector<int> &v)
{

    v.push_back(node->value);

    if (node->left)
    {
        preOrder(node->left, v);
    }

    if (node->right)
    {
        preOrder(node->right, v);
    }
}

void inOrder(TreeNode *node, std::vector<int> &v)
{

    if (node->left)
    {
        inOrder(node->left, v);
    }

    v.push_back(node->value);

    if (node->right)
    {
        inOrder(node->right, v);
    }
}

void postOrder(TreeNode *node, std::vector<int> &v)
{

    if (node->left)
    {
        postOrder(node->left, v);
    }

    if (node->right)
    {
        postOrder(node->right, v);
    }

    v.push_back(node->value);
}

TreeNode *transferTreeInOrder(std::vector<int> v, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (end - start) / 2 + start;

    TreeNode *node = new TreeNode(v[mid]);

    node->left = transferTreeInOrder(v, start, mid - 1);
    node->right = transferTreeInOrder(v, mid + 1, end);

    return node;
}


TreeNode* transferTreePreOrder(std::vector<int> v, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    
    int mid = (end - start ) / 2 + start;
    
    int newStart = start + 1;


    TreeNode *node = new TreeNode(v[start]);

    node->left = transferTreePreOrder(v, newStart, mid);
    node->right = transferTreePreOrder(v, mid + 1, end);

    return node;
}


TreeNode* transferTreePostOrder(std::vector<int> v, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }
    
    int mid = (end - start ) / 2 + start;
    
    int newEnd = end - 1;


    TreeNode *node = new TreeNode(v[end]);

    node->left = transferTreePostOrder(v, start, mid - 1);
    node->right = transferTreePostOrder(v, mid, newEnd);

    return node;
}