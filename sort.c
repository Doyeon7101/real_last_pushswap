#include "push_swap.h"
void sort_3(t_stack *stack)
{
    int max;
    int min;
    t_node *curr;
    
    curr = stack->top;
    max = return_max(stack);
    min = return_min(stack);
    // find_min_max(stack, &max, &min);
    if(is_ascend(stack))
        return;
    if (curr->data < max && curr->data > min) //중간값
    {
        curr = curr->next;
        if(curr->data == min && op("sa", stack, NULL))
            return;
        if(curr->data == max && op("rra", stack, NULL))
            return;
    }
    if (curr->data == max && op("ra", stack, NULL)) // 최댓값
    {
        curr = curr->next;
        if(curr->data < max && curr->data > min && op("sa", stack, NULL))
            return;
    }
    if(op("sa", stack, NULL) && op("ra", stack, NULL))
        return;
}
/**
void sort_4_to_5(t_stack *a, t_stack *b)
{
    int max;
    int min;
    t_node *curr;
    int cnt;

    cnt = 0;
    max = return_max(a);
    min = return_min(b);
    curr = a->top;
    while (a->numofdata > 3)
    {
        if (curr->data == max || curr->data == min)
        {
            op("pb", a, b);
            cnt++;
        }
        else
            op("ra", a, NULL);
        curr = a->top;
    }
        op("pb", a, b);
    sort_3(a);
}
**/

void sort_1_to_5(t_stack *a, t_stack *b)
{
    if (a->numofdata == 1)
        return;
    if (a->numofdata == 2)
    {
        if (a->top->data > a->top->next->data)
            op("sa", a, NULL);
    }
    if (a->numofdata == 3)
        sort_3(a);
    // if (a->numofdata > 3 && a->numofdata <= 5)
    //     sort_4_to_5(a, b);
}