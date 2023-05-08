/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:09:37 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/26 15:09:41 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ERR "Error\n"

typedef struct s_stack
{
	int	s;
	int	ip;
	int	stat;
	int	*tab;
}			t_stack;

typedef struct s_stacks
{
	t_stack	a;
	t_stack	b;
	t_stack	t;
}			t_stacks;

/*==	=========================================*/
/*=		PUSH_SWAP					            =*/
/*==	=========================================*/

/*--	Init.c-----------------------------------*/
int		*malloc_tab(int size);
void	init_tab(char **av, t_stacks *st);
int		ft_isdigit(char *s);
int		check_double_arg(t_stack *a);

/*--	Little_sort.c----------------------------*/
void	select_little_sort(t_stack *a, t_stack *b);
void	little_sort_2(t_stack *a);
void	little_sort_3(t_stack *a);
void	little_sort_4(t_stack *a, t_stack *b);
void	little_sort_5(t_stack *a, t_stack *b);

/*--	Big_sort.c-------------------------------*/
void	big_sort(t_stacks *st);
void	ft_sort_int_tab(int *tab, int size);
void	radix_sort(t_stacks *st);
int		get_max_binary(t_stack *s);

/*--	Moves(_2).c------------------------------*/
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
int		push(t_stack *a, t_stack *b);
void	swap_swap(t_stack *a, t_stack *b);
void	rot_rot(t_stack *a, t_stack *b);
void	rev_rev_rot(t_stack *a, t_stack *b);

/*--	Moves_Utils.c----------------------------*/
int		get_min(t_stack *s);
int		get_index(t_stack *s, int e);
int		is_sorted(t_stack *s);

/*--	Utils.c----------------------------------*/
void	ft_putstr(char *str);
void	ft_exit(char *str, t_stacks *st);
int		ft_atoi(char *s, t_stacks *st);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

/*==	=========================================*/
/*=		CHECKER						            =*/
/*==	=========================================*/

/*--	Checker_bonus.c--------------------------*/
void	checker(t_stacks *st);

/*--	Get-Next-Line_bonus.c--------------------*/
char	*ft_strjoin_gnl(char *line, char c);
char	*get_next_line(int const fd);
int		stdin_mooves(t_stacks *st, char *input);
int		stdin_read(t_stacks *st);

/*--	Utils_bonus.c----------------------------*/
void	c_init_tab(char **av, t_stacks *st);
int		ft_strcmp(const char *s1, const char *s2);

#endif