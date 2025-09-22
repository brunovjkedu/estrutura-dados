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
    if (f == NULL)
    {
        printf("List vazia\n");
        return f;
    }

    temperatura *aux, *aux2;

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
        aux2->next = NULL;
        free(aux);
        return f;
    }
    aux2->next = aux->next;
    free(aux);
    return f;
}

temperatura *inserirEmPosicao(temperatura *f, float t, int pos)
{
    if (f == NULL)
    {
        printf("List vazia\n");
        return f;
    }

    temperatura *p, *aux_ant, *aux_pos;

    p = (temperatura *)malloc(sizeof(temperatura));
    p->temp = t;
    p->next = NULL;

    if (pos == 1)
    {
        p->next = f;
        return p;
    }

    aux_ant = f;
    int i = 1;
    while (aux_ant->next != NULL && i < pos - 1)
    {
        aux_ant = aux_ant->next;
        i++;
    }

    aux_pos = aux_ant->next;

    p->next = aux_pos;
    aux_ant->next = p;

    return f;
}

// temperatura *inserirAntes(temperatura *f, float t, float taux)
// {
//     if (f == NULL)
//     {
//         printf("List vazia\n");
//         return f;
//     }
//     // 2- Antes ou depois de um valor
//     // CUIDADOS:
//     //     - Antes do primeiro
//     //     - Depois do ultimo
// };

// temperatura *inserirDepois(temperatura *f, float t, float taux)
// {
//     if (f == NULL)
//     {
//         printf("List vazia\n");
//         return f;
//     }
// };

int main()
{
    temperatura *first = NULL, *aux;
    float t, taux;
    int op = 1, pos;

    while (op != 0)
    {
        printf("1. Inserir\n2. Consultar\n3. Listar\n4. Excluir\n5. Inserir em posição\n6. Inserir antes\n7. Inserir antes\n0. Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1: // Inserir
            first = insereTemp(first);
            break;
        case 2: // Consultar
            printf("Temperatura: ");
            scanf("%f", &t);
            aux = printTemp(first, t);
            if (aux == NULL)
                printf("Temperatura não encontrada!\n");
            else
                printf("A temperatura está na lista!\n");
            break;
        case 3: // Listar
            printAll(first);
            break;
        case 4: // Excluir
            printf("Temperatura: ");
            scanf("%f", &t);
            first = delTemp(first, t);
            break;
        case 5: // Inserir em posição
            printf("Temperatura: ");
            scanf("%f", &t);
            printf("Posição: ");
            scanf("%d", &pos);
            first = inserirEmPosicao(first, t, pos);
            break;
        // case 6: // Inserir antes
        //     printf("Temperatura: ");
        //     scanf("%f", &t);
        //     printf("Inserir antes: ");
        //     scanf("%f", &taux);
        //     first = inserirAntes(first, t, taux);
        //     break;
        // case 7: // Inserir Depois
        //     printf("Temperatura: ");
        //     scanf("%f", &t);
        //     printf("Inserir depois: ");
        //     scanf("%f", &taux);
        //     first = inserirDepois(first, t, taux);
        //     break;
        }
    }
    freeAll(first);
    return 0;
}