#include "push_swap.h"
void set_pivot(int cnt, int pb_b, int *p_b, int *p_s)
{
    *p_b = pb_b -(cnt/3);
    *p_s = pb_b - (cnt/3)*2;
}
void b_to_a(t_stack *a, t_stack *b, int pb_b, int pb_s, t_info *info);
void a_to_b(t_stack *a, t_stack *b, int pb_b, int pb_s, t_info *info)
{
    int p_b;
    int p_s;
    int i;

    if (a->numofdata <= 5)
    {
        sort_2_to_5(a, b);
        return;
    }
    i = 0;
    set_pivot(pb_b - pb_s, pb_b, &p_b, &p_s);
    printf("numofdata : %d, pivot big : %d, pivot small : %d\n", pb_b, p_b, p_s);
    while(i < pb_b - pb_s)
    {
        if (a->top->data <= pb_b && a->top->data > p_b) //Ⅰ
            op("ra", a, NULL);
        else if (a->top->data <= p_b && a->top->data > p_s) //Ⅱ
        {
            op("pb", a, b);
            op("rb", b, NULL);
        }
        else if (a->top->data <= p_s && a->top->data >= pb_s + 1) //Ⅲ
            op("pb", a, b);
        i++;
    }
    //2스택 개수 ? : info->cnt
    while ((info->cnt)++ < (p_b - p_s))
        op("rrb", b, NULL);
    a_to_b(a, b, p_b, pb_s, info);
        /**
    b_to_a(a, b, p_b, p_s, info); //2
    b_to_a(a, b, p_b, p_s, info); //3
    **/
}

void sort(t_stack *a,t_stack *b, t_info *info)
{
    a_to_b(a, b, a->numofdata, 0, info);
    return;
}