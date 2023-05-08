/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:46:09 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/29 18:46:11 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	select_little_sort(t_stack *a, t_stack *b)
{
	if (a->s == 2)
		little_sort_2(a);
	else if (a->s == 3)
		little_sort_3(a);
	else if (a->s == 4)
		little_sort_4(a, b);
	else if (a->s == 5)
		little_sort_5(a, b);
}

void	little_sort_2(t_stack *a)
{
	if (a->tab[0] > a->tab[1])
		swap(a);
}

void	little_sort_3(t_stack *a)
{
	little_sort_2(a);
	if (is_sorted(a))
	{
		reverse_rotate(a);
		if (is_sorted(a))
			swap(a);
	}
}

void	little_sort_4(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
	{
		while (a->tab[0] != get_min(a))
			rotate(a);
		push(a, b);
		little_sort_3(a);
		push(b, a);
	}
}

void	little_sort_5(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
	{
		while (a->tab[0] != get_min(a))
			rotate(a);
		push(a, b);
		little_sort_4(a, b);
		push(b, a);
	}
}
