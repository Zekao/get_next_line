/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaugale <emaugale@students.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:23:14 by emaugale          #+#    #+#             */
/*   Updated: 2021/08/25 16:12:14 by emaugale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

size_t	ft_strlen(char const *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_modify_buffer(char *str, size_t n);
char	*ft_return(char *buffer, char *line);
int		ft_checknl(char *str);
size_t	ft_isnl(char const *str);
char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_free(char *str);

#endif
