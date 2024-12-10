#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node* prev;
    int data;
    struct node* next;
};

void main() 
{
    int value, i, n, ch, j;
    struct node *newNode, *current, *head = NULL, *tail;

    while(1)
    {
        printf("__________Menu__________\n");
        printf("1: Insert at beginning\n");
        printf("2: Insert at end\n");
        printf("3: Display list\n");
        printf("4: Delete Node at end\n");
        printf("5: Delete Node at start\n");
        printf("\n\n");
        printf("Enter choice---->");
        scanf("%d",&ch);

        if (ch==1)
        {
            if (head==NULL)
            {
                newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter Data---->");
                scanf("%d",&value);
                newNode->prev=NULL;
                newNode->next=NULL;
                newNode->data=value;
                head=newNode;
            }
            else
            {
                newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter Data---->");
                scanf("%d",&value);
                newNode->data=value;
                newNode->prev=NULL;
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
            }

        }
        if(ch==2)
        {
            if (head==NULL)
            {
                newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter Data---->");
                scanf("%d",&value);
                newNode->prev=NULL;
                newNode->next=NULL;
                newNode->data=value;
                head=newNode;
            }
            else
            {
                current=head;
                while(current->next!=NULL)
                {
                    current=current->next;
                }
                newNode = (struct node*)malloc(sizeof(struct node));
                printf("Enter Data---->");
                scanf("%d",&value);
                current->next=newNode;
                newNode->data=value;
                newNode->prev=current;
                newNode->next=NULL;
                tail=newNode;

            }

        }
        if(ch==3)
        {
            current = head;
            printf("The linked list is: ");
            while (current != NULL) {
                printf("%d  ", current->data);
                current = current->next;
            }
            printf("\n");
        }
        if (ch==4)
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        if (ch==5)
        {
            head=head->next;
        }
    }
}