/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:01:54 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/07 11:52:57 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef MAX_FD
#  define MAX_FD 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int			search_newline(char *str);
size_t		count_len(char *str);
char		*search_char(char *str, int c);
char		*join_str(char *str1, char *str2);
char		*get_next_line(int fd);
char		*get_new_line(char *storage);
char		*clear_storage(char *storage);
void		ft_free(char **str);

#endif
