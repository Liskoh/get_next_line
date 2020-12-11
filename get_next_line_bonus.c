/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjordan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:27:32 by hjordan           #+#    #+#             */
/*   Updated: 2020/12/10 06:23:56 by hjordan          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_find_char(char *content, char c)
{
	int		i;

	i = -1;
	while (content[++i])
		if (content[i] == c)
			return (1);
	return (0);
}

static int			ft_try_free(char **s)
{
	if (s == NULL)
		return (FAILURE);
	free(*s);
	*s = NULL;
	return (FAILURE);
}

static int			ft_get_state(char **current, char **line, int read_len)
{
	int			len;
	int			i;
	char		*tempo;

	i = 0;
	len = 0;
	while ((*current)[i] && (*current)[i] != END_OF_LINE)
		i++;
	if ((*current)[i] == END_OF_LINE)
	{
		if (!(*line = ft_substr(*current, 0, i))
			|| !(tempo = ft_strdup(&(*current)[i + 1])))
			return (ft_try_free(current));
		ft_try_free(current);
		*current = tempo;
	}
	else
	{
		if (!(*line = ft_strdup(*current)))
			return (ft_try_free(current));
		ft_try_free(current);
		if (read_len == END_OF_FILE)
			return (END_OF_FILE);
	}
	return (LINE_READED);
}

int					get_next_line(int fd, char **line)
{
	int				read_len;
	char			buffer[BUFFER_SIZE + 1];
	static char		*array[MAX_FD];

	read_len = 0;
	if (fd < 0 || !BUFFER_SIZE || line == NULL || read(fd, buffer, 0) < 0)
		return (FAILURE);
	if (array[fd] == NULL)
		array[fd] = ft_strdup("");
	while (!ft_find_char(array[fd], END_OF_LINE)
		&& (read_len = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[read_len] = '\0';
		array[fd] = ft_join_and_free(array[fd], buffer);
	}
	if (read_len < 0)
	{
		free(array[fd]);
		return (FAILURE);
	}
	return (ft_get_state(&array[fd], line, read_len));
}
