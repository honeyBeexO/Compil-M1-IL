#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaration d'une structure de donn�e pour la table de symbole

typedef struct entite
{
    char nom[20];
    char code[20];
    char nature[20]; //variable ou cst
    char type[20];
    int taille;
    struct entite *svt;
} entite;

typedef struct tableH
{
    entite *tete;
    entite *queue;
} tableH;

tableH TableHachage[673];

extern int hachage(char *chaine)
{
    unsigned int i = 0, n = strlen(chaine), u = 0, j = 0, k = 1, h = 0;
    for (i = 0; i < n; i++)
    {
        u = n - i - 1;
        for (j = 0; j < u; j++)
            k *= 26;
        h += ((int)chaine[i]) * k;
        k = 1;
    }
    h = h % 673;
    return h;
}

extern int rechercher(char *chaine)
{
    int existe = 0;
    int position = 0;

    position = hachage(chaine);
    entite *ptr = TableHachage[position].tete;
    while ((ptr != NULL) && (existe == 0))
    {
        if (strcmp(ptr->nom, chaine) == 0)
        {
            existe = 1;
        }
        else
            ptr = ptr->svt;
    }
    if (existe == 1)
        return position;
    else
        return -1;
}

void inserer(char *nom_entite, char *code_entite, int position)
{
    entite *ptr = NULL;

    if (rechercher(nom_entite) == -1)
    {

        ptr = (entite *)malloc(sizeof(entite));
        strcpy(ptr->nom, nom_entite);
        strcpy(ptr->code, code_entite);
        strcpy(ptr->type, " ");
        strcpy(ptr->nature, " ");
        ptr->taille = 0;
        ptr->svt = NULL;

        if (TableHachage[position].tete == NULL) //c'est le premier element � ins�rer
        {
            TableHachage[position].tete = ptr;
            TableHachage[position].queue = ptr;
        }
        else
        {
            (TableHachage[position].queue->svt) = ptr;
            TableHachage[position].queue = ptr;
        }
    }
}

void typeDeIdf(char *out, char *idf)
{

    int p = rechercher(idf);
    if (p != -1)
    {
        entite *ptr = TableHachage[p].tete;

        while ((ptr != NULL))
        {
            if (strcmp(ptr->nom, idf) == 0)
            {
                strcpy(out, ptr->type);
                return;
            }
            else
                ptr = ptr->svt;
        }
    }
    else
        strcpy(out, " ");
}

void routineModifCst(char *idf)
{
    int p = rechercher(idf);
    if (p != -1)
    {
        entite *ptr = TableHachage[p].tete;

        while ((ptr != NULL))
        {
            if (strcmp(ptr->nom, idf) == 0)
            {
                if (strcmp(ptr->nature, "Constante") == 0)

                    printf("la valeur de %d : ne peut pas etre modifi� c'est une constante ", idf);
            }
            else
                ptr = ptr->svt;
        }
    }
    else
        return;
}

extern int doubleDeclaration(char entites[])
{
    int posEntite = rechercher(entites); //posEntite contiendras -1 si elle ne figure pas dans la liste chain� de la position
    entite *ptr = NULL;
    if (posEntite != -1)
    {
        ptr = TableHachage[posEntite].tete;
        while (ptr != NULL)
        {
            if (strcmp(ptr->nom, entites) == 0)
            {
                if (strcmp(ptr->type, " ") == 0)
                    return 0; // j'ai pas trouv� le type associ� � l'entit� dans le table de symbole et donc elle est pas encore d�clar�e
                else
                    return 1; // le type de l'entit� existe dej� dans la TS et donc c'est une double d�claration
            }
            else
                ptr = ptr->svt;
        }
    }
    return -1;
}

// fonction qui change le type d'une etit� une fois il va �tre reconu dans la syntaxe

extern void insererType(char entites[], char typ[], char nature[], int taille)
{
    entite *ptr = NULL;
    int b = 0;

    int posEntite = hachage(entites);

    ptr = TableHachage[posEntite].tete;

    while ((ptr != NULL) && (b == 0))
    {
        if (strcmp(ptr->nom, entites) == 0)
        {
            strcpy(ptr->type, typ);
            strcpy(ptr->nature, nature);
            ptr->taille = taille;
            b = 1;
        }
        else
            ptr = ptr->svt;
    }
}
extern void supprimerTS(char *nom)
{
    int hach = hachage(nom);
    entite *ptr = TableHachage[hach].tete;
    entite *prec = NULL;

    int trouve = 0;
    while ((ptr != NULL) && (trouve == 0))
    {
        if (strcmp(ptr->nom, nom) == 0)
        {
            if (prec != NULL)
            {
                if (ptr->svt != NULL)
                {
                    prec->svt = ptr->svt;
                }
                else
                {
                    TableHachage[hach].queue = prec;
                }
            }
            else
            {
                TableHachage[hach].tete = ptr->svt;
            }
            ptr->svt = NULL;
            free(ptr);
            prec = NULL;
            trouve = 1;
        }
        else
        {
            prec = ptr;
            ptr = ptr->svt;
        }
    }
}

extern void afficher()
{
    printf("  \n");
    printf("  \n");
    printf("\t ********************************** Table des symboles **************************************** /\n");
    printf("\t ______________________________________________________________________________________________  \n");
    printf("\t|      NomEntite      |   CodeEntite        |      NatureEntite     |     TypeEntite   | taille  |\n");
    printf("\t ________________________________________________________________________________________________\n");
    int i = 0;
    for (i = 0; i < 673; i++)
    {
        entite *ptr = TableHachage[i].tete;
        while (ptr != NULL)
        {
            printf("\t| %20s | %20s | %20s | %15s | %5d   |\n", ptr->nom, ptr->code, ptr->nature, ptr->type, ptr->taille);

            ptr = ptr->svt;
        }
    }
}

// int main()
// {
//     inserer("Lynda", "IDF", hachage("Lynda"));
//     insererType("Lynda", "String", "Variable", strlen("Lynda") * sizeof(char));
//     afficher();
//     return 0;
// }