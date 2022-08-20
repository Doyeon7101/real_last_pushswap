#include "push_swap.h"
void set_pivot(int cnt, int max, int *p_b, int *p_s)
{
    *p_b = max -(cnt/3);
    *p_s = max - (cnt/3)*2;
}
void b_to_a(t_stack *a, t_stack *b, int max, int min, t_info *info)
{
    int p_b;
    int p_s;
    int i;

    info->i = 0;
    info->cnt = 0;
    //sort
    if (max - min +1 <= 5)
    {
        while ((info->cnt) < (max - min)+1 )
        {
            op("pa", b, a);
            (info->cnt)++;
        }
        sort_2_to_5(a, b, max - min+1);
        return;
    }
    //devide
    set_pivot(max-min , max, &p_b, &p_s);
    printf("numofdata : %d, pivot big : %d, pivot small : %d, max : %d, min: %d\n", max, p_b, p_s, max, min);
    while(info->i < max - min + 1)
    {
        if (b->top->data <= max && b->top->data > p_b) //Ⅰ
            op("pa", b, a);
        else if (b->top->data <= p_b && b->top->data > p_s) //Ⅱ
        {
            op("pa", b, a);
            op("ra", a, NULL);
        }
        else if (a->top->data <= p_s && a->top->data >= min) //Ⅲ
            op("rb", b, NULL);
        (info->i)++;
    }
    info->i = 0;
    /**
    while ((info->cnt)++ < (max - min) - (p_b - p_s)*2)
        op("rrb", b, NULL);
    a_to_b(a, b, max, p_b, info); //Ⅰ
    while ((info->i)++ < p_b - p_s) //Ⅱ
        op("rra", a, NULL);
    a_to_b(a, b, p_b, p_s, info);
    while ((info->j)++ < p_s - min) //Ⅲ
        op("pa", b, a);
    a_to_b(a, b, p_s, min, info);
    **/
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
        sort_2_to_5(a, b, max - min +1);
        return;
    }
    set_pivot(max - min + 1, max, &p_b, &p_s);
    printf("numofdata : %d, pivot big : %d, pivot small : %d, max : %d, min: %d\n", max, p_b, p_s, max, min);
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
    printf("=====\n<data len>\n[1]: %d, [2]: %d, [3]: %d\n=====\n",max - p_b, p_b - p_s, p_s - min + 1);
    //2스택(==1스택) 개수 ? : info->cnt
    while ((info->cnt)++ < (p_b - p_s))
        op("rrb", b, NULL);
    a_to_b(a, b, max, p_b+1, info); //1
    b_to_a(a, b, p_b, p_s+1, info); //2
    b_to_a(a, b, p_s, min, info); //3
}

void sort(t_stack *a,t_stack *b, t_info *info)
{
    a_to_b(a, b, a->numofdata, 1, info);
    return;
}