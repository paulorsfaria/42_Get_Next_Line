/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:16:40 by paulo-do          #+#    #+#             */
/*   Updated: 2023/11/06 14:53:04 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trim_stash(char *stash)
{
	char	*tempstash;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	tempstash = (char *)malloc(sizeof(char) *(ft_strlen(stash) - i));
	if (!tempstash)
		return (NULL);
	if (stash[i] == '\n')
		i++;
	j = 0;
	while (stash[i] != '\0')
	{
		tempstash[j] = stash[i];
		j++;
		i++;
	}
	tempstash[j] = '\0';
	return (tempstash);
}

char	*get_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line) 
		return (NULL);
	while (j <= i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	if (stash == NULL) 
	{
		stash = (char *)malloc(sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	something(fd, &stash);
	line = get_line(stash);
	if (!line || !*line)
	{
		ft_free(&stash);
		return (NULL);
	}
	temp = trim_stash(stash);
	ft_free(&stash);
	stash = temp;
	if(!stash || !*stash)
		ft_free(&stash);
	return (line);
}
int main(void)
{
	int file;
	char *pnt;
	int i = 1;
	file = open("test01", O_RDONLY);
	while ((pnt = get_next_line(file)))
	{
		printf("ptn %d: %s",i, pnt);
		i++;
		free(pnt);
	}
	close(file);
}