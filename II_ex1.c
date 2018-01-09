#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int x,int y,struct Node*pr,struct Node*ul)
{
    int i;
    struct Node* newElement=NULL;
    pr->data=y;
    pr->next=NULL;
    ul=pr;
    if(x>1)
        for(i=0; i<x-1; i++)
        {
            newElement=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&y);
            newElement->data=y;
            ul->next=newElement;
            newElement->next=NULL;
            ul=newElement;
        }
}

void PrintList(struct Node *node)
{
    if (!node) printf ("\n Empty list!");
    else
    {
        while(node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
    }
}

struct Node* insertNth(int index,struct Node**head)
{
    struct Node*current=*head;
    struct Node *newElement=NULL;
    struct Node*next;
    int count=0,contor=0;

    while(current)
    {
        if(count==index)
        {
            next=current->next;
            newElement=(struct Node*)malloc(sizeof(struct Node*));
            newElement->data=13;
            newElement->next=next;
            current->next=newElement;
            break;
            contor=1;
        }
        count++;
        current=current->next;
    }
    if(contor==0)
        printf("\nThe list doesn't have the index: %d\n",index);
}

int main()
{
    struct Node* p=NULL;
    struct Node* u=NULL;
    p=(struct Node*)malloc(sizeof(struct Node));
    u=(struct Node *)malloc(sizeof(struct Node));

    int n;///the number of elements from the list
    int m;///elements from the list

    printf("Enter the number of elements from the list: ");
    scanf("%d",&n);

    printf("Enter the first element of the list: ");
    scanf("%d",&m);

    printf("Enter the elements from the list: ");

    createList(n,m,p,u);
    printf("The list before insertion is: ");
    PrintList(p);
    printf("\n");

    int i;
    printf("Enter the index position: ");
    scanf("%d",&i);

    insertNth(i,&p);
    printf("The list after insertion is: ");
    PrintList(p);

    return 0;
}


