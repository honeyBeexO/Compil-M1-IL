extern void supprimerTS(char *nom);
extern int hachage(char *chaine);
typedef struct pile
{
    char nom[20];
    struct pile *svt;
} pile;

typedef struct idfTemp
{
    char nom[20];
    int position;
    struct idfTemp *svt;
} idfTemp;

pile *p = NULL;

char *sommetDePile(pile *p)
{
    if (p != NULL)
        return p->nom;
    return NULL;
}
char *depiler()
{
    char *ch;
    if (p != NULL)
    {
        ch = p->nom;
        p = p->svt;
        return ch;
    }
    else
    {
        return NULL;
    }
}

idfTemp *idfDeclT = NULL; //la tete de la liste chainé contenant que les idf déclaré
idfTemp *idfDeclQ = NULL; //la queue de la liste chainé des idf déclaré

void inserIdfDecl(char *nom)
{
    idfTemp *ptr = (idfTemp *)malloc(sizeof(idfTemp));
    strcpy(ptr->nom, nom);
    ptr->position = hachage(nom);

    ptr->svt = NULL;

    if (idfDeclT == NULL)
        idfDeclT = ptr;
    else
        (idfDeclQ->svt) = ptr;

    idfDeclQ = ptr;
}

int routinIdfDeclar(char *nom)
{
    int trouve = 0;
    idfTemp *ptr = idfDeclT;
    while ((ptr != NULL) && (trouve == 0))
    {
        if (strcmp(ptr->nom, nom) == 0)
        {
            trouve = 1;
        }
        else
        {
            ptr = ptr->svt;
        }
    }
    //if(trouve == 0) supprimerTS(nom);
    return trouve;
}

void afficherDecl()
{
    printf("  \n");
    printf("  \n");
    printf("\t ****************** list idf *****************/\n");
    printf("\t __________________________\n");
    printf("\t|  NomEntite  |  Position |\n");
    printf("\t __________________________\n");

    idfTemp *ptr = idfDeclT;

    while (ptr != NULL)
    {
        printf("\t| %10s | %10d |\n", ptr->nom, ptr->position);

        ptr = ptr->svt;
    }
}
void printPile(pile *input)
{
    pile *ptr = (pile *)malloc(sizeof(pile));
    ptr = input;

    while (ptr != NULL)
    {
        printf("\t| %p | %10s | %10p |\n", ptr, ptr->nom, ptr->svt);
        ptr = ptr->svt;
    }
    free(ptr);
}

int isEmpty(pile *p)
{
    if (p == NULL)
        return 1;
    return 0;
}
