/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:34:24 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/14 11:34:26 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	c_init_tab(char **av, t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->a.s)
	{
		if (ft_isdigit(av[i + 1]))
			ft_exit(ERR, st);
		st->a.tab[i] = ft_atoi(av[i + 1], st);
		i++;
	}
	if (check_double_arg(&st->a))
		ft_exit(ERR, st);
	st->b.s = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	char	*s1_str;
	char	*s2_str;
	size_t	i;

	s1_str = (char *)s1;
	s2_str = (char *)s2;
	i = 0;
	while (s1_str[i] && s2_str[i] && s1_str[i] == s2_str[i])
		i++;
	return ((unsigned char)s1_str[i] - (unsigned char)s2_str[i]);
}
