/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:35:42 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/08 16:35:44 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	swap_swap(t_stack *a, t_stack *b)
{
	a->ip = 5;
	b->ip = 6;
	swap(a);
	swap(b);
	if (a->stat != -1)
		ft_putstr("ss\n");
	a->ip = 1;
	a->ip = 2;
}

void	rot_rot(t_stack *a, t_stack *b)
{
	a->ip = 5;
	b->ip = 6;
	rotate(a);
	rotate(b);
	if (a->stat != -1)
		ft_putstr("rr\n");
	a->ip = 1;
	a->ip = 2;
}

void	rev_rev_rot(t_stack *a, t_stack *b)
{
	a->ip = 5;
	b->ip = 6;
	reverse_rotate(a);
	reverse_rotate(b);
	if (a->stat != -1)
		ft_putstr("rrr\n");
	a->ip = 1;
	a->ip = 2;
}
