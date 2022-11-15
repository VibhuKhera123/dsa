#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
} * head , *temp;

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void enqueue(int value, int priority)
{

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->priority = priority;
    

    if (head == NULL)
    {
        newnode->next = NULL;
        head = temp = newnode;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->priority > newnode->priority)
            {
                temp->next = newnode;
                newnode->next = NULL;
                temp = temp->next;
            }
            else
            {
                newnode->next = temp;
                temp = newnode;
            }
        }
    }
}

int main()

{
    int value, priority,i,n;
    printf("Enter the number of elements in the list: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter the value: ");
        scanf("%d",&value);
        printf("Enter the priority: ");
        scanf("%d",&priority);
        enqueue(value, priority);
    }

    

    printf("Queue is :");
    printf("\n");
    display();
    return 0;
}