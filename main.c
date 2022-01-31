/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lespinoz <lespinoz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:48:23 by lespinoz          #+#    #+#             */
/*   Updated: 2022/01/31 13:48:00 by lespinoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# define TRUE 1
# define FALSE 0

int main(void)
{
	int		fd;
	int		i;
	char *line[4096];
	int		end;
	
	i = 1;
	end = FALSE;
	fd = open("a_machado.txt", O_RDONLY);
	while(end == FALSE)
	{
		line[fd] = get_next_line(fd);
		printf("%s", line[fd]);
		if (!line[fd])
			end = TRUE;
		free(line[fd]);
		i++;
	}
}
