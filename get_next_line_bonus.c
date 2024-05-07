/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:14:10 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/07 11:57:19 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_new_line(char *storage)
{
	char	*new_line;
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	ptr = search_char(storage, '\n');
	if (!search_char(storage, '\n'))
		len = count_len(storage);
	if (search_char(storage, '\n'))
		len = count_len(storage) + 1 - count_len(ptr);
	if (!storage)
		return (NULL);
	new_line = (char *)malloc(sizeof(char) * len + 1);
	if (!new_line)
		return (NULL);
	while (len > i)
	{
		new_line[i] = storage[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*clear_storage(char *storage)
{
	char	*new_storage;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != '\n' && storage[i] != '\0')
		i++;
	if (storage[i] == '\n')
		i++;
	if (storage[i] == '\0')
		return (ft_free(&storage), NULL);
	len = count_len(storage) - i;
	new_storage = (char *)malloc(sizeof(char) * len + 1);
	if (!new_storage)
		return (NULL);
	while (storage[i] != '\0')
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	ft_free(&storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024] = {NULL};
	char		*line;
	int			count;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&storage[fd]), NULL);
	count = 1;
	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (!search_char(storage[fd], '\n') && count != 0)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == (-1) || (count <= 0 && !storage[fd]))
			return (ft_free(&line), ft_free(&storage[fd]), NULL);
		line[count] = '\0';
		storage[fd] = join_str(storage[fd], line);
	}
	ft_free(&line);
	line = get_new_line(storage[fd]);
	storage[fd] = clear_storage(storage[fd]);
	return (line);
}
