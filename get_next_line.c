/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:51:18 by anthony           #+#    #+#             */
/*   Updated: 2023/11/16 16:12:45 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stock(int fd, char *buffer)
{
	int				i;
	static int		index = 0;
	int				count_word;

	i = 0;
	while (index != -1)
	{
		count_word = ft_strlen(buffer);
		buffer = ft_realloc(buffer, count_word);
		index = read(fd, &buffer[count_word], BUFFER_SIZE);
		if (index == 0 && buffer[0] == 0)
		{
			free(buffer);
			return (NULL);
		}
		if (index == 0 || ft_strchr(buffer, '\n') == 1)
			break ;
		buffer = ft_realloc(buffer, count_word);
		i++;
	}
	if (index == -1)
		return (ft_free(buffer));
	return (buffer);
}

int	ft_place_cursor(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}

char	*ft_cpy_line(char *buffer, char *line)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*ft_strdup_custom(char *buffer, int cursor)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc (sizeof(char) * (ft_strlen(buffer) - cursor + 1));
	if (!new)
	{
		free (new);
		return (NULL);
	}
	while (buffer[cursor])
	{
		cursor++;
		new[i] = buffer[cursor];
		i++;
	}
	new[i] = '\0';
	free (buffer);
	return (new);
}

char	*get_next_line(int fd)
{	
	static char	*buffer;
	static int	cursor;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	buffer = ft_stock(fd, buffer);
	if (!buffer)
		return (ft_free(buffer));
	cursor = ft_place_cursor(buffer);
	line = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!line)
		return (ft_free(line));
	line = ft_cpy_line(buffer, line);
	buffer = ft_strdup_custom (buffer, cursor);
	return (line);
}
// int main(void)
// {
// 	char *s;

// 	while ((s = get_next_line(0)))
// 	{
// 		__builtin_printf("%s\n", s);
// 		free(s);
// 	}
// }