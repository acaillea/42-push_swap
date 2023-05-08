/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:12:40 by acaillea          #+#    #+#             */
/*   Updated: 2022/02/10 15:12:42 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	checker(t_stacks *st)
{
	if (stdin_read(st))
		ft_exit(ERR, st);
	if (!is_sorted(&st->a) && !st->b.s)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		return (0);
	st.a.tab = malloc_tab(ac - 1);
	st.b.tab = malloc_tab(ac - 1);
	st.a.s = ac - 1;
	st.a.stat = -1;
	st.b.stat = -1;
	c_init_tab(av, &st);
	checker(&st);
	free(st.a.tab);
	free(st.b.tab);
	return (0);
}
