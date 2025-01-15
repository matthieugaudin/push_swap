/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:57:49 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/14 19:25:41 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push(t_stack **head_src, t_stack **head_dst)
{
	t_stack	*to_push;

	if (!head_src || !head_dst || !(*head_src))
		return ;
	to_push = *head_src;
	*head_src = (*head_src)->next;
	if (*head_src)
		(*head_src)->prev = NULL;
	to_push->prev = NULL;
	to_push->next = *head_dst;
	if (*head_dst)
		(*head_dst)->prev = to_push;
	*head_dst = to_push;
}

void	pa(t_stack **a, t_stack **b, int show_msg)
{
	push(b, a);
	if (show_msg)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int show_msg)
{
	push(a, b);
	if (show_msg)
		write(1, "pb\n", 3);
}
