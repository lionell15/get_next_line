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

#include "get_next_line.h"

static void	ft_free_null(char **pt)
{
	if (*pt != NULL)
	{
		free(*pt);
		pt = NULL;
	}
}

static char	*join_line(int nl_position, char **buffer)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (nl_position <= 0)
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
	tmp = ft_substr(*buffer, nl_position, BUFFER_SIZE);
	res = *buffer;
	res[nl_position] = 0;
	*buffer = tmp;
	return (res);
}

static char	*ft_read(int fd, char **buffer, char *read_return)
{
	ssize_t	bytes_read;
	char	*tmp;
	char	*nl;

	nl = ft_strchr(*buffer, '\n');
	tmp = NULL;
	bytes_read = 0;
	while (nl == NULL)
	{
		bytes_read = read(fd, read_return, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (join_line(bytes_read, buffer));
		read_return[bytes_read] = 0;
		tmp = ft_strjoin(*buffer, read_return);
		ft_free_null(buffer);
		*buffer = tmp;
		nl = ft_strchr(*buffer, '\n');
	}
	return (join_line(nl - *buffer + 1, buffer));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*aux;
	char		*line;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	aux = (char *)malloc(BUFFER_SIZE + 1);
	if (aux == NULL)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	line = ft_read(fd, &buffer, aux);
	ft_free_null(&aux);
	return (line);
}
