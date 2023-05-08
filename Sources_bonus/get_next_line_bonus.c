/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaillea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:28:29 by acaillea          #+#    #+#             */
/*   Updated: 2022/01/10 16:28:31 by acaillea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

char	*ft_strjoin_gnl(char *line, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (line && line[i])
		i++;
	new = (char *)malloc((i + 2) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (line && line[i] && line[i + 1] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	if (line)
		free(line);
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int const fd)
{
	char	buff[1];
	char	*line;
	int		rd;

	line = NULL;
	while (buff[0] != '\n')
	{
		rd = read(fd, buff, 1);
		if (rd == 0 || rd == -1)
			break ;
		line = ft_strjoin_gnl(line, buff[0]);
	}
	return (line);
}

int	stdin_mooves(t_stacks *st, char *input)
{
	if (ft_strcmp(input, "sa\n") == 0)
		swap(&st->a);
	else if (ft_strcmp(input, "sb\n") == 0)
		swap(&st->b);
	else if (ft_strcmp(input, "ss\n") == 0)
		swap_swap(&st->a, &st->b);
	else if (ft_strcmp(input, "pa\n") == 0)
		push(&st->b, &st->a);
	else if (ft_strcmp(input, "pb\n") == 0)
		push(&st->a, &st->b);
	else if (ft_strcmp(input, "ra\n") == 0)
		rotate(&st->a);
	else if (ft_strcmp(input, "rb\n") == 0)
		rotate(&st->b);
	else if (ft_strcmp(input, "rr\n") == 0)
		rot_rot(&st->a, &st->b);
	else if (ft_strcmp(input, "rra\n") == 0)
		reverse_rotate(&st->a);
	else if (ft_strcmp(input, "rrb\n") == 0)
		reverse_rotate(&st->b);
	else if (ft_strcmp(input, "rrr\n") == 0)
		rev_rev_rot(&st->a, &st->b);
	else
		return (1);
	return (0);
}

int	stdin_read(t_stacks *st)
{
	char	*input;

	while (19)
	{
		input = get_next_line(STDIN_FILENO);
		if (!input)
			break ;
		if (stdin_mooves(st, input))
		{
			free(input);
			return (1);
		}
		free(input);
	}
	return (0);
}
