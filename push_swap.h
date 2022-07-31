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
	t_node *bottom;
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

//parse
void parse_av(char **argv, t_stack *a);

//operaction

//algo
bool sort(t_stack **a, t_stack **b);
bool set_pivot(t_stack **stack, int **pivot);
bool a_to_b(t_stack **stack);
bool b_to_a(t_stack **stack);

//uitl
void	ft_print_error(void);


//libft
void	ft_putstr_fd(char *s, int fd);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
size_t ft_strlen(const char *str);

#endif