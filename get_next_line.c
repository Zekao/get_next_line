/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:24:09 by emaugale          #+#    #+#             */
/*   Updated: 2021/08/25 16:27:49 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

void	ft_modify_buffer(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (n < BUFFER_SIZE)
	{
		str[i] = str[n];
		i++;
		n++;
	}
	while (i < BUFFER_SIZE)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_return(char *buffer, char *line)
{
	size_t	i;

	if (ft_isnl(buffer) != ft_strlen(buffer))
	{
		ft_modify_buffer(buffer, ft_isnl(buffer) + 1);
		if (ft_checknl(line) || ft_strlen(line))
			return (line);
	}
	else if (ft_isnl(buffer) == ft_strlen(buffer))
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buffer[i] = 0;
			i++;
		}
		if (ft_checknl(line) || ft_strlen(line))
			return (line);
	}
	return (ft_free(line));
}

char	*get_next_line(int fd)
{
	ssize_t		byte;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, buffer);
	if (!(line))
		return (ft_free(line));
	if (ft_isnl(buffer) != ft_strlen(buffer))
		return (ft_return(buffer, line));
	byte = BUFFER_SIZE;
	while (byte == BUFFER_SIZE && !ft_checknl(buffer))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (ft_free(line));
		buffer[byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!(line))
			return (ft_free(line));
		if (byte == BUFFER_SIZE)
			byte = ft_isnl(buffer);
	}
	return (ft_return(buffer, line));
}
