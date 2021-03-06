/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:15:11 by lespinoz          #+#    #+#             */
/*   Updated: 2022/02/01 15:18:34 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_free_null(char **pt)
{
	if (*pt != NULL)
	{
		free(*pt);
		pt = NULL;
	}
}

static char	*join_line(int nl_index, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_index <= 0)
	{
		if (**buffer == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		res = *buffer;
		*buffer = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, nl_index, BUFFER_SIZE);
	res = *buffer;
	res[nl_index] = 0;
	*buffer = tmp;
	return (res);
}

static char	*read_line(int fd, char **buffer, char *aux)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, aux, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buffer));
		aux[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, aux);
		ft_free_null(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer[PATH_MAX];
	char		*aux;
	char		*line;

	if (BUFFER_SIZE < 0)
		return (NULL);
	if (fd < 0 || fd > PATH_MAX)
		return (NULL);
	aux = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (aux == NULL)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	line = read_line(fd, &buffer[fd], aux);
	ft_free_null(&aux);
	return (line);
}
