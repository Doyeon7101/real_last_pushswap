#include "push_swap.h"

//테스트를 위한 임시main
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_node *curr;
    int i = 0;

    stack_init(&a, &b);
    parse_av(argv, a);
    op("rra", a, NULL);
    curr = a->top;
    while (1)
    {
        printf("%dst a's data = %d\n",i, curr->data);
        curr = curr->next;
        if (curr == a->top)
            break;
        i++;
    }
    i = 0;
    /**
    curr = b->top;
    while (1)
    {
        printf("%dst b's data = %d\n",i, curr->data);
        curr = curr->next;
        if (curr == b->top)
            return(0);
        i++;
    }
    **/
}
