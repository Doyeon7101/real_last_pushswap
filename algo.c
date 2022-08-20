#include "push_swap.h"

/**
void set_pivot(t_stack *stack, t_info *info)
{
    // 1 2 3 4 5 6
    info->p_big = stack->numofdata - (stack->numofdata / 3);
    info->p_small = stack->numofdata - 2*(stack->numofdata / 3);
}

//피봇 왕피봇>소피봇
void a_to_b(t_stack *a, t_stack *b, t_info *info)
{
    int len;

    set_pivot(a, info);
    printf("big : %d, small : %d\n", info->p_big, info->p_small);
    len = a->numofdata - info->p_big;
    while (a->numofdata != len)
    {
        if (a->top-> data >= info->p_big)
        {
            op("ra", a, NULL);
            (info->cnt_ra)++;
        }
        if (a->top->data < info->p_big && a->top->data >= info->p_small)
        {
            op("pb", a, b);
            if (b->numofdata > 1)
                op("rb", b, NULL);
            (info->cnt_rb)++;
        }
        if (a->top->data = info->p_small)
            op("pb", a, b);
    }
    (info->cnt_rb)++;
    while (--(info->cnt_rb)> 0)
        op("rrr", a, b);
    if (a->numofdata < 6)
    {
        sort_2_to_5(a,b);
        return;
    }
    a_to_b(a, b, info->cnt_ra);
    b_to_a(a, b, info->cnt_rb);
    b_to_a(a, b, info->cnt = info->cnt_pb - info->cnt_rb);

}
void b_to_a(t_stack *a, t_stack *b, t_info *info)
{
    int len;

    if (b->numofdata < 3)
    {
        sort_2_to_5(b, a);
        while(--(info->cnt_pb) >= 0)
            op("pa", b, a);
        return;
    }
    set_pivot(b, info);
    len = b->numofdata - info->p_big;
    while (b->numofdata != len)

    while (cnt만큼)
        rrb;
}

void sort(t_stack *a, t_stack *b, t_info *info)
{
    int call_cnt;
    call_cnt = 0;
    a_to_b(a, b, info);
    // b_to_a(a, b, info);
}

**/