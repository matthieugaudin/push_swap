/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:58:16 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 11:03:58 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_stack **head)
{
	if (!head || !*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, int show_msg)
{
	swap(a);
	if (show_msg)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int show_msg)
{
	swap(b);
	if (show_msg)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int show_msg)
{
	sa(a, 0);
	sb(b, 0);
	if (show_msg)
		write(1, "ss\n", 3);
}
