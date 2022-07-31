#include "push_swap.h"

void    stack_init(t_stack **a, t_stack **b)
{
    *a = (t_stack*)malloc(sizeof(t_stack));
    *b = (t_stack*)malloc(sizeof(t_stack));
    (*a)->top = NULL;
    (*a)->numofdata = 0;
    (*b)->top = NULL;
    (*b)->numofdata = 0;
    return ;
}

t_node  *nodeinit(int num)
{
    t_node *newnode;

    newnode = (t_node*)malloc(sizeof(t_node));
    newnode->data = num;
    newnode->next = NULL;
    newnode->prev = NULL;
    return(newnode);
}

void insert_node(t_stack **a, int num)
{
    t_node *newnode = nodeinit(num);
    t_node *oldbottom;

    if((*a)->top == NULL)
    {
        (*a)->top = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        oldbottom = (*a)->top->prev;
        oldbottom->next = newnode;
        newnode->prev = oldbottom;
        newnode->next = (*a)->top;
        (*a)->top->prev = newnode;
    }
    ((*a)->numofdata)++;
    return;
}

