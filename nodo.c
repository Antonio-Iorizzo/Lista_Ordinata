#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

void stampa(NodoPtr attuale)
{
    while(attuale!=NULL){
        printf("%d\t", attuale->val);
        attuale=attuale->next;
    }
    printf("NULL\n");
}

void inserisci(NodoPtr *head, int val)
{
    NodoPtr attuale=*head;
    NodoPtr prev=NULL;

    NodoPtr temp=malloc(sizeof(Nodo));
    temp->val=val;
    temp->next=NULL;

    //ricerca dell'ultimo nodo con valore minore di quello da inserire
    while(attuale!=NULL && attuale->val<val){
        prev=attuale;
        attuale=attuale->next;
    }

    if(prev==NULL){
        //inserimento in testa
        temp->next=*head;
        *head=temp;
    }else{
        //inserimento dopo prev
        prev->next=temp;
        temp->next=attuale;
    }
}

void rimuovi(NodoPtr *head, int val)
{
    NodoPtr attuale=*head;
    NodoPtr prev=NULL;
    NodoPtr temp=NULL;

    //ricerca dell'ultimo nodo con valore minore di quello da rimuovere 
    while(attuale!=NULL && attuale->val<val){
        prev=attuale;
        attuale=attuale->next;
    }

    //se l'elemento non e' stato trovato 
    if(attuale==NULL){
        printf("Eelemento %d non trovato, non faccio nulla\n", val);
        return;
    }

    printf("Elemento %d trovato, lo elimino\n", val);

    //se l'elemento da rimuovere e' il primo 
    if(prev==NULL){
        printf("L'elemento da eliminare e' in testa\n");
       
        temp=*head;          
        *head=(*head)->next;  
        free(temp);             
        return;
    }

    //L'elemento da eliminare e' prev->next 
    printf("L'elemento da eliminare non e' in testa\n");
    temp=prev->next;
    prev->next=temp->next;
    free(temp);
}

void clear(NodoPtr *head)
{
    NodoPtr temp;

    while(*head!=NULL){
        temp=*head;    
        *head=(*head)->next;
        
        printf("Svuotamento del nodo con valore %d\n", temp->val);
        free(temp);
    }
}