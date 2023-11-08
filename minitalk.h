/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:07 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/08 12:18:37 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

void		handle_errors(char *error_msg);
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			ft_isdigit(int c);

#endif