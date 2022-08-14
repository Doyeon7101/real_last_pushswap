#include "push_swap.h"

void set_pivot(t_stack *stack, t_info *info)
{
    // 1 2 3 4 5 6
    info->p_big = stack->numofdata - (stack->numofdata / 3);
    info->p_small = stack->numofdata - 2*(stack->numofdata / 3);
}

//피봇 왕피봇>소피봇
void a_to_b(t_stack *a, t_stack *b, t_info *info, int call_cnt)
{
    int cnt_ra = 0;
    int cnt_rb = 0;
    int len;

    if (a->numofdata < 6)
    {
        sort_2_to_5(a,b);
        return;
    }
    set_pivot(a, info);
    len = a->numofdata - info->p_big;
    while (a->numofdata != len)
    {
        if (a->top-> data > info->p_big)
        {
            op("ra", a, NULL);
            cnt_ra++;
        }
        if (a->top->data <= info->p_big && a->top->data > info->p_small)
        {
            op("pb", a, b);
            if (b->numofdata > 1)
                op("rb", b, NULL);
            cnt_rb++;
        }
        if (a->top->data <= info->p_small)
            op("pb", a, b);
    }
    cnt_rb++;
    while (--cnt_rb > 0)
        op("rrb", b, NULL);
}
/**
void b_to_a(t_stack *a, t_stack *b, t_info *info)
{
    while ()
    {
        if (왕피봇보다 크다면)
            ra;
        if (왕피봇 > 00 > 소피봇)
            pb;
        if (소피봇보다 작다면)
            pb;
            rb;
            cnt++;
    }
    sort(a);
    while (cnt만큼)
        rrb;
}
**/

void sort(t_stack *a, t_stack *b, t_info *info)
{
    if (a->numofdata > 5)
        a_to_b(a, b, info)
    a_to_b(a, b, info);
    // b_to_a(a, b, info);
}