#include "push_swap.h"
/**
**/
void sort_3(t_stack *stack)
{
    int max;
    int min;
    t_node *curr;
    
    curr = stack->top;
    max = return_max(stack);
    min = return_min(stack);
    if(is_ascend(stack, 3) == true)
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
        return;
    }
    if(op("sa", stack, NULL) && op("ra", stack, NULL))
        return;
}

/**
가장 작은 숫자 두개만 top으로 올리고
pb 해준다음에
남은 3개는 3 num rotate gg
<가장 작은 숫자 맨 앞으로  올리기>
가장 작은 data가 있는 곳의 인덱스가 
0 이면 그냥 리턴
top에 더 가까우면 ra
bottom 에 더 가까우면 rra
가장 작은 숫자가 top에 위치하지 않을때까지 ra keep
**/

void sort_minnum_to_top(t_stack *stack)
{
    int min;
    t_node *curr;
	int cnt;
    
	cnt = 0;
    curr = stack->top;
    min = return_min(stack);
    if (curr->data == min)
        return;
    while (curr->data != min)
	{
	    curr = curr->next;
	  	cnt++;
	} //cnt : 2 
	if (cnt >= (stack->numofdata) / 2)
    {
        while (stack->top->data != min)
        {
          op("rra", stack, NULL);
          cnt --;
        }
    }
    else
    {
        while (stack->top->data != min)
            op("ra", stack, NULL);
    }
  return;
}
void sort_4_to_5(t_stack *a, t_stack *b, int len)
{
    int origin_numofdata;

    origin_numofdata = a->numofdata;
    // 가장 작은 숫자 2개 top으로 올리기 
    if(is_ascend(a, len))
        return;
    while (a->numofdata > 3) 
    {
        sort_minnum_to_top(a);
        op("pb", a, b);
    }
    sort_3(a);
    while (a->numofdata < origin_numofdata)
        op("pa", b, a);
}

void sort_2_to_5_btoa(t_stack *a, t_stack *b, int len)
{
    if (len == 2 || len == 3)
    {
        if (a->top->data > a->top->next->data)
            op("sb", b, NULL);
        if (len == 3 && !is_ascend(a,len))
        {
            op("rb", b, NULL);
            op("sb", b, NULL);
            op("rrb", b, NULL);
            if (a->top->data < a->top->next->data)
                op("sb", b, NULL);
        }
            // sort_3(a);
    }
    // if (len == 4 || len == 5)
    //     sort_4_to_5(a, b, len);
    return;
}
void sort_2_to_5_atob(t_stack *a, t_stack *b, int len)
{
    if (len == 2 || len == 3)
    {
        if (a->top->data > a->top->next->data)
            op("sa", a, NULL);
        if (len == 3 && !is_ascend(a,len))
        {
            op("ra", a, NULL);
            op("sa", a, NULL);
            op("rra", a, NULL);
            if (a->top->data > a->top->next->data)
                op("sa", a, NULL);
        }
            // sort_3(a);
    }
    if (len == 4 || len == 5)
        sort_4_to_5(a, b, len);
    return;
}
