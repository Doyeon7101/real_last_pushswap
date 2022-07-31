#include "push_swap.h"
/**
int main(int argc, char **argv)
{
    int i = 1;
    argv++;
    while (*argv)
    {
        printf("%dst argv : %s\n", i, *argv);
        argv++;
        i++;
    }
    return(0) ;
}
**/

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char **temp;
    int i = 0;

    argv++;
    while (*argv)
    {
        temp = ft_split(*argv, ' ');
        while (*temp)
        {
            printf("%dst argv : %s\n", i, *temp);
            temp++;
            i++;
        }
        argv++;
    }

}