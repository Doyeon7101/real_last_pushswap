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
            insert_node(&a, val);
            temp++;
        }
        argv++;
    }
    return;
}

//parse_av에 str 넣고 node 끝까지 insert하고 확인하기
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_node *curr;
    int i = 0;

    stack_init(&a, &b);
    parse_av(argv, a);
    curr = a->top;
    while (1)
    {
        printf("%dst data = %d\n",i, curr->data);
        curr = curr->next;
        if (curr == a->top)
            return(0);
        i++;
    }
}