/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:22:01 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/08 15:22:05 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	big_sort(t_stacks *st)
{
	int	i;
	int	tmp;

	i = 0;
	if (is_sorted(&st->t))
	{
		ft_sort_int_tab(st->t.tab, st->t.s);
		while (i < st->t.s)
		{
			tmp = st->a.tab[i];
			st->a.tab[i] = get_index(&st->t, tmp);
			i++;
		}
		radix_sort(st);
	}
	else
		return ;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i <= size)
	{
		j = 0;
		while (j < (size - 1))
		{
			if (tab[j + 1] < tab[j])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	radix_sort(t_stacks *st)
{
	int	max_bin;
	int	i_bin;
	int	i;

	max_bin = get_max_binary(&st->a);
	i_bin = 0;
	while (i_bin < max_bin)
	{
		i = 0;
		while (i < st->t.s)
		{
			if ((st->a.tab[0] >> i_bin) & 1)
				rotate(&st->a);
			else
				push(&st->a, &st->b);
			i++;
		}
		while (st->b.s > 0)
			push(&st->b, &st->a);
		i_bin++;
	}
}

int	get_max_binary(t_stack *s)
{
	int	max_bin;
	int	size;

	max_bin = 1;
	size = s->s - 1;
	while (size != 1)
	{
		max_bin++;
		size /= 2;
	}
	return (max_bin);
}
