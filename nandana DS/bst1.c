#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left; 
    struct node *right; 
};

struct node *root=NULL;

void insertion();
void deletion();
void display();

void main()
{
    int choice;
    while(1)
    {
        printf("-----------Menu----------\n");
        printf("1.Insert\n");
        printf("2.Deletion\n");
        printf("3.Display\n");
        printf("Enter choice---->");
        scanf("%d",&choice);


        if(choice==1)
        {
            insertion();
        }
        if(choice==2)
        {
            deletion();
        }
        if(choice==3)
        {
            display();
        }
    }
}

void insertion()
{
    struct node *newnode, *current, *parent;
    newnode = (struct node *) malloc(sizeof(struct node));
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else 
    {
        current = root;
        parent = NULL;

        while (current != NULL)
        {
            parent = current;
            if (current->data > value)
            {
                current = current->left;
            }
            else if (current->data < value)
            {
                current = current->right;
            }
            else
            {
                printf("Element already exists\n");
                return;
            }
        }

        if (parent->data > value)
        {
            parent->left = newnode;
        }
        else
        {
            parent->right = newnode;
        }
    }
}

struct node* searchnode(int value)
{
    struct node* current, *parent;
    current = root;

    while (current != NULL)
        {
            if(current->right->data == value || current->left->data == value)
            {
                return current;
            }
            else if (current->data > value)
            {
                current = current->left;
            }
            else if (current->data < value)
            {
                current = current->right;
            }
            
        }
        current = NULL;

}
void deletion()
{
    struct node* current;
    int value, test;
    printf("Enter the value you wish to delete: ");
    scanf("%d",&value);
    current = searchnode(value);
    if(current->right->data == value)
    {
        current->right = NULL;
    }
    if(current->left->data == value)
    {
        current->left = NULL;
    }
    
    
}
void inOrder(struct node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d -> ", root->data);
    inOrder(root->right);
}
void display()
{
    printf("IN-Order: ");
    inOrder(root);
    printf("\n");
}