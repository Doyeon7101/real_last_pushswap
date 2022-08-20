#include "push_swap.h"
void sort_3(t_stack *stack)
{
    int max;
    int min;
    t_node *curr;
    
    curr = stack->top;
    max = return_max(stack);
    min = return_min(stack);
    if(is_ascend(stack) == true)
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
void sort_4_to_5(t_stack *a, t_stack *b)
{
    int max;
    int min;
    int origin_numofdata;
    int tmp;

    origin_numofdata = a->numofdata;
    // 가장 작은 숫자 2개 top으로 올리기 
    if(!is_ascend)
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

void sort_2_to_5(t_stack *a, t_stack *b)
{
    if (a->numofdata == 2)
    {
        if (a->top->data > a->top->next->data)
            op("sa", a, NULL);
    }
    if (a->numofdata == 3)
        sort_3(a);
    if (a->numofdata == 4 || a->numofdata ==5)
        sort_4_to_5(a, b);
    return;
}
