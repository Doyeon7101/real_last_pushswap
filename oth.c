#include "push_swap.h"

void ft_print_error(void)
{
    ft_putstr_fd("Error", STDERR_FILENO);
    exit(1);
}

/**
void find_min_max(t_stack *stack, int *max, int *min)
{
    t_node *curr;
    
    *max = curr->data;
    *min = curr->next->data;
    printf("here : %d", *max);
    while (1)
    {    
        if (curr->data > curr->next->data)
        {
            if (curr->data > *max)
                *max = curr->data;
            if (curr->next->data < *min)
                *min = curr->next->data;
        }
        else
        {
            if (curr->next->data > *max)
                *max = curr->next->data;
            if (curr->next->data < *min)
                *min = curr->data;
        }
        if (curr->next == stack->top)
            return;
        curr = curr->next->next;
    }
}
**/

int return_max(t_stack *stack)
{
    t_node *curr;
    int max;

    curr = stack->top;
    max = curr->data;
    while (1)
    {
        if (curr->data > max)
            max = curr->data;
        curr = curr->next;
        if (curr == stack->top)
            return(max);
    }
}

int return_min(t_stack *stack)
{
    t_node *curr;
    int min;

    curr = stack->top;
    min = curr->data;
    while (1)
    {
        if (curr->data < min)
            min = curr->data;
        curr = curr->next;
        if (curr == stack->top)
            return(min);
    }
}

bool is_ascend(t_stack *stack)
{
    t_node *curr;

    curr = stack->top;
    while (1)
    {
        if (curr->data > curr->next->data)
            return(false);
        curr = curr->next;
        if(curr == stack->top)
            return(true);
    }
}


// void set_pivot(t_stack *a, t_stack *b, t_info *info)

