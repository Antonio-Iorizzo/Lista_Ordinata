#ifndef NODO_H
#define NODO_H

struct nodo {
    int val;
    struct nodo *next;
};
typedef struct nodo Nodo;
typedef struct nodo *NodoPtr;

void stampa(NodoPtr attuale);
void inserisci(NodoPtr *head, int val);
void rimuovi(NodoPtr *head, int val);
void clear(NodoPtr *head);

#endif