
typedef struct Node Node;
struct Node
{

    char oper[10];
    char op1[10];
    char op2[10];
    char res[10];
    Node *next;
};

typedef struct QUAD QUAD;
struct QUAD
{
    Node *head;
};

int qc = 0;

QUAD quadMatrix;

void initialize()
{
    quadMatrix.head = malloc(sizeof(quadMatrix.head));
    quadMatrix.head = NULL;
}

Node *creatNode(char opr[], char op1[], char op2[], char res[])
{

    Node *new = malloc(sizeof(*new));

    strcpy(new->oper, opr);
    strcpy(new->op1, op1);
    strcpy(new->op2, op2);
    strcpy(new->res, res);
    new->next = NULL;

    return new;
}

void insertQuadreplet(char opr[], char op1[], char op2[], char res[])
{

    Node **temp;
    (temp) = &quadMatrix.head;

    Node *new = creatNode(opr, op1, op2, res);

    if (new == NULL)
        exit(EXIT_FAILURE);

    //insertion are in FIFO
    if (*temp == NULL)
    {
        *temp = new;
    }
    else
    {
        Node *t = (*temp);
        while (t->next != NULL)
        {
            t = (t)->next;
        }
        (t)->next = new;
    }
    qc++;
}

void deleteQuadreplet()
{
    if (quadMatrix.head == NULL)
        exit(EXIT_FAILURE);
    if (quadMatrix.head != NULL)
    {

        Node *toBeDeleted = quadMatrix.head;
        quadMatrix.head = quadMatrix.head->next;
        free(toBeDeleted);
    }
}

void printQuadreplet()
{

    printf("********************* Les Quadruplets ***********************\n");

    if (quadMatrix.head == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Node *actual = quadMatrix.head;
    int i = 0;
    while (actual != NULL)
    {
        printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )", i, (actual)->oper, (actual)->op1, (actual)->op2, (actual)->res);
        printf("\n---------------------------------------------------\n");
        actual = (actual)->next;
        i++;
    }
}

void updateQuadreplet(int num_quad, int colon_quad, char val[])
{

    int i = 0;
    Node **temp;
    (temp) = &quadMatrix.head;
    Node *t = (*temp);

    while (t != NULL && i < num_quad)
    {
        t = t->next;
        i++;
    }
    if (t == NULL)
        printf("erro_parenthese , le quadruplet n'existe pas\n");
    else
    {
        if (colon_quad == 0)
            strcpy(t->oper, val);
        else
        {
            if (colon_quad == 1)
                strcpy(t->op1, val);
            else
            {
                if (colon_quad == 2)
                    strcpy(t->op2, val);
                else if (colon_quad == 3)
                    strcpy(t->res, val);
            }
        }
    }
}

char *createName(char name[], int number)
{

    char toString[8];
    sprintf(toString, "%d", number);
    char *result = malloc((strlen(name) + strlen(toString)) * sizeof(char));
    strcpy(result, name);
    strcat(result, toString); //pour construire le nom t0..t10...tn qui sera dans result : nom+numero
    return result;
}
