#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct quadNode quadNode;
struct quadNode{

    char oper[10];
    char op1[10];
    char op2[10];
    char res[10];
    quadNode *next;
};

typedef struct QUAD QUAD;
struct QUAD{
    quadNode *head;
};


int qc = 0 ;

QUAD quadMatrix;

void initialize(){

    quadMatrix.head = malloc(sizeof(quadMatrix.head));

    quadMatrix.head = NULL;
    //return quadMatrix;
}

quadNode *creatQNode(char opr[],char op1[],char op2[],char res[]){

    quadNode *new = malloc(sizeof(*new));

    strcpy(new->oper  ,   opr);
    strcpy(new->op1   ,   op1);
    strcpy(new->op2   ,   op2);
    strcpy(new->res   ,   res);
    new->next = NULL;

    return new;
}


void insererQUADR(char opr[],char op1[],char op2[],char res[]){

    quadNode **temp;
    (temp) =  &quadMatrix.head;

    quadNode *new = creatQNode(opr,op1,op2,res);

    if(new == NULL )
        exit(EXIT_FAILURE);

    //insertion are in FIFO
    if(*temp == NULL){
        *temp = new;
    }else {
        quadNode *t = (*temp);
        while (t->next != NULL) {
            t = (t)->next;
        }
        (t)->next = new;
    }
    qc++;
}

void delete(){
    if(quadMatrix.head == NULL)
        exit(EXIT_FAILURE);
    if(quadMatrix.head != NULL){

        quadNode *toBeDeleted = quadMatrix.head;
        quadMatrix.head = quadMatrix.head->next;
        free(toBeDeleted);
    }
}

void printQuad(QUAD quadMatrix){

    printf("*********************LesQuadruplets***********************\n");

    if(quadMatrix.head == NULL ){
        exit(EXIT_FAILURE);
    }

    //quadNode **actual = &quadMatrix.head;
    quadNode *actual = quadMatrix.head;
    int i = 0;
    while(actual != NULL)
    {
        //printf("%a ---- %a \n",quadMatrix,quadMatrix->head);
        printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )",i,(actual)->oper,(actual)->op1,(actual)->op2,(actual)->res);
        printf("\n---------------------------------------------------\n");

        actual = (actual)->next;
        i++;
    }
}


void ajour_quad(int num_quad, int colon_quad, char val []) {

    int i = 0;
    quadNode **temp;
    (temp) = &quadMatrix.head;
    quadNode *t = (*temp);

    while (t != NULL && i < num_quad) {
        t = t->next;
        i++;
    }
    if (t == NULL)
        printf("erro_parenthese , le quadruplet n'existe pas\n");
    else {
        if (colon_quad == 0)
            strcpy(t->oper, val);
        else {
            if (colon_quad == 1)
                strcpy(t->op1, val);
            else {
                if (colon_quad == 2)
                    strcpy(t->op2, val);
                else if (colon_quad == 3)
                    strcpy(t->res, val);
            }
        }

    }
}

char *createName(char name[],int number){

    char toString[8];
    sprintf(toString,"%d",number);
    char *result = malloc((strlen(name)+strlen(toString))*sizeof(char));
    strcpy(result,name);
    strcat(result,toString);//pour construire le nom t0..t10...tn qui sera dans result : nom+numero
    return result;
}

