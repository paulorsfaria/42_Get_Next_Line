/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:16:53 by paulo-do          #+#    #+#             */
/*   Updated: 2023/11/10 15:02:14 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*strjoin(char *stash, char *temp)
{
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	j = 0;
	if (!stash)
	{
		stash = malloc(sizeof(char));
		stash[0] = '\0';
	}
	temp_stash = (char *)malloc(sizeof(char) * 
			((ft_strlen(stash) + ft_strlen(temp)) + 1));
	if (!stash)
		return (NULL);
	while (stash[i] != '\0')
	{
		temp_stash[i] = stash[i];
		i++;
	}
	while (temp[j] != '\0')
		temp_stash[i++] = temp[j++];
	free (stash);
	temp_stash[i] = '\0';
	return (temp_stash);
}

int	checkenter(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n' || stash[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *stash )
{
	int		size;
	char	*temp;

	size = 1;
	while (checkenter(stash) == 0 && size != 0)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
		{
			free(stash);
			free(temp);
			return (NULL);
		}
		temp[size] = '\0';
		if (!temp)
			return (NULL);
		stash = strjoin(stash, temp);
		free(temp);
	}
	return (stash);
}
