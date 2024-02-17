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