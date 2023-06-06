#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return root;
}
/*
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->value);
    }
}*/

void inorderTraversal(Node* root, int* d) {
    if (root != NULL) {
        inorderTraversal(root->left, d);
        if (!*d){
            printf(" ");
        }
        printf("%d", root->value);
        *d = 0;
        inorderTraversal(root->right, d);
    }
    
}

void preorderTraversal(Node* root, int* d) {
    if (root != NULL) {
        if (!*d){
            printf(" ");
        }
        printf("%d", root->value);
        *d = 0;
        preorderTraversal(root->left, d);
        preorderTraversal(root->right, d);
    }
}

void postorderTraversal(Node* root, int* d) {
    if (root != NULL) {
        postorderTraversal(root->left, d);
        postorderTraversal(root->right, d);
        if (!*d){
            printf(" ");
        }
        printf("%d", root->value);
        *d = 0;
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int C, d=1;
    scanf("%d", &C);

    for (int i = 1; i <= C; i++) {
        int N;
        scanf("%d", &N);
        
        Node* root = NULL;
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);
            root = insertNode(root, num);
        }
        
        printf("Case %d:\n", i);
        printf("Pre.: ");
        preorderTraversal(root, &d);
        d=1;

        printf("\n");
        printf("In..: ");
        inorderTraversal(root, &d);
        d=1;

        printf("\n");
        printf("Post: ");
        postorderTraversal(root, &d);
        d=1;

        if(i<C+1){
            printf("\n\n");
        } else {
            printf("\n");
        }
        freeTree(root);
    }

    return 0;
}
