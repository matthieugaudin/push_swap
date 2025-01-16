/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:46:29 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/16 09:31:43 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_move(char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		return (1);
	else if (ft_strcmp(line, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(line, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(line, "ss\n") == 0)
		return (1);
	else
		return (0);
}

static void	exec_move(t_stack **a, t_stack **b, t_list *move)
{
	if (ft_strcmp(move->content, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(move->content, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(move->content, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(move->content, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(move->content, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp((char *)move->content, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(move->content, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(move->content, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(move->content, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(move->content, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(move->content, "ss\n") == 0)
		ss(a, b, 0);
}

static int	add_move(t_list **moves, char *move)
{
	t_list	*to_append;

	to_append = malloc(sizeof(t_list));
	if (!to_append)
		return (0);
	to_append->content = ft_strdup(move);
	if (!to_append->content)
	{
		free(to_append);
		return (0);
	}
	to_append->next = NULL;
	if (!(*moves))
		*moves = to_append;
	else
		ft_lstadd_back(moves, to_append);
	return (1);
}

static void	exec_moves(t_stack **a, t_stack **b)
{
	t_list	*moves;
	t_list	*tmp_moves;
	char	*line;

	moves = NULL;
	line = get_next_line(0, 5, 0);
	while (line)
	{
		if (!is_move(line))
			send_error(a, b, &moves, line);
		if (!add_move(&moves, line))
			send_error(a, b, &moves, line);
		free(line);
		line = get_next_line(0, 5, 0);
	}
	get_next_line(0, 5, 1);
	tmp_moves = moves;
	while (moves)
	{
		exec_move(a, b, moves);
		moves = moves->next;
	}
	ft_lstclear(&tmp_moves, free);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	parse_data(&a, argv + 1);
	exec_moves(&a, &b);
	if (stack_sorted(a) && !(b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack_a(&a);
	free_stack_a(&b);
	return (0);
}
