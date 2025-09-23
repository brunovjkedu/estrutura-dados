#include <stdio.h>
#include <stdlib.h>
struct tidade
{
    int idade;
    struct tidade *next;
};
typedef struct tidade idade;

idade *getUnion(idade *l1, idade *l2){
    idade *p, *first = l1, *aux,*aux2, *aux3, *l3;
  
    for (aux = l1; aux != NULL; aux = aux->next){
        p=(idade *)malloc(sizeof(idade));
        p->idade = aux2->idade;
        p->next=first;

        if(first==NULL){first=p; aux=p;}
        else {aux->next=p; aux=p;}
    }

    for (aux2 = l2; aux2 != NULL; aux2 = aux2->next){
        for (aux = l1; aux != NULL; aux = aux->next){
            if(aux2->idade != aux->idade){
                p=(idade *)malloc(sizeof(idade));
                p->idade = aux2->idade;
                p->next=first;

                // Adicionar p no comeco da list first

            }
        }
    } 


    return first;
    
}

int main()
{
    idade vector[3];

    return 0;
}