/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 15:24:24 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/30 15:24:26 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->s < 2)
		return ;
	tmp = s->tab[0];
	s->tab[0] = s->tab[1];
	s->tab[1] = tmp;
	if (s->ip == 1 && s->stat != -1)
		ft_putstr("sa\n");
	if (s->ip == 2 && s->stat != -1)
		ft_putstr("sb\n");
}

void	rotate(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->tab[0];
	while (i <= s->s - 1)
	{
		s->tab[i] = s->tab[i + 1];
		i++;
	}
	s->tab[s->s - 1] = tmp;
	if (s->ip == 1 && s->stat != -1)
		ft_putstr("ra\n");
	if (s->ip == 2 && s->stat != -1)
		ft_putstr("rb\n");
}

void	reverse_rotate(t_stack *s)
{
	int	tmp;
	int	size;

	size = s->s - 1;
	tmp = s->tab[size];
	while (size)
	{
		s->tab[size] = s->tab[size - 1];
		size--;
	}
	s->tab[0] = tmp;
	if (s->ip == 1 && s->stat != -1)
		ft_putstr("rra\n");
	if (s->ip == 2 && s->stat != -1)
		ft_putstr("rrb\n");
}

int	push(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;

	if (a->s == 0)
		return (-1);
	tmp = a->tab[0];
	i = -1;
	while (++i < a->s - 1)
		a->tab[i] = a->tab[i + 1];
	a->s--;
	b->s++;
	i = b->s - 1;
	while (i)
	{
		b->tab[i] = b->tab[i - 1];
		i--;
	}
	b->tab[0] = tmp;
	if (a->ip == 1 && a->stat != -1)
		ft_putstr("pb\n");
	if (a->ip == 2 && a->stat != -1)
		ft_putstr("pa\n");
	return (0);
}
