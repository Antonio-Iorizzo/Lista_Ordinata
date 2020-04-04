#include <stdio.h>
#include "nodo.h"

int main()
{
    NodoPtr head=NULL;
    
    stampa(head);

    inserisci(&head, 2);
    stampa(head);

    inserisci(&head, 4);
    stampa(head);

    inserisci(&head, 3);
    stampa(head);

    inserisci(&head, 7);
    stampa(head);

    inserisci(&head, 1);
    stampa(head);

    rimuovi(&head, 2);
    stampa(head);

    rimuovi(&head, 7);
    stampa(head);

    
    rimuovi(&head, 17); // elemento non presente in lista

    rimuovi(&head, 1);
    stampa(head);

    clear(&head);
    
    return 0;
}