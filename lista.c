#include <stdio.h>
#include <stdlib.h>
struct ttemp
{
    float temp;
    struct ttemp *next;
};
typedef struct ttemp temperatura;

temperatura *insereTemp(temperatura *f)
{
    temperatura *p;
    p = (temperatura *)malloc(sizeof(temperatura));
    printf("Temperatura: ");
    scanf("%f", &p->temp);
    p->next = NULL;

    if (f == NULL)
        return p;
    temperatura *aux;
    for (aux = f; aux->next != NULL; aux = aux->next)
        ;
    aux->next = p;
    return f;
}

temperatura *printTemp(temperatura *f, float t)
{
    temperatura *aux;
    for (aux = f; aux != NULL; aux = aux->next)
        if (aux->temp == t)
            return aux;
    return aux;
}

void printAll(temperatura *f)
{
    temperatura *aux;
    for (aux = f; aux != NULL; aux = aux->next)
        printf("Temperatura: %.2f\n", aux->temp);
}

void freeAll(temperatura *f)
{
    temperatura *aux1, *aux2;
    aux1 = f;
    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->next;
        free(aux2);
    }
}

temperatura *delTemp(temperatura *f, float t)
{
    temperatura *aux, *aux2;

    if (f = NULL)
    {
        printf("List vazia");
        return f;
    }

    if (f->temp == t)
    {
        aux = f;
        f = f->next;
        free(aux);
        return f;
    }

    aux = f;

    while (aux != NULL)
    {
        if (aux->temp == t)
            break;
        aux2 = aux;
        aux = aux->next;
    }

    if (aux == NULL)
    {
        printf("Temperatura '%f' não encontrada!\n", t);
        return f;
    }

    if (aux->next == NULL)
    {
        aux2->next == NULL;
        free(aux);
        return f;
    }
    aux2->next=aux->next;
    free(aux);
    return f;
}

int main()
{
    temperatura *first = NULL, *aux;
    float t;
    int op = 1;

    while (op != 0)
    {
        printf("1. Inserir\n2. Consultar\n3. Listar\n4. Excluir\n0. Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            first = insereTemp(first);
            break;
        case 2:
            printf("Temperatura: ");
            scanf("%f", &t);
            aux = printTemp(first, t);
            if (aux == NULL)
                printf("Temperatura não encontrada!\n");
            else
                printf("A temperatura está na lista!\n");
            break;
        case 3:
            printAll(first);
            break;
        case 4:
            printf("Temperatura: ");
            scanf("%f", &t);
            first = delTemp(first, t);
        }
    }
    freeAll(first);
    return 0;
}