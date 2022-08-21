#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_info *info;
    t_node *curr;
    int i = 0;
    int max;
    int min;

    stack_init(&a, &b, &info);
    parse_av(argv, a);
    // sort(a,b,info);
    sort_2_to_5_atob(a, b, 5);
    curr = a->top;
    printf("==========STACK A==========\n");
    while (1)
    {
        printf("[%d] : origin : %d, data : %d\n",i, curr->origin, curr->data);
        curr = curr->next;
        if (curr == a->top)
            break;
        i++;
    }
    i = 0;
    curr = b->top;
    printf("==========STACK B==========\n");
    while (1)
    {
        if (curr == b->top)
            return(0);
        printf("[%d] : origin : %d, data : %d\n",i, curr->origin, curr->data);
        curr = curr->next;
        i++;
    }
}
