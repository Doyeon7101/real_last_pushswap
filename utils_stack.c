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

t_node  *nodeinit(int num, int data)
{
    t_node *newnode;

    newnode = (t_node*)malloc(sizeof(t_node));
    newnode->origin = num;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return(newnode);
}

void insert_node_to_bottom(t_stack **a, int num, int data)
{
    t_node *newnode = nodeinit(num, data);
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
        (*a)->top->prev = newnode;
        newnode->next = (*a)->top;
        
        // (*a)->top->prev->next = newnode;
    }
    ((*a)->numofdata)++;
    return;
}


void insert_node_to_top(t_stack **a, int num, int data)
{
    t_node *newnode = nodeinit(num, data);
    t_node *oldtop;

    if((*a)->top == NULL)
    {
        (*a)->top = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        (*a)->top->prev->next = newnode;
        newnode->prev = (*a)->top->prev;
        (*a)->top->prev = newnode;
        newnode->next = (*a)->top;
        (*a)->top = newnode;
    }
    ((*a)->numofdata)++;
    return;
}

int pop_node(t_stack **stack)
{
    t_node *delnode;
    int deldata;

    delnode = (*stack)->top;
    deldata = delnode->data;
    if ((*stack)->top == (*stack)->top->next)
        (*stack)->top = NULL;
    else
    {
        (*stack)->top->prev->next = (*stack)->top->next;
        (*stack)->top->next->prev= (*stack)->top->prev;
        (*stack)->top = (*stack)->top->next;
        delnode->next = delnode;
        delnode->prev = delnode;
    }
    free(delnode);
    delnode = NULL;
    ((*stack)->numofdata)--;
    return(deldata);
}