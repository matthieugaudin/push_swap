/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgaudin <mgaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:02:08 by mgaudin           #+#    #+#             */
/*   Updated: 2025/01/14 11:42:19 by mgaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
#define CHECKER_BONUS_H

# include "../libft/libft.h"

void	parse_data(t_list **a, char **argv, int argc);
void	send_error(t_list **a, char **args, int argc);
void	free_list_a(t_list **a);
void	free_tab(char **tab);

#endif /* CHECKER_BONUS_H */