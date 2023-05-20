#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noh {
   char string;
   struct noh* esq;
   struct noh* dir;
} Noh;

Noh* criarNoh(char valor) {
   Noh* novoNoh = (Noh*)malloc(sizeof(Noh));
   novoNoh->string = valor;
   novoNoh->esq = NULL;
   novoNoh->dir = NULL;
   return novoNoh;
}

int procurarIndice(char* str, int inicio, int fim, char valor) {
   for (int i = inicio; i <= fim; i++) {
      if (str[i] == valor) {
         return i;
      }
   }
   return -1;
}

Noh* construirArvore(char* preOrdem, char* inOrdem, int* indice, int inicio, int fim) {
   if (inicio > fim) {
      return NULL;
   }

   Noh* novoNoh = criarNoh(preOrdem[*indice]);
   (*indice)++;

   if (inicio == fim) {
      return novoNoh;
   }

   int indiceInOrdem = procurarIndice(inOrdem, inicio, fim, novoNoh->string);

   novoNoh->esq = construirArvore(preOrdem, inOrdem, indice, inicio, indiceInOrdem - 1);
   novoNoh->dir = construirArvore(preOrdem, inOrdem, indice, indiceInOrdem + 1, fim);

   return novoNoh;
}

void posOrdem(Noh* raiz) {
   if (raiz == NULL) {
      return;
   }

   posOrdem(raiz->esq);
   posOrdem(raiz->dir);
   printf("%c", raiz->string);
}

int main() {
   int C;
   scanf("%d", &C);

   while (C--) {
      int N;
      scanf("%d", &N);

      char preOrdem[53], inOrdem[53];
      scanf("%s %s", preOrdem, inOrdem);

      int indice = 0;
      Noh* raiz = construirArvore(preOrdem, inOrdem, &indice, 0, N - 1);

      posOrdem(raiz);
      printf("\n");

      // Libera a memória alocada pela árvore
      free(raiz);
   }

   return 0;
}