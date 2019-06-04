#include <stdio.h>
#include <stdlib.h>
//wuthout edition
//comment
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *insertAfter(struct Node *start, int value, int loc)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=value;
    if(start==NULL)
    {
        new_node->next=new_node->prev=new_node;
        start=new_node;
        return start;
    }
    else
    {
        struct Node *temp=start;
        while(temp->data!=loc)
        {
            if(temp->next==start)
            {
                struct Node *last=start->prev;
                new_node->next=start;
                start->prev=new_node;
                new_node->prev=last;
                last->next=new_node;
                return start;
            }
            else
            {
                temp=temp->next;
            }
        }
        struct Node *next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=next;
        next->prev=new_node;
    }
    return start;
}

struct Node *deleteNode(struct Node *start, int value)
{
    if(start==NULL)
        return start;

    struct Node *curr=start, *prev_1=NULL;
    while(curr->data!=value)
    {
        if(curr->next==start)
        {
            printf("\nList doesn't have node with value = %d", value);
            return start;
        }
        prev_1=curr;
        curr=curr->next;
    }

    if(curr->next==start&&prev_1==NULL)
    {
        start=NULL;
        free(curr);
        return start;
    }

    if(curr==start)
    {
        prev_1=start->prev;
        start=start->next;
        prev_1->next=start;
        start->prev=prev_1;
        free(curr);
    }

    else if (curr->next == start)
    {
        prev_1->next=start;
        start->prev=prev_1;
        free(curr);
    }
    else
    {
        struct Node *temp=curr->next;
        prev_1->next=temp;
        temp->prev=prev_1;
        free(curr);
    }
    return start;
}

void display(struct Node* start)
{
    struct Node *temp = start;

    printf("Traversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main()
{
    struct Node *start=NULL;

    start=insertAfter(start, 1, 1);
    start=insertAfter(start, 3, 2);
    start=insertAfter(start, 2, 1);
    start=deleteNode(start, 2);

    display(start);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *insertAfter(struct Node *start, int value, int loc)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=value;
    if(start==NULL)
    {
        new_node->next=new_node->prev=new_node;
        start=new_node;
        return start;
    }
    else
    {
        struct Node *temp=start;
        while(temp->data!=loc)
        {
            if(temp->next==start)
            {
                struct Node *last=start->prev;
                new_node->next=start;
                start->prev=new_node;
                new_node->prev=last;
                last->next=new_node;
                return start;
            }
            else
            {
                temp=temp->next;
            }
        }
        struct Node *next=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=next;
        next->prev=new_node;
    }
    return start;
}

struct Node *deleteNode(struct Node *start, int value)
{
    if(start==NULL)
        return start;

    struct Node *curr=start, *prev_1=NULL;
    while(curr->data!=value)
    {
        if(curr->next==start)
        {
            printf("\nList doesn't have node with value = %d", value);
            return start;
        }
        prev_1=curr;
        curr=curr->next;
    }

    if(curr->next==start&&prev_1==NULL)
    {
        start=NULL;
        free(curr);
        return start;
    }

    if(curr==start)
    {
        prev_1=start->prev;
        start=start->next;
        prev_1->next=start;
        start->prev=prev_1;
        free(curr);
    }

    else if (curr->next == start)
    {
        prev_1->next=start;
        start->prev=prev_1;
        free(curr);
    }
    else
    {
        struct Node *temp=curr->next;
        prev_1->next=temp;
        temp->prev=prev_1;
        free(curr);
    }
    return start;
}

void display(struct Node* start)
{
    struct Node *temp = start;

    printf("Traversal in forward direction \n");
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
}

int main()
{
    struct Node *start=NULL;

    start=insertAfter(start, 1, 1);
    start=insertAfter(start, 3, 2);
    start=insertAfter(start, 2, 1);
    start=deleteNode(start, 2);

    display(start);

    return 0;
}
