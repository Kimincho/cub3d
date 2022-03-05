/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:06:47 by minchoi           #+#    #+#             */
/*   Updated: 2022/03/05 20:47:31 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	in_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

size_t	count_w(char const *s, char *charset)
{
	size_t	n;
	int		i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (in_charset(charset, s[i]))
		{
			n++;
			while (s[i] && in_charset(charset, s[i]))
				i++;
		}
		else
			i++;
	}
	return (n);
}

static void	ft_strcpy(char *dest, char *s1, char *s2)
{
	while (s1 < s2)
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	*dest = 0;
}

char	**ft_free(char **s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

char	**ft_split_set(char *s, char *charset)
{
	char	**str;
	char	*tmp;
	size_t	i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (count_w(s, charset) + 1));
	if (!s || str == NULL)
		return (NULL);
	while (*s)
	{
		if (in_charset(charset, *s))
		{
			tmp = s;
			while (*s && in_charset(charset, *s))
				s++;
			str[i] = (char *)malloc((s - tmp) + 1);
			if (str[i] == NULL)
				return (ft_free(str));
			ft_strcpy(str[i++], tmp, s);
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
