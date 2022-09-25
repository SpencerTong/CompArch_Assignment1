#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node;

void freeList(struct node *head)
{
    struct node *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

node *createNode(int num)
{
    node *returnNode = malloc(sizeof(node));
    returnNode->value = num;
    returnNode->next = NULL;
    return returnNode;
}

void printList(node *head)
{
    node *temp = head;
    if (temp == NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%i ", temp->value);
            temp = temp->next;
        }
    }
}

int main(int argc, char *argv[])
{
    node *head = NULL;
    FILE *fpointer;
    char str[255];

    fpointer = fopen(argv[1], "r");

    if (fpointer == NULL)
    {
        printf("error\n");
        return 1;
    }
    

    while (fgets(str, 255, fpointer) != NULL)
    {
        if (str[1]!='O'){
        strtok(str, " ");
        int x = atoi(strtok(NULL, " "));
        if (str[1] == 'N')
        {

            if (head == NULL)
            {
                head = createNode(x);
            }
            else
            {
                node *prev = head;
                node *next = head->next;
                while (next != NULL)
                {
                    prev = next;
                    next = next->next;
                }
                free(next);
                prev->next = createNode(x);
            }
            printList(head);
            printf("\n"); 
        }
        else if (str[1] == 'U')
        {
            if (head == NULL)
            {
                head = createNode(x);
            }
            else
            {
                node *newNode = createNode(x);
                newNode->next = head;
                head = newNode;
            }
            printList(head);
            printf("\n");
        } 
        } else {
            if (head==NULL){
                printf("EMPTY\n");
            } else if (head->next==NULL){
                node *temp = head;
                head = head->next;
                free(temp);
                printf("EMPTY\n");
            } else {
                node *temp = head;
                head = head->next;
                free(temp);
                printList(head);
                printf("\n");
            }  
    } 
} 

freeList(head);
fclose(fpointer);
return 0;
}
