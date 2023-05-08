/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:01:10 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/30 16:01:12 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	get_min(t_stack *s)
{
	int	i;
	int	tmp;

	i = s->s - 1;
	tmp = s->tab[i];
	while (i >= 0)
	{
		if (tmp > s->tab[i])
			tmp = s->tab[i];
		i--;
	}
	return (tmp);
}

int	get_index(t_stack *s, int e)
{
	int	i;

	i = 0;
	while (i < s->s)
	{
		if (s->tab[i] == e)
			return (i);
		i++;
	}
	return (-19);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->s - 1)
	{
		if (s->tab[i] > s->tab[i + 1])
			return (-19);
		i++;
	}
	return (0);
}
