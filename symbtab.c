#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node
{
    char *nom;
    int type;
    int taille;
    char isConst[4];
    Node *next;
};

typedef struct TS TS;
struct TS
{
    Node *head;
};

TS *list;

Node *creatNode(char *entite)
{

    Node *new = malloc(sizeof(*new));

    new->taille = -1;
    new->type = -1;
    new->nom = malloc(strlen(entite) * sizeof(char));
    strcpy(new->nom, entite);
    strcpy(new->isConst, "non");

    new->next = NULL;

    return new;
}

Node *recherche(char *entite)
{

    TS temp = *list;

    while (temp.head != NULL)
    {

        if (strcmp(temp.head->nom, entite) == 0)
        {
            return temp.head;
        }
        temp.head = temp.head->next;
    }
    return NULL;
}

void inserer(char *entite)
{

    Node *new = creatNode(entite);
    // printf("%s : le idf \n",new->nom);
    if (new == NULL || list == NULL)
        exit(EXIT_FAILURE);
    if (recherche(entite) == NULL)
    {
        new->next = list->head;
        list->head = new;
    } /*else{
        printf("IDF EXIST ALREADY ! \n");
    }*/
}

char *comparateurReverse(char cmp[])
{

    if (strcmp(cmp, "<") == 0)
    {
        return "BGE";
    }
    if (strcmp(cmp, "==") == 0)
    {
        return "BNE";
    }
    if (strcmp(cmp, "!=") == 0)
    {
        return "BE";
    }
    if (strcmp(cmp, "<=") == 0)
    {
        return "BG";
    }
    if (strcmp(cmp, ">=") == 0)
    {
        return "BL";
    }
    if (strcmp(cmp, ">") == 0)
    {
        return "BLE";
    }
    strcpy(cmp, "");
    return "";
}

char *comparateur(char cmp[])
{

    if (strcmp(cmp, ">=") == 0)
    {
        return "BGE";
    }
    if (strcmp(cmp, "!=") == 0)
    {
        return "BNE";
    }
    if (strcmp(cmp, "==") == 0)
    {
        return "BE";
    }
    if (strcmp(cmp, ">") == 0)
    {
        return "BG";
    }
    if (strcmp(cmp, "<") == 0)
    {
        return "BL";
    }
    if (strcmp(cmp, "<=") == 0)
    {
        return "BLE";
    }

    strcpy(cmp, "");
    return "";
}

void setConstant(char *entite, char *str)
{
    Node *new = recherche(entite);

    if (new != NULL)
    {
        strcpy(new->isConst, str);
    }
}

void insererType(char *entite, int type)
{

    Node *temp = recherche(entite);
    if (temp != NULL)
    {
        temp->type = type;
    }
    //return table;
}

void setSize(char *entite, int taille)
{
    Node *temp = recherche(entite);
    if (temp != NULL)
    {
        temp->taille = taille;
    }
}

////////////////////    Les routines sémantiques  /////////////

// 0 : double declaration
// 1 : non double declaration

int DoubleDeclaration(char *entite)
{

    Node *t = recherche(entite);

    if (t != NULL)
    {
        // j'ai pas trouvée le type associé ‡ l'entitÈ dans le
        // table de symbole et donc elle est pas encore dÈclarÈe
        if (t->type == -1)
            return 1;
    }
    // le type de l'entitÈ existe dej‡ dans
    // la TS et donc c'est une double dÈclaration
    return 0;
}

//verifier la non declaration :
int NotDeclared(char *entite)
{

    Node *temp = recherche(entite);
    if (temp == NULL)
        printf("%s non declaree\n", entite);

    if ((temp != NULL))
    { //||(temp->nom == NULL)
        if (temp->type != -1)
        { //donc var est declaree
            printf("%s declaree type %d\n", entite, temp->type);
            return 0;
        }
    }
    return 1;
    //var non declaree
}

//verifier la valeur d 'un entier
int valid_int(int cst)
{
    if (cst > 32720 || cst < -32720)
        return 0;

    return 1;
}

//verifier la longeur d'un idf :
int valid_idf(char *idf)
{
    if (strlen(idf) > 12)
        return 0;

    return 1;
}

void afficherTS()
{
    printf("\n/***************Table des symboles ********************/\n");
    printf("___________________________________________________________\n");
    printf("\t|  Nom Entite  | Type Entite  |  Taille    |  Constant   \n");
    printf("___________________________________________________________\n");

    TS *temp = list;

    if (temp == NULL || temp->head == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (temp->head != NULL)
    {
        printf("\t|%12s  |%12d  |%8d    |%7s    \n", temp->head->nom, temp->head->type, temp->head->taille, temp->head->isConst);
        temp->head = temp->head->next;
    }
}

void init()
{
    list = malloc(sizeof(TS));
    list->head = NULL;
}

void erro_parentheseSemantic(int lineno, char *msg)
{
    printf("erro_parenthese at : %d , %s\n", lineno, msg);
}

void missingLibrary(int lineno, char *libarary_name)
{
    printf("MISSING LIBRARY : %s, AT LINE : %d\n", libarary_name, lineno);
}

int affect_compatibl(int typeOP1, int typeOP2)
{
    /*   int  0 : int 0 compatible return 1
         float  1 : 0 | 1 compatible //   //
         string 2 : 2     compatible //  //
      */
    if (typeOP1 == typeOP2)
        return 1;

    if ((typeOP1 == 1) && (typeOP2 == 0))
        return 1;
    if ((typeOP1 == -1) || (typeOP2 == -1))
        return 1;

    return 0;
}

int getType(char *entite)
{

    Node *temp = recherche(entite);
    if (temp != NULL)
    {
        return temp->type;
    }
    return -1;
}

int getSize(char *entite)
{
    Node *temp = recherche(entite);
    if (temp != NULL)
        return temp->taille;
    return -1;
}

int divByZero(char operator, float fv)
{

    if (operator== '/' && fv == 0)
        return 1;
    return 0;
}

void initializeEntier(int *OP1, int *OP2)
{
    (*OP1) = -1;
    (*OP2) = -1;
}