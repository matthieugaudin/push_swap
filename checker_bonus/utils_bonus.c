/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:23:27 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/14 11:45:32 by mgaudin          ###   ########.fr       */
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

void	free_list_a(t_list **a)
{
	t_list	*tmp_node;

	while (*a)
	{
		tmp_node = *a;
		*a = (*a)->next;
		free(tmp_node->content);
		free(tmp_node);
	}
}

void	send_error(t_list **a, char **args, int argc)
{
	if (a)
		free_list_a(a);
	if (argc == 2)
		free_tab(args);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
