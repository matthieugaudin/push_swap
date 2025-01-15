/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:42 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 11:05:40 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_stack **head)
{
	t_stack	*last_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last_node = get_last(head);
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev->prev = last_node;
	(*head)->prev->prev->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	ra(t_stack **a, int show_msg)
{
	rotate(a);
	if (show_msg)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int show_msg)
{
	rotate(b);
	if (show_msg)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int show_msg)
{
	ra(a, 0);
	rb(b, 0);
	if (show_msg)
		write(1, "rr\n", 3);
}
