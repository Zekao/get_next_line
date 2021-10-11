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
char	*ft_check(char *memory, int fd);
char	*get_next_line(int fd);
int		ft_strchr(char *str, char c);
char	*ft_get_next(char *str);
char	*ft_strjoin(char *s1, char *s2, int i, int j);
char	*ft_get_line(char *str);
char	*ft_free(char *str);

#endif
