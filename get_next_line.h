/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momari <momari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:50:43 by momari            #+#    #+#             */
/*   Updated: 2023/12/08 20:34:55 by momari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_search(char *str);
char	*ft_newbuffer(char *src);
char	*ft_createstr(char *src, char **string);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, char const *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int		ft_allocate(char **src);
int		ft_check(int fd);

#endif
