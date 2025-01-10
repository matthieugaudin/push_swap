/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:58:02 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/09 18:09:46 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *to_move)
{
	while (to_move->prev && to_move->target->prev)
		rrr(a, b);
	update_pos(*a);
	update_pos(*b);
}
