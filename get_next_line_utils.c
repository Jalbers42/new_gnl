/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbers <jalbers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/10/17 14:37:41 by jalbers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_str_len(char *str)
{
    int i;
    
    i = 0;
    while (str && str[i])
        i++;
    return (i);
}

int contains_newline(char *str)
{
    int i;

    i = 0;
    while (str && str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
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
    while (str2 && str2[j])
        new_str[i++] = str2[j++];
    new_str[i] = '\0';
    if (str1)
        free(str1);
    return (new_str);
}