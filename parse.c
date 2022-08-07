#include "push_swap.h"

void dub_check(t_stack *a, int val)
{
    t_node *curr;

    if (a->numofdata  < 1)
    {
        return;
    }
    curr = a->top;
    while (1)
    {
        if (curr->data == val)
            ft_print_error();
        curr = curr->next;
        if (curr == a->top)
            return;
    }
}

void parse_av(char **argv, t_stack *a)
{
    char **temp;
    int val;

    argv++;
    while (*argv)
    {
        temp = ft_split(*argv, ' ');
        while(*temp)
        {
            val = ft_atoi(*temp);
            dub_check(a, val);
            insert_node_to_bottom(&a, val);
            temp++;
        }
        argv++;
    }
    return;
}
