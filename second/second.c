#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node;

void freeList(struct node* head)
{
   struct node* temp;

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
    
    //duplicates

    while (fgets(str, 255, fpointer) != NULL)
    {
        strtok(str, " ");
        int x = atoi(strtok(NULL, " "));
        if ((str[0] == 'I'))
        {
            if (head == NULL)
            {
                head = createNode(x);
            }
            else
            {
                if (head->value>x){
                    node *newNode = createNode(x);
                    newNode->next=head;
                    head=newNode;
                } else {
                node *prev = head;
                node *next = head->next;
                while (next != NULL && next->value<=x)
                {
                    prev = next;
                    next = next->next;
                }
                if (prev->value!=x)
                {
                    node *newNode = createNode(x);
                    newNode->next = next;
                    prev->next = newNode;
                }
                }
            }
            printList(head);
            printf("\n");
        }
        else
        {
            if (head == NULL)
            {
                printf("EMPTY\n");
            }
            else if (head->value == x)  //causing memory leak 
            {   
                node *temp = head;
                head = temp->next;
                free(temp);
                if (head==NULL){
                    printf("EMPTY\n");
                } else {
                    printList(head);
                    printf("\n");
                }
            }
            else
            {
                node *prevNode = head;
                node *nextNode = head->next;
                while (nextNode!=NULL&&nextNode->value!=x){
                    prevNode = nextNode;
                    nextNode = nextNode->next;
                }
                if (nextNode!=NULL){
                    prevNode->next=nextNode->next;
                    free(nextNode);
                }
                printList(head);
                printf("\n");
            }
        }
    }
    freeList(head);
    fclose(fpointer);
    return 0;
}
