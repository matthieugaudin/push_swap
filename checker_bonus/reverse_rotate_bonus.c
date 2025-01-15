/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:58:02 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 11:03:49 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*first_node;

	if (!head || !(*head) || !(*head)->next)
		return ;
	first_node = *head;
	*head = get_last(head);
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
	(*head)->next = first_node;
	first_node->prev = *head;
}

void	rra(t_stack **a, int show_msg)
{
	reverse_rotate(a);
	if (show_msg)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int show_msg)
{
	reverse_rotate(b);
	if (show_msg)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int show_msg)
{
	rra(a, 0);
	rrb(b, 0);
	if (show_msg)
		write(1, "rrr\n", 4);
}
