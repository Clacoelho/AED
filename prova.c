#include <stdio.h>
#include <stdlib.h>

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


int main() {
    
    Node* root = NULL;
    int C;
    scanf("%d", &C);
    while (C --) {
      int N;
      scanf("%d", &N);
      int num;
      for (int i = 0; i < N; i++){
        scanf(" %c", &num);
        root = insertNode(root, num);
      }
    int d = 1;
    
    printf("Case %d:\n", C); 
    
   // printf("Case %d:\n", C+1);
    printf("In..:");
    inorderTraversal(root, &d);
    printf("\n");
    printf("Pre.:");
    preorderTraversal(root, &d);
    printf("\n");
    printf("Post:");
    postorderTraversal(root, &d);
    printf("\n");
     
        
    
    }
   
    
    

    // Libera a memória alocada pela árvore
    // Implemente a função para liberar a memória se necessário

    return 0;
}
