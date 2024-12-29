/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 19:35:31 by marleand          #+#    #+#             */
/*   Updated: 2024-12-17 19:35:31 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-29 17:22:13 by marleand          #+#    #+#             */
/*   Updated: 2024-12-29 17:22:13 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0|| BUFFER_SIZE < 1)
		return (line);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = fstrjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			newline(buffer);
			break;
		}
		buffer[0] = '\0';
	}
	return (line);
}

int	main()
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
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}