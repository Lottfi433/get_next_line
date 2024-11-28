/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazlaigi <yazlaigi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:23:11 by yazlaigi          #+#    #+#             */
/*   Updated: 2024/11/28 09:12:34 by yazlaigi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_extract(char *hold)
{
	int	i;

	i = 0;
	while (hold[i] != '\0' && hold[i] != '\n')
		i++;
	if (hold[i] == '\n')
		i++;
	return (ft_substr(hold, 0, i));	
}

char	*updated_hold(char *hold)
{
	int		i;
	char	*n_hold;

	i = 0;
	while (hold[i] != '\n' && hold[i] != '\0')
		i++;
	if (hold[i] == '\0')
	{
		free(hold);
		return (NULL);
	}
	n_hold = ft_strdup(&hold[i + 1]);
	if (n_hold == NULL)
	{
		free(hold);
		return (NULL);
	}
	free(hold);
	return (n_hold);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*hold;
	int			byte_read;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((byte_read = read(fd, buffer,BUFFER_SIZE)) > 0)
	{
		buffer[byte_read] = '\0';
		if (hold == NULL)
			hold = ft_strdup("");
		tmp = ft_strjoin(hold,buffer);
		if (tmp == NULL)
			free (tmp);
		hold = tmp;
		if (ft_strchr(hold, '\n') != NULL)
			break;
	}
	if (byte_read < 0 || hold == NULL || hold[0] == '\0')
		return (NULL);
	line = line_extract(hold);
	hold = updated_hold(hold);
	return (line);
}

// int main()
// {
	
// 	int fd = open("my_file", O_RDONLY); 
// 	char *line;
// 		line = get_next_line(fd);
// 		printf("%s\n", line);
// 		line = get_next_line(fd);
// 		printf("%s\n", line);
// 		line = get_next_line(fd);
// 		printf("%s\n", line);

// 	close(fd);  
// 	return 0;
// }