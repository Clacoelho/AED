#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char letter;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->letter = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, char value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->letter) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->letter) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void inorderTraversal(Node* root, int* d) {
    if (root != NULL) {
        inorderTraversal(root->left, d);
        if (!*d){
            printf(" ");
        }
        printf("%c", root->letter);
        *d = 0;
        inorderTraversal(root->right, d);
    }
    
}

void preorderTraversal(Node* root, int* d) {
    if (root != NULL) {
        if (!*d ){
            printf(" ");
        }
        printf("%c", root->letter);
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
        printf("%c", root->letter);
        *d = 0;
    }
}

int searchNode(Node* root, char value) {
    if (root == NULL) {
        return 0;
    }
    if (value < root->letter) {
        return searchNode(root->left, value);
    }
    else if (value > root->letter) {
        return searchNode(root->right, value);
    }
    else {
        return 1;
    }
}

int main() {
    Node* root = NULL;
    char command[10];

    while (scanf("%s", command) != EOF) {

        if (strcmp(command, "I") == 0) {
            char letter;
            scanf(" %c", &letter);
            root = insertNode(root, letter);
        }
        else if (strcmp(command, "INFIXA") == 0) {
            int d = 1;
            inorderTraversal(root, &d);
            printf("\n");
        }
        else if (strcmp(command, "PREFIXA") == 0) {
            int d = 1;
            preorderTraversal(root, &d);
            printf("\n");
        }
        else if (strcmp(command, "POSFIXA") == 0) {
            int d = 1;
            postorderTraversal(root, &d);
            printf("\n");
        }
        else if (strcmp(command, "P") == 0) {
            char searchLetter;
            scanf(" %c", &searchLetter);
            if (searchNode(root, searchLetter)) {
                printf("%c existe\n", searchLetter);
            }
            else {
                printf("%c nao existe\n", searchLetter);
            }
        }
    }

    // Libera a memória alocada pela árvore
    // Implemente a função para liberar a memória se necessário

    return 0;
}
