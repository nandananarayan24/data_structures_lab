#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

void main() {
    int value, i, n, ch, j;
    struct node *newNode, *current, *head = NULL;

    while(1){
        printf("\n1: Creation\n2: Display\n3:enqueue\n4.dequeue\n5:exit");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("\nEnter the number of nodes: ");
            scanf("%d", &n);

            for (i = 0; i < n; i++) 
            {
                newNode = (struct node*)malloc(sizeof(struct node));  
                printf("\nEnter the value: ");
                scanf("%d", &value);
                newNode->data = value;
                newNode->next = NULL;

                if (head == NULL) 
                {
                    head = newNode; 
                    current = newNode;
                    current->next = head;
                } else
                {
                    current->next = newNode; 
                    current = newNode;
                    current->next=head;
                }
            }
            }
        if(ch==2)
        {
            if(head==NULL)
            {
                printf("The list is empty");
            }
            else
            {
                current = head;
                printf("\nThe linked list is: ");
                printf("%d ", current->data);
                while (current->next != head)
                {
                    current = current->next;
                    printf("%d ", current->data);
                }  
            printf("\n");
            }
        }
        if(ch==3)
        {
            newNode = (struct node*)malloc(sizeof(struct node));
            printf("\nEnter the data: ");
            scanf("%d",&value);
            newNode->data=value;
            newNode->next=head;
            current=head;
            while (current->next != head) 
            {
                current = current->next;
            }
            current->next=newNode;

        }
        
        if(ch==4)
        {
            
            if(head==NULL)
            {
                printf("Emptyyyyyyyy!!!");
            }
            else if(head->next==head)
            {
                head=NULL;
            }
            else
            {
                current=head;
                while(current->next!=head)
                {
                    current=current->next;
                }
                head=head->next;
                current->next=head;
            }

            
        }
        if (ch==5)
        {
            break;
        }
        
}
}
