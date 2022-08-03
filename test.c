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
/**
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
**/
int printf_jj(void)
{
    printf("jj\n");
    return (1);
}
int printf_kk(void)
{
    printf("kk\n");
    return (1);
}
void test(void)
{
    if (ft_strcmp("sa","ssdfljk") && printf_kk())
        printf("welcome\n");
    if (ft_strcmp("ss", "ss") && printf_jj())
        printf("hihihihihi~~");
}
int main()
{
    test();
}

