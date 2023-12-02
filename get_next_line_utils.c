/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:17:31 by momari            #+#    #+#             */
/*   Updated: 2023/12/02 12:28:20 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_search(char *str)
{
    int i;

    i = 0;
	if (!str)
		return (-1);
    while (str[i])
    {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char	*ft_strcpy(char *dst, char const *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		return (free(s1), s1 = NULL, ft_strdup((const char *)s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	n_str = (char *)malloc(s1_len + s2_len + 1 * sizeof(char));
	if (n_str == NULL)
		return (free(s1), s1 = NULL, NULL);
	ft_strcpy(n_str, s1, s1_len);
	ft_strcpy(n_str + s1_len, s2, s2_len);
	free(s1);
	s1 = NULL;
	return (n_str);
}
char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		s1_len;

	s1_len = ft_strlen(s1);
	ptr = (char *)ft_calloc(s1_len + 1, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, s1, s1_len);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*n_str;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start > len)
		n_str = (char *)malloc(len + 1);
	else
		n_str = (char *)malloc((s_len - start) + 1);
	if (n_str == NULL)
		return (NULL);
	ft_strcpy(n_str, s + start, len);
	return ((char *)n_str);
}