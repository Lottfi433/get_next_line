/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:23:30 by yazlaigi          #+#    #+#             */
/*   Updated: 2024/11/28 09:05:24 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*n_str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	n_str = malloc(ft_strlen(s1) + ft_strlen(s2)+ 1);
	if (n_str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		n_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		n_str[i + j] = s2[j];
		j++;
	}
	n_str[i + j] = '\0';
	free (s1);
	s1 = NULL;
	return (n_str);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*n_str;

	if (str == NULL)
		return (NULL); 
	i = 0;
	n_str = malloc (ft_strlen(str) + 1);
	if (n_str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

char	*ft_strchr(char *str, char c)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			s_len;
	char			*a;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (start >= s_len)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	a = malloc(len + 1);
	if (a == NULL)
		return (NULL);
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
