/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:09:53 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/26 15:09:54 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		exit(0);
	st.a.tab = malloc_tab(ac - 1);
	st.b.tab = malloc_tab(ac - 1);
	st.t.tab = malloc_tab(ac - 1);
	st.a.s = ac - 1;
	st.a.stat = 1;
	init_tab(av, &st);
	if (st.a.s > 1 && st.a.s < 6)
		select_little_sort(&st.a, &st.b);
	else
		big_sort(&st);
	free(st.a.tab);
	free(st.b.tab);
	free(st.t.tab);
	return (0);
}
