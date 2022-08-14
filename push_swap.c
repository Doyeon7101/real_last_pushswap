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

    info = (t_info *)malloc(sizeof(t_info));
    stack_init(&a, &b);
    parse_av(argv, a);
    sort(a,b,info);
    curr = a->top;
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
    printf("print b\n");
    while (1)
    {
        printf("[%d] : origin : %d, data : %d\n",i, curr->origin, curr->data);
        curr = curr->next;
        if (curr == b->top)
            return(0);
        i++;
    }
}
