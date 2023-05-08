/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:40:27 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/26 18:40:31 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	*malloc_tab(int size)
{
	int	*tab;

	tab = ft_calloc(size, sizeof(int));
	if (!tab)
		return (NULL);
	return (tab);
}

void	init_tab(char **av, t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->a.s)
	{
		if (ft_isdigit(av[i + 1]))
			ft_exit(ERR, st);
		st->a.tab[i] = ft_atoi(av[i + 1], st);
		st->t.tab[i] = ft_atoi(av[i + 1], st);
		i++;
	}
	if (check_double_arg(&st->a))
		ft_exit(ERR, st);
	st->t.s = st->a.s;
	st->b.s = 0;
	st->a.ip = 1;
	st->b.ip = 2;
	st->t.ip = 3;
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if ((s[i] < 47 || s[i] > 57) && s[i] != 45)
			return (-19);
		i++;
	}
	return (0);
}

int	check_double_arg(t_stack *a)
{
	int	i;
	int	j;

	i = 0;
	while (i <= a->s)
	{
		j = i + 1;
		while (j < a->s)
		{
			if (a->tab[j] == a->tab[i])
				return (-19);
			j++;
		}
		i++;
	}
	return (0);
}
