/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:23:27 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 10:52:58 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack_a(t_stack **a)
{
	t_stack	*tmp_node;

	while (*a)
	{
		tmp_node = *a;
		*a = (*a)->next;
		free(tmp_node);
	}
}

void	send_error(t_stack **a, t_stack **b, t_list **moves, char *line)
{
	if (a)
		free_stack_a(a);
	if (b)
		free_stack_a(b);
	free(line);
	ft_lstclear(moves, free);
	get_next_line(0, 5, 1);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

t_stack	*get_last(t_stack **head)
{
	t_stack	*node;

	node = *head;
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	ft_to_clean(char **pstash)
{
	free(*pstash);
	*pstash = NULL;
}
