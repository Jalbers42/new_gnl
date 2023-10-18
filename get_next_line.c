/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/17 15:34:54 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_next_line(char *str)
{
    char    *next_line;
    int     i;

    if (!str || str[0] == '\0')
        return (NULL);
    i = 0;
    while (str && str[i] && str[i] != '\n')
        i++;
    next_line = malloc((i + 1) * sizeof(char));
    i = 0;
    while (str && str[i] && str[i] != '\n')
    {
        next_line[i] = str[i];
        i++;
    }
    next_line[i] = '\0';
    return (next_line);
}

char *get_remainder(char *str)
{
    int i;
    int j;
    
    i = 0;
    while (str && str[i] && str[i] != '\n')
        i++;
    if (str && str[i] == '\n')
        i++;
    j = 0;
    while (str && str[i])
        str[j++] = str[i++];
    str[j] = '\0';
    return (str); 
}

char *get_next_line(int fd)
{
    char        *buffer;
    static char *read_str;
    char        *next_line;
    int         bytes_read;
    
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    bytes_read = 1;
    while (bytes_read > 0 && !contains_newline(read_str))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        read_str = ft_str_join(read_str, buffer); 
    }
    free(buffer); 
    next_line = extract_next_line(read_str);
    read_str = get_remainder(read_str);
    return (next_line);
}

int	main(void)
{
    int     fd;
    char    *str;
    
    fd = open("test.txt", O_RDONLY);
    while (1)
    {
        str = get_next_line(fd);
        if (str == NULL)
            break;
        printf("%s\n", str);
        free (str);
    }
    return (0);
}