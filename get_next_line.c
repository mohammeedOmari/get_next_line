/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:52:35 by momari            #+#    #+#             */
/*   Updated: 2023/12/02 12:22:49 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*(unsigned char *)(s + n) = 0;
	}
}

char *ft_createstr(char *src)
{
    int     i;
    char    *str;
    
    i = 0;
    while (src[i] && src[i] != '\n')
        i++;
    if (src[i] == '\n')
        i++;
    str = (char *)ft_calloc(i + 1, sizeof(char));
    if (!str)
        return (NULL);
    ft_strcpy(str, src, i);
    return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
char *ft_newbuffer(char *src)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    j = 0;
    while(src[i] && src[i] != '\n')
        i++;
    if (src[i] == '\n')
        i++;
    while (src[i + j])
        j++;
    str = (char *)ft_calloc(j + 1, sizeof(char));
    if (!str)
        return (free(src),src = NULL, NULL);
    ft_strcpy(str, src + i, j + 1);
    free(src);
    src = NULL;
    return (str);
}

char *get_next_line(int fd)
{
    int         re;
    static char *buffer;
    char        string[BUFFER_SIZE + 1];
    char        *return_str;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || read(fd, 0, 0) == -1)
        return (free(buffer), buffer = NULL, NULL);
    re = 1;
    while (re)
    {
        re = read(fd, string, BUFFER_SIZE);
        if (re == -1)
            return (free(buffer), buffer = NULL, NULL);
        string[re] = '\0';
        buffer = ft_strjoin(buffer, string);
        if (!buffer || ft_search(string) != -1)
            break;
    }
    if (!buffer || buffer[0] == '\0')
        return (free(buffer), buffer = NULL, NULL);
    return_str = ft_createstr(buffer);
    buffer = ft_newbuffer(buffer);
    return (return_str);
}
