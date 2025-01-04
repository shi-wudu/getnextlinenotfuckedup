/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:55:20 by marleand          #+#    #+#             */
/*   Updated: 2025/01/04 17:22:23 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			check;

	line = NULL;
	if ((fd < 0 && fd > FOPEN_MAX) || BUFFER_SIZE < 1)
		return (line);
	check = read(fd, buffer, BUFFER_SIZE);
	while (*buffer || check > 0)
	{
		line = fstrjoin(line, buffer);
		if (newline(buffer))
			break ;
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
			return (free(line), NULL);
	}
	return (line);
}

# include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("BUFFER SIZE: %i\n", BUFFER_SIZE);
	close(fd);
	return (0);
}