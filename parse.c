#include "push_swap.h"

int dub_check_and_add_data(t_stack *a, int val)
{
    t_node *curr;
    int data;

    data = 0;
    if (a->numofdata  < 1)
        return(data);
    curr = a->top;
    while (1)
    {
        if (curr->origin == val)
            ft_print_error();
        else if (curr->origin > val)
            (curr->data)++;
        else
            data ++;
        curr = curr->next;
        if (curr == a->top)
            return(data);
    }
}

void parse_av(char **argv, t_stack *a)
{
    char **temp;
    int val;
    int data;

    argv++;
    while (*argv)
    {
        temp = ft_split(*argv, ' ');
        while(*temp)
        {
            val = ft_atoi(*temp);
            data = dub_check_and_add_data(a, val);
            insert_node_to_bottom(&a, val, data);
            temp++;
        }
        argv++;
    }
    return;
}
