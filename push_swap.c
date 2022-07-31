#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc == 1)
        return(0) ;
    stack_init(a, b);
    parse_av(argv, a);
}