/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:28:27 by hjordan           #+#    #+#             */
/*   Updated: 2020/12/10 06:24:49 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define LINE_READED 1
# define END_OF_FILE 0
# define FAILURE -1
# define END_OF_LINE '\n'
# define MAX_FD 10240

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t				ft_strlen(const char *str);
char				*ft_join_and_free(char *s1, char *s2);
char				*ft_strdup(char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					get_next_line(int fd, char **line);

#endif
