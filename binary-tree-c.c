#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


int main() {

    Node *root = NULL;
    root = (Node *)malloc(sizeof(Node));
    root->data = 2;
    root->left = NULL;
    root->right = NULL;
    printf("%d", root->data);

    return 0;
}