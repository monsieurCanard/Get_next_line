/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Monsieur_Canard <Monsieur_Canard@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:52:01 by Monsieur_Ca       #+#    #+#             */
/*   Updated: 2023/11/16 16:03:49 by Monsieur_Ca      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*ft_realloc(char *stock, int buffer_len)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc (sizeof(char) * (buffer_len + BUFFER_SIZE + 1));
	if (!new)
	{
		free (new);
		free (stock);
		return (NULL);
	}
	ft_bzero(new, (buffer_len + BUFFER_SIZE + 1));
	while (stock[i] != 0)
	{
		new[i] = stock[i];
		i++;
	}
	free (stock);
	return (new);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
