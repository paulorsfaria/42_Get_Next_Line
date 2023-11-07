/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:16:53 by paulo-do          #+#    #+#             */
/*   Updated: 2023/11/07 18:14:29 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin(char *stash, char *temp)
{
	int		i;
	int		j;
	char	*updated_stash;

	i = 0;
	j = 0;
	updated_stash = (char *)malloc(sizeof(char) * 
			((ft_strlen(stash) + ft_strlen(temp)) + 1));
	if (!updated_stash)
		return (NULL);
	while (stash[j] != '\0')
	{
		updated_stash[j] = stash[j];
		j++;
	}
	while (temp[i] != '\0')
		updated_stash[j++] = temp[i++];
	updated_stash[j] = '\0';
	return (updated_stash);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	checkenter(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n' || stash[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free(char **t)
{
	if (t && *t)
	{
		free(*t);
		*t = NULL;
	}
}

void	something(int fd, char **stash )
{
	char	*temp;
	char	*temp_stash;
	int		size;

	temp = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);// problems here when buffer 42 look into it
	if (!temp)
		return (ft_free(stash));
	size = 1;
	while (*stash && checkenter(*stash) == 0 && size > 0)
	{
		size = read(fd, temp, BUFFER_SIZE);
		if (size == -1)
		{
			ft_free(&temp);
			return (ft_free(stash));
		}
		temp[size] = '\0';
		temp_stash = strjoin(*stash, temp);
		ft_free(stash);
		*stash = temp_stash;
	}
	ft_free(&temp);
}
