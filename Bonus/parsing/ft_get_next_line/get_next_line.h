/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <aoueldma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:16:10 by aoueldma          #+#    #+#             */
/*   Updated: 2023/03/10 12:16:10 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*get_next_line(int fd);
int		ft_searche(char	*buf);
char	*ft_joint(char *left, char *buf);
char	*ft_line(char *left);
char	*ft_update_left(char *left);
int		ft_new_line_len(char *str);

#endif