/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:43:17 by momari            #+#    #+#             */
/*   Updated: 2023/12/08 20:31:29 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_createstr(char *src, char **string)
{
	int		i;
	char	*str;

	i = 0;
	if (string || *string)
		free(*string);
	if (!src || src[0] == '\0')
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, src, i);
	return (str);
}

char	*ft_newbuffer(char *src)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	while (src[i + j])
		j++;
	str = (char *)malloc(j + 1 * sizeof(char));
	if (!str)
		return (free(src), src = NULL, NULL);
	ft_strcpy(str, src + i, j + 1);
	free(src);
	src = NULL;
	return (str);
}

int	ft_allocate(char **src)
{
	*src = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!*src)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	int			re;
	static char	*buffer[OPEN_MAX];
	char		*string;
	char		*return_str;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (ft_allocate(&string))
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	re = 1;
	while (re)
	{
		re = read(fd, string, BUFFER_SIZE);
		if (re == -1)
			return (free(string), free(buffer[fd]), buffer[fd] = NULL, NULL);
		string[re] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], string);
		if (!buffer[fd] || ft_search(string) != -1)
			break ;
	}
	return_str = ft_createstr(buffer[fd], &string);
	if (!return_str)
		return (free(buffer[fd]), buffer[fd] = NULL, NULL);
	buffer[fd] = ft_newbuffer(buffer[fd]);
	return (return_str);
}
