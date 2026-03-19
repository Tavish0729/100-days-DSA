#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    printf("Height of tree: %d\n", findHeight(root));
    
    struct Node* root2 = createNode(10);
    printf("Height of single node tree: %d\n", findHeight(root2));
    
    struct Node* root3 = NULL;
    printf("Height of empty tree: %d\n", findHeight(root3));
    
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
    free(root2);
    
    return 0;
}