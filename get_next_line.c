/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:54:57 by lespinoz          #+#    #+#             */
/*   Updated: 2022/01/31 15:06:53 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd)
{
	char	*aux;
	int		bytesize;

	aux = malloc(BUFFER_SIZE + 1);
	if (!aux)
		return (NULL);
	bytesize = read(fd, aux, BUFFER_SIZE);
	if (bytesize < 0)
	{
		free(aux);
		return (NULL);
	}
	aux[bytesize] = '\0';
	return (aux);
}

static char	*ft_expand_buffer(char *buff, int fd)
{
	char	*newbuffer;
	int		newsize;
	char	*aux;

	aux = ft_read(fd);
	if (!aux)
		return (NULL);
	if (!aux[0])
	{
		free(aux);
		return (buff);
	}
	if (!buff)
		return (aux);
	newsize = ft_strlen(buff) + ft_strlen(aux);
	newbuffer = malloc(newsize + 1);
	if (!newbuffer)
		return (NULL);
	ft_strlcpy(newbuffer, buff, newsize + 1);
	ft_strlcat(newbuffer, aux, newsize + 1);
	free(buff);
	free(aux);
	return (newbuffer);
}

static char	*ft_reduce_buffer(char *buff, char *line)
{
	char	*newbuffer;
	int		line_size;

	if (!buff || !line)
		return (buff);
	line_size = ft_strlen(line);
	if ((int)ft_strlen(buff) == line_size)
	{
		free(buff);
		return (NULL);
	}
	newbuffer = ft_substr(buff, line_size, ft_strlen(buff) - line_size);
	free(buff);
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;
	size_t		size_buffer;

	line = NULL;
	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 0)
		return (NULL);
	if (ft_strchr(buffer[fd], '\n') == -1)
	{
		size_buffer = ft_strlen(buffer[fd]);
		buffer[fd] = ft_expand_buffer(buffer[fd], fd);
		if (size_buffer == ft_strlen(buffer[fd]) && buffer[fd])
			line = ft_substr(buffer[fd], 0, size_buffer);
	}
	if (!buffer[fd])
		return (NULL);
	if (!line && ft_strchr(buffer[fd], '\n') != -1)
		line = ft_substr(buffer[fd], 0, ft_strchr(buffer[fd], '\n') + 1);
	if (line)
	{
		buffer[fd] = ft_reduce_buffer(buffer[fd], line);
		return (line);
	}
	return (get_next_line(fd));
}
