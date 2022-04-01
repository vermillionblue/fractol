/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:11:57 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/14 18:36:14 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	alloc_strns(char const *s, char	**arr, char c)
{
	int	k;
	int	sec;
	int	f;

	k = 0;
	sec = 0;
	f = 0;
	while (s[k])
	{
		sec = 0;
		if (s[k] != c && s[k])
		{
			while (s[k] != c && s[k])
			{
				k++;
				sec++;
			}
			arr[f] = (char *)malloc((sec + 1) * (sizeof(char )));
			f++;
		}
		else
			k++;
	}
}

static size_t	count_strns(const char *s, char c)
{
	size_t	k;
	size_t	f;

	k = 0;
	f = 0;
	while (s[k])
	{
		if (s[k] != c && s[k] != '\0')
		{
			while (s[k] != c && s[k])
				k++;
			f++;
		}
		else
			k++;
	}
	return (f);
}

static void	char_insert(char const *s, char **arr, char c)
{
	size_t	k;
	size_t	sec;
	size_t	f;

	f = 0;
	k = 0;
	sec = 0;
	while (s[k])
	{
		sec = 0;
		if (s[k] != c && s[k])
		{
			while (s[k] != c && s[k])
			{
				arr[f][sec] = s[k];
				sec++;
				k++;
			}
			arr[f][sec] = '\0';
			f++;
		}
		else
			k++;
	}
	arr[f] = 0;
}

char	**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		num_strns;
	char		set[1];

	if (!s)
		return (NULL);
	set[0] = c;
	s = ft_strtrim(s, set);
	if (!s)
		return (NULL);
	num_strns = count_strns(s, c);
	arr = (char **)malloc((num_strns + 1) * (sizeof(char *)));
	if (!arr)
		return (0);
	alloc_strns(s, arr, c);
	char_insert(s, arr, c);
	free((char *)s);
	return (arr);
}

// int main(void)
// {
// 	int n = 0;
// 	char *s = "      split       this for   me  !       ";

// 	char **result = ft_split(s, ' ');
// 		while (result[n])
// 		{
// 			printf("%s\n", result[n]);
// 			n++;
// 		}
// 		if (result[n] == NULL)
// 			printf("null\n");
//    return(0);
// }