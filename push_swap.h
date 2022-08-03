#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	int origin;
	int data;
	struct s_node *next;
	struct s_node *prev;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int numofdata;
} t_stack;

typedef struct s_info
{
	int pivot_a;
	int pivot_b;
} t_info;

//stack
void stack_init(t_stack **a, t_stack **b);
void insert_node(t_stack **a, int num);
int pop_node(t_stack **stack);

//parse
void parse_av(char **argv, t_stack *a);

//operaction
int op(char *str, t_stack *gvn, t_stack *rcv);
int swap(t_stack *stack);
int push(t_stack *gvn, t_stack *rcv);
int rotate(t_stack **stack);
int r_rotate(t_stack **stack);

//sort
void sort_3(t_stack *stack);
void sort_2_to_5(t_stack *a, t_stack *b);
void sort_4_to_5(t_stack *a, t_stack *b);


//algo
bool sort(t_stack **a, t_stack **b);
bool set_pivot(t_stack **stack, int **pivot);
bool a_to_b(t_stack **stack);
bool b_to_a(t_stack **stack);

//uitl
void	ft_print_error(void);
void find_min_max(t_stack *stack, int *max, int *min);
int return_max(t_stack *stack);
int return_min(t_stack *stack);
bool is_ascend(t_stack *stack);


//libft
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t ft_strlen(const char *str);
bool ft_strcmp(const char *s1, const char *s2);

#endif