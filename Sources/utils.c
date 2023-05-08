/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:16:05 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/26 15:16:08 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_exit(char *str, t_stacks *st)
{
	ft_putstr(str);
	free(st->a.tab);
	free(st->b.tab);
	if (st->a.stat == 1)
		free(st->t.tab);
	exit(0);
}

int	ft_atoi(char *s, t_stacks *st)
{
	long	res;
	long	sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	if (s[i] && s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s && s[i])
	{
		res = (res * 10) + (s[i] - 48);
		i++;
		if (res * sign < -2147483648)
			ft_exit(ERR, st);
		if (res * sign > 2147483647)
			ft_exit(ERR, st);
	}
	return ((int)res * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = (void *)malloc(size * count);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, count);
	return (tab);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
