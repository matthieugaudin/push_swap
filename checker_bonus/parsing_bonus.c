/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:13:07 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/15 10:54:09 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static long	ft_atol(const char *nptr)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		if ((res > 2147483647 || res < -2147483648)
			&& !(sign == -1 && res == 2147483648))
			return (2147483648);
		i++;
	}
	return (res * sign);
}

static int	handle_nbr(char *arg)
{
	int	i;
	int	nb_sign;

	i = 0;
	nb_sign = 0;
	while (arg[i] && (arg[i] == '-' || arg[i] == '+'))
	{
		nb_sign++;
		if (nb_sign > 1 || ft_strlen(arg) == 1)
			return (0);
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_doubles(t_stack *node)
{
	t_stack	*tmp;

	while (node)
	{
		tmp = node->next;
		while (tmp)
		{
			if (node->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}

static int	append_node(t_stack **a, int nb, int i)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (1);
	if (i == 0)
		*a = node;
	node->value = nb;
	node->pos = i;
	node->target = NULL;
	node->prev = NULL;
	if (i > 0)
	{
		node->prev = get_last(a);
		node->prev->next = node;
	}
	node->next = NULL;
	return (0);
}

void	parse_data(t_stack **a, char **argv, int argc)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (!handle_nbr(argv[i]))
			send_error(a, NULL, NULL, NULL);
		nb = ft_atol(argv[i]);
		if (nb == 2147483648)
			send_error(a, NULL, NULL, NULL);
		if (append_node(a, nb, i))
			send_error(a, NULL, NULL, NULL);
		i++;
	}
	if (!is_doubles(*a))
		send_error(a, NULL, NULL, NULL);
}
