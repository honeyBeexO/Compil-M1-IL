#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    char *inf;
    struct element *suivant;
} cellule;

typedef cellule *Pile;

int error = 0;
Pile p;

Pile initpile() { return NULL; }

int pilevide(Pile p)
{
    if (p == NULL)
        return 1;

    else
        return 0;
}

char *sommetpile(Pile p)
{
    int a, b;
    if (!pilevide(p))
        return (p->inf);
    return NULL;
}

void empiler(Pile *p, char x[])
{

    Pile nouv;

    nouv = (cellule *)malloc(sizeof(cellule));

    nouv->inf = malloc(strlen(x) * sizeof(char));
    strcpy(nouv->inf, x);
    nouv->suivant = *p;

    *p = nouv;
}

char *depiler(Pile *p)
{

    Pile temp;
    temp = *p;
    char *x = "";
    if (!pilevide(temp))
    {
        x = (*p)->inf;
        //printf("pile : info a depiler %s\n",x);
        *p = (*p)->suivant;

        free(temp);
        return x;
    }
    return "";
}

void initializerVar(char **str1, char **str2)
{
    *(str1) = "";
    *(str2) = "";
}

int taillePile(Pile *p)
{
    Pile temp = *p;
    int taille = 0;
    while (!pilevide(temp))
    {
        taille++;
        temp = temp->suivant;
    }
    return taille;
}