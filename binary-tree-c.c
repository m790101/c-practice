#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* creatNode(int value);


int main() {
    Node *root = creatNode(3);
    

    Node *node2 = creatNode(9);
    Node *node3 = creatNode(15);

    root->left = node2;
    root->right = node3;


    printf("%d", root->data);
    printf("root left is %p\n", root->left);
    printf("root left is %d\n", root->left->data);
    printf("root right is %p\n", root->right);
    printf("root right is %d\n", root->right->data);
    

    printf("node2 is %p\n", node2);
    printf("node3 is %p\n", node3);

    free(root);
    free(node2);
    free(node3);
    return 0;
}


Node* creatNode(int value){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}