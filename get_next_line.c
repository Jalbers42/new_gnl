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

int ft_str_len(char *str)
{
    int i;
    
    if (!str) 
        return (0);
    while (str[i])
        i++;
    return (i);
}

char *ft_str_join(char *str1, char *str2)
{
    char    *new_str;
    int     i;
    int     j;

    new_str = malloc((ft_str_len(str1) + ft_str_len(str2) + 1) * sizeof(char));
    i = 0;
    while (str1 && str1[i])
    {
        new_str[i] = str1[i];
        i++; 
    }
    j = 0;
    while (str2[j])
        new_str[i++] = str2[j++];
    new_str[i] = '\0';
    if (str1)
        free(str1);
    return (new_str);
}

char *get_next_line(int fd)
{
    char        *buffer;
    static char *final_str;
    int         bytes_read;
    
    final_str = NULL;
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        final_str = ft_str_join(final_str, buffer); 
    }
    free(buffer); 
    return (final_str);
}

int	main(void)
{
    int fd;
    // int i;
    
    fd = open("test.txt", O_RDONLY);
    // get_next_line(fd);
        printf("%s\n", get_next_line(fd));
    // i = 0;
    // while (i < 1)
    // {
    //     i++;
    // }
    return (0);
}