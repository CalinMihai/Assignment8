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
    if (!node) printf ("Empty list!");
    else
    {
        while(node)
        {
            printf("%d ", node->data);
            node = node->next;
        }
    }
}

int sum(struct Node *head)
{
    int s=0;
    while(head)
    {
        s=s+head->data;
        head=head->next;
    }
    return s;
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
    printf("\nThe list is: ");
    PrintList(p);
    printf("\n");

    printf("\nThe addition of the elements from the list is: %d\n",sum(p));
    return 0;
}
