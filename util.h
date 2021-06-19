typedef struct element
{
    char *inf;
    struct element *suivant;
} cellule;

typedef cellule *Pile;

extern int error = 0;
extern Pile _pile = NULL;
extern Pile _postFixed = NULL;

extern int pileVide(Pile _p)
{
    if (_p == NULL)
        return 1;

    else
        return 0;
}

extern char *sommetPile(Pile p)
{
    if (!pileVide(p))
        return (p->inf);
    return NULL;
}

extern void push(Pile *p, char x[])
{

    Pile nouv;

    nouv = (cellule *)malloc(sizeof(cellule));

    nouv->inf = malloc(strlen(x) * sizeof(char));
    strcpy(nouv->inf, x);
    nouv->suivant = *p;

    *p = nouv;
}

extern char *pop(Pile *p)
{
    Pile temp;
    temp = *p;
    char *x = "";
    if (!pileVide(temp))
    {
        x = (*p)->inf;
        *p = (*p)->suivant;
        free(temp);
        return x;
    }
    return "";
}

extern int getSize(Pile *p)
{
    Pile temp = *p;
    int taille = 0;
    while (!pileVide(temp))
    {
        taille++;
        temp = temp->suivant;
    }
    return taille;
}
extern void printStack(Pile *p)
{
    Pile temp = *p;
    while (!pileVide(temp))
    {
        printf("| %s |\n", temp->inf);
        temp = temp->suivant;
    }
}
extern int poids(char op)
{
    switch (op)
    {
    case '(':
        return 5;
    case ')':
        return 5;
    case '*':
        return 4;
    case '/':
        return 4;
    case '+':
        return 3;
    case '-':
        return 3;
    case '!':
        return -5; // !=
    case '>':
        return -2;
    case '<':
        return -2;
    case '=':
        return -2;
    case 'G':
        return -2; // >=
    case 'L':
        return -2; // <=
    default:
        return 0; // ce n'est pas un oprerateur
    }
    return 0;
}
extern int priority(char operator1, char operator2)
{
    return poids(operator1) - poids(operator2);
}
extern int isOperator(char op)
{
    if (poids(op) == 0) // operande
        return 0;
    return 1; //Operator
}
extern char *getExpression(Pile *p)
{
    Pile temp = *p;
    char *result = temp->inf;
    temp = temp->suivant;
    while (!pileVide(temp))
    {
        result = strcat(result, temp->inf);
        temp = temp->suivant;
    }
    return result;
}
extern void toPostfix(Pile *_expression, Pile *_result)
{
    Pile s = NULL, r = NULL;
    Pile temp = *_expression;

    int size = getSize(_expression);
    char *T[size];
    int i = 0;

    while (!pileVide(temp) && i < size)
    {

        T[i] = sommetPile(temp);
        temp = temp->suivant;
        if (T[i][0] == '(')
        {
            push(&s, T[i]);
        }

        if (isOperator(T[i][0]) == 0) //Operande
        {
            push(&r, T[i]);
        }
        if (isOperator(T[i][0]) == 1) //Operateur
        {

            while ((pileVide(s) == 0) && (isOperator(sommetPile(s)[0]) == 1) && (priority(T[i][0], sommetPile(s)[0]) <= 0))
            {
                char *x = pop(&s);
                push(&r, x);
            }

            push(&s, T[i]);
        }
        if (T[i][0] == ')')
        {
            char *x;
            while ((pileVide(s) == 0) && (sommetPile(s)[0] != ')'))
            {
                x = pop(&s);
                push(&r, x);
            }
            push(&s, x);
        }
        i++;
    }
    while ((pileVide(r) == 0))
    {
        char *x = pop(&r);
        push(&s, x);
    }
    //printPile(&s);
    _postFixed = s;
}

extern char *generateTemporaryName(int number)
{
    char *buf = malloc(sizeof(char *));
    snprintf(buf, 4, "t%d", number); // puts string into buffer
    //free(buf);
    return strdup(buf);
}

int isCompatible(const char *type1, const char *type2)
{

    if (strcmp(type1, type2) == 0) //du meme type
        return 1;
    if (strcmp(type1, "INTEGER") == 0 && strcmp(type2, "REAL") == 0)
    {
        return 1;
    }
    if (strcmp(type1, "REAL") == 0 && strcmp(type2, "INTEGER") == 0)
    {
        return 1;
    }
    return 0;
}
extern int compatibilityTest(Pile *_pile)
{

    Pile temp = *_pile;
    char *previous = pop(&temp);
    while ((!pileVide(temp)) && (isCompatible(previous, sommetPile(temp))))
    {
        temp = temp->suivant;
    }
    if (pileVide(temp))
    {
        return 1; // compatible
    }
    printf("%s non compatible avec %s\t", previous, sommetPile(temp));
    return 0;
}