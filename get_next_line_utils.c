/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marleand <marleand@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 19:35:48 by marleand          #+#    #+#             */
/*   Updated: 2024-12-17 19:35:48 by marleand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlenl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*fstrjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	szofs1;
	size_t	szofs2;
	size_t	len;

	if (!s2)
		return (NULL);
	szofs1 = ft_strlenl(s1);
	szofs2 = ft_strlenl(s2);
	len = szofs1 + szofs2 + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (s1)
		ft_memmove(str, s1, szofs1);
	ft_memmove(str + szofs1, s2, szofs2);
	str[szofs1 + szofs2] = '\0';
	if (s1) // Free the old s1 if it exists
		free((char *)s1);
	return (str);
}

int newline(char *buffer)
{
    int j;
    int i;
    int flag;

    i = 0;
    j = 0;
    flag = 0;
    while(buffer[i])
    {
        if (flag == 0 && buffer[i] == '\n')
            flag = 1;
        else if (flag == 1)
            buffer[j++] = buffer[i];
        buffer[i++] = 0;
    }
    return (flag);
}