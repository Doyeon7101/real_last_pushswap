#include "push_swap.h"

int swap(t_stack *stack)
{
    int temp;

    if (stack->numofdata == 1)
        return(1);
    temp = stack->top->data;
    stack->top->data = stack->top->next->data;
    stack->top->next->data = temp;
    return(1);
}

int push(t_stack *gvn, t_stack *rcv)
{
    insert_node_to_top(&rcv, pop_node(&gvn));
    return(1);
}

int rotate(t_stack **stack)
{
    if ((*stack)->numofdata == 1)
        return(1);
    (*stack)->top = (*stack)->top->next;
    return(1);
}

int r_rotate(t_stack **stack)
{
    if ((*stack)->numofdata == 1)
        return(1);
    (*stack)->top = (*stack)->top->prev;
    return(1);
}

int op(char *str, t_stack *gvn, t_stack *rcv)
{
    t_node *curr;
    if (ft_strcmp("sa",str) &&  swap(gvn))
        ft_putstr_fd("sa\n", STDOUT_FILENO);
    if (ft_strcmp("sb",str) &&  swap(gvn))
        ft_putstr_fd("sb\n", STDOUT_FILENO);
    if (ft_strcmp("ss",str) &&  swap(gvn) && swap(rcv))
        ft_putstr_fd("ss\n", STDOUT_FILENO);
    if (ft_strcmp("pa",str) &&  push(gvn, rcv))
        ft_putstr_fd("pa\n", STDOUT_FILENO);
    if (ft_strcmp("pb",str) &&  push(gvn, rcv))
        ft_putstr_fd("pb\n", STDOUT_FILENO);
    if (ft_strcmp("ra",str) &&  rotate(&gvn))
        ft_putstr_fd("ra\n", STDOUT_FILENO);
    if (ft_strcmp("rb",str) &&  rotate(&gvn))
        ft_putstr_fd("rb\n", STDOUT_FILENO);
    if (ft_strcmp("rr",str) &&  rotate(&gvn) && rotate(&rcv))
        ft_putstr_fd("rr\n", STDOUT_FILENO);
    if (ft_strcmp("rra",str) &&  r_rotate(&gvn))
        ft_putstr_fd("rra\n", STDOUT_FILENO);
    if (ft_strcmp("rrb",str) &&  r_rotate(&gvn))
        ft_putstr_fd("rrb\n", STDOUT_FILENO);
    if (ft_strcmp("rrr",str) &&  r_rotate(&gvn) && r_rotate(&rcv))
        ft_putstr_fd("rrr\n", STDOUT_FILENO);
    return(1);
}