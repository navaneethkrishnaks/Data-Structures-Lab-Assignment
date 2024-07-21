#include <stdio.h>
#include <stdlib.h>

// Node structure to define the structure of the node
struct node {
    int data;
    struct node *right_child;
    struct node *left_child;
};

// Function to create a new node
struct node* new_node(int x) {
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left_child = NULL;
    temp->right_child = NULL;
    return temp;
}

// Function to insert a new node in the BST
struct node* insert(struct node * root, int x) {
    if (root == NULL)
        return new_node(x);
    else if (x > root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child, x);
    return root;
}

// Function to print the BST in a structured format
void printTree(struct node *root, int space) {
    int COUNT = 10;
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    printTree(root->right_child, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    printTree(root->left_child, space);
}

int main() {
    struct node *root = NULL;

    // Insertion of nodes to form the tree with the given data elements
    int elements[] = {29, 5, 30, 1, 15, 25, 40, 9, 45, 7, 12, 42};
    int n = sizeof(elements) / sizeof(elements[0]);
    for (int i = 0; i < n; i++) {
        root = insert(root, elements[i]);
    }

    // Printing the structured tree
    printf("Structured tree output:\n");
    printTree(root, 0);

    return 0;
}
