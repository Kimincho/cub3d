/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:15:03 by wleite            #+#    #+#             */
/*   Updated: 2022/02/24 14:27:06 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*extract_line(char **buffer_backup)
{
	int		i;
	char	*line;
	char	*temp_free;

	i = 0;
	while ((*buffer_backup)[i] != '\0' && (*buffer_backup)[i] != '\n')
		i++;
	temp_free = *buffer_backup;
	line = ft_substr(temp_free, 0, i + 1);
	*buffer_backup = ft_strdup(&(*buffer_backup)[i + 1]);
	free_ptr(&temp_free);
	return (line);
}

static int	read_file(int fd, char **buffer, char **buffer_backup)
{
	int		bytes_read;
	char	*temp_free;

	bytes_read = 1;
	while (!ft_strchr(*buffer_backup, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFSIZ);
		if (bytes_read == -1)
			return (bytes_read);
		(*buffer)[bytes_read] = '\0';
		temp_free = *buffer_backup;
		*buffer_backup = ft_strjoin(temp_free, *buffer);
		free_ptr(&temp_free);
	}
	return (bytes_read);
}

static char	*get_line(int fd, char **buffer, char **buffer_backup)
{
	int		bytes_read;
	char	*temp_free;

	if (ft_strchr(*buffer_backup, '\n'))
		return (extract_line(buffer_backup));
	bytes_read = read_file(fd, buffer, buffer_backup);
	if ((bytes_read == 0 || bytes_read == -1) && !**buffer_backup)
	{
		free_ptr(buffer_backup);
		return (NULL);
	}
	if (ft_strchr(*buffer_backup, '\n'))
		return (extract_line(buffer_backup));
	if (!ft_strchr(*buffer_backup, '\n') && **buffer_backup)
	{
		temp_free = ft_strdup(*buffer_backup);
		free_ptr(buffer_backup);
		return (temp_free);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char		*buffer_backup[OPEN_MAX + 1];
	char			*buffer;
	char			*result;

	if (fd < 0 || BUFSIZ <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFSIZ + 1);
	if (!buffer)
		return (NULL);
	if (!buffer_backup[fd])
		buffer_backup[fd] = ft_strdup("");
	result = get_line(fd, &buffer, &buffer_backup[fd]);
	free_ptr(&buffer);
	return (result);
}
