#include "push_swap.h"
void set_pivot(int cnt, int max, int *p_b, int *p_s)
{
    *p_b = max -(cnt/3);
    *p_s = max - (cnt/3)*2;
}
void rewind_stack(t_stack *rcv, t_stack *gvn, char *operation, int cnt)
{
    int i;

    i = 0;
    if (ft_strcmp("pa",operation) || ft_strcmp("pb", operation))
    {
        while (i < cnt)
        {
            op(operation, gvn, rcv);
            i++;
        }
        return;
    }
    while (i < cnt)
    {
        op(operation, rcv, NULL);
        i++;
    }

}
void b_to_a(t_stack *a, t_stack *b, int max, int min, t_info *info)
{
    int p_b;
    int p_s;

    info->i = 0;
    info->cnt = 0;
    //sort
    if (max - min +1 <= 3)
    {
        while ((info->cnt) < (max - min)+1 )
        {
            op("pa", b, a);
            (info->cnt)++;
        }
        sort_2_to_5_btoa(a, b, max - min+1);
        return;
    }
    set_pivot(max-min , max, &p_b, &p_s);
    printf("numofdata : %d, pivot big : %d, pivot small : %d, max : %d, min: %d\n", max, p_b, p_s, max, min);
    while(info->i < max - min + 1)
    {
        if (b->top->data <= max && b->top->data >= p_b) //Ⅰ
            op("pa", b, a);
        else if (b->top->data < p_b && b->top->data >= p_s) //Ⅱ
        {
            op("pa", b, a);
            op("ra", a, NULL);
        }
        else if (b->top->data < p_s && b->top->data >= min) //Ⅲ
            op("rb", b, NULL);
        (info->i)++;
    }
    rewind_stack(a,b,"rrr", p_b-p_s);
    a_to_b(a, b, max, p_b, info); //Ⅰ
    a_to_b(a,b, p_b,p_s, info);
    rewind_stack(a, b, "pa", (max-min+1) - (p_b-p_s)*2);
    a_to_b(a,b,p_s,min,info);
}

//1더미 ,2 더미 -> min이 있어
void a_to_b(t_stack *a, t_stack *b, int max, int min, t_info *info)
{
    int p_b;
    int p_s;

    info-> i = 0;
    printf("max : %d, min : %d\n", max, min);
    if (max - min +1 <= 5)
    {
        sort_2_to_5_atob(a, b, max - min +1);
        return;
    }
    set_pivot(max - min + 1, max, &p_b, &p_s);
    while(info->i < max - min+1)
    {
        if (a->top->data <= max && a->top->data > p_b) //Ⅰ
            op("ra", a, NULL);
        else if (a->top->data <= p_b && a->top->data > p_s) //Ⅱ
        {
            op("pb", a, b);
            op("rb", b, NULL);
        }
        else if (a->top->data <= p_s && a->top->data >= min) //Ⅲ
            op("pb", a, b);
        (info->i)++;
    }
    while ((info->cnt)++ < (p_b - p_s))
        op("rrr", a, b);
    a_to_b(a, b, max, p_b+1, info); //1
    b_to_a(a, b, p_b, p_s+1, info); //2
    b_to_a(a, b, p_s, min, info); //3
}

void sort(t_stack *a,t_stack *b, t_info *info)
{
    a_to_b(a, b, a->numofdata, 1, info);
    return;
}