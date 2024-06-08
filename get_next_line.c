/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo-do <paulo-do@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:16:40 by paulo-do          #+#    #+#             */
/*   Updated: 2023/11/10 15:10:01 by paulo-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trim_stash(char *stash)
{
	int		i;
	int		j;
	char	*temp_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	temp_stash = (char *)malloc(sizeof(char) *(ft_strlen(stash) - i + 1));
	if (!temp_stash)
		return (NULL);
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
		temp_stash[j++] = stash[i++];
	temp_stash[j] = '\0';
	free(stash);
	return (temp_stash);
}

char	*get_new_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_new_line(stash);
	stash = trim_stash(stash);
	return (line);
}

// int main(void)
// {
// 	int file;
// 	char *pnt;
// 	//int i = 1;
// 	file = open("TEST01", O_RDONLY);
// 	// while ((pnt = get_next_line(file)))
// 	// {
// 	// 	printf("ptn %d: %s",i, pnt);
// 	// 	i++;
// 	// 	free(pnt);
// 	// }
// 	pnt = get_next_line(file);
// 	//printf("%d", BUFFER_SIZE);
// 	//printf("ptn: %s", pnt);
// 	free(pnt);
// 	close(file);
// }
