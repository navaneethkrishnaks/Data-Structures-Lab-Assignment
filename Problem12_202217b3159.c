#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
        Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

void deletDeepest(Node* root, Node* d_node) {
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
        Node* temp = queue[front++];

        if (temp == d_node) {
            temp = NULL;
            free(d_node);
            return;
        }

        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = temp->right;
            }
        }

        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                free(d_node);
                return;
            } else {
                queue[rear++] = temp->left;
            }
        }
    }
}

Node* deletion(Node* root, int key) {
    if (!root) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            return NULL;
        } else {
            return root;
        }
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    Node* temp;
    Node* key_node = NULL;

    while (front != rear) {
        temp = queue[front++];

        if (temp->data == key) {
            key_node = temp;
        }

        if (temp->left) {
            queue[rear++] = temp->left;
        }

        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }

    if (key_node != NULL) {
        int x = temp->data;
        key_node->data = x;
        deletDeepest(root, temp);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (!root) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (!root) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void levelorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front != rear) {
        Node* temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left) {
            queue[rear++] = temp->left;
        }

        if (temp->right) {
            queue[rear++] = temp->right;
        }
    }
}

int main() {
    Node* root = NULL;

    // Insertion of nodes in the desired order
    root = insert(root, 11);
    root->left = newNode(12);
    root->right = newNode(13);
    root->left->left = newNode(14);
    root->left->right = newNode(15);
    root->left->left->left = newNode(16);
    root->left->left->right = newNode(17);

    printf("Output Binary Tree:\n");
    printf("               11\n");
    printf("           /        \\\n");
    printf("         12          13\n");
    printf("       /   \\         \n");
    printf("     14     15    \n");
    printf("    /  \\   \n");
    printf("   16  17 \n");

    printf("\nPreorder traversal: ");
    preorderTraversal(root);

    printf("\nInorder traversal: ");
    inorderTraversal(root);

    printf("\nPostorder traversal: ");
    postorderTraversal(root);

    printf("\nLevel order traversal: ");
    levelorderTraversal(root);

    printf("\nInorder traversal after deletion: ");
    root = deletion(root, 20);
    inorderTraversal(root);

    return 0;
}
