/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:09:31 by jalbers           #+#    #+#             */
/*   Updated: 2023/10/18 20:05:27 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_next_line(char *str)
{
	char	*next_line;
	int		i;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] && (i == 0 || str[i - 1] != '\n'))
		i++;
	next_line = malloc((i + 1) * sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (str[i] && (i == 0 || str[i - 1] != '\n'))
	{
		next_line[i] = str[i];
		i++;
	}
	next_line[i] = '\0';
	return (next_line);
}

char	*get_remainder(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		i++;
	j = 0;
	while (str && str[i])
		str[j++] = str[i++];
	str[j] = '\0';
	if (str && !str[0])
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*read_str;
	char		*buffer;
	char		*next_line;
	int			bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !contains_newline(read_str))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		read_str = ft_str_join(read_str, buffer); 
	}
	free(buffer);
	next_line = extract_next_line(read_str);
	read_str = get_remainder(read_str);
	return (next_line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	// int		i = 0;

// 	printf("BUFER_SIZE: %i\n", BUFFER_SIZE);
// 	// printf("%s", get_next_line(0));
// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (str == NULL)
// 			break ;
// 		printf("%s", str);
// 		free (str);
// 		// i++;
// 	}
// 	return (0);
// }
