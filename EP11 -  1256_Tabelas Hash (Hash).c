#include <stdio.h>

#include <stdlib.h>



//estrutura interna da tabela

//lista encadeada contendo um dado inteiro (chave) e um ponteiro

struct Node {

    int key;

    struct Node* next;

};



//estrutura externa da tabela

//lista encadeada contendo um dado inteiro (tamanho da tabela) e a lista criada anteriormente

struct HashTable {

    int size;

    struct Node** table;

};



//mapeamento chaves na tabela

int hash_function(int key, int size) {

    return key % size;

}



//criando um novo nó na estrutura interna

// Função que retorna o ponteiro para o novo nó criado do tipo struct Node*

struct Node* create_node(int key) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->key = key;

    newNode->next = NULL;

    return newNode;

}



//função do tipo void de inserção da chave na estrutura externa

void insert_key(struct HashTable* hashTable, int key) {

    int index = hash_function(key, hashTable->size);

    struct Node* newNode = create_node(key);



    if (hashTable->table[index] == NULL) {

        hashTable->table[index] = newNode;

    } else {

        struct Node* current = hashTable->table[index];

        while (current->next != NULL) {

            current = current->next;

        }

        current->next = newNode;

    }

}

//função do tipo void que imprime a estrutura externa

void print_hash_table(struct HashTable* hashTable) {

    for (int i = 0; i < hashTable->size; i++) {

        printf("%d -> ", i);

        struct Node* current = hashTable->table[i];

        while (current != NULL) {

            printf("%d -> ", current->key);

            current = current->next;

        }

        printf("\\\n");

    }

}



int main() {

    int num_cases;

    scanf("%d", &num_cases);



    for (int i = 0; i < num_cases; i++) {

        int size, num_keys;

        scanf("%d %d", &size, &num_keys);



        struct HashTable hashTable;

        hashTable.size = size;

        hashTable.table = (struct Node**)malloc(size * sizeof(struct Node*));



        // Inicializar a tabela hash com ponteiros NULL

        for (int j = 0; j < size; j++) {

            hashTable.table[j] = NULL;

        }



        // Inserir as chaves na tabela hash

        for (int j = 0; j < num_keys; j++) {

            int key;

            scanf("%d", &key);

            insert_key(&hashTable, key);

        }



        // Imprimir a tabela hash

        print_hash_table(&hashTable);

        

        if (i < num_cases - 1) {

            printf("\n");

        }



        // Liberar a memória alocada para a tabela hash

        for (int j = 0; j < size; j++) {

            struct Node* current = hashTable.table[j];

            while (current != NULL) {

                struct Node* temp = current;

                current = current->next;

                free(temp);

            }

        }

        free(hashTable.table);

    }



    return 0;

}

