/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:22:15 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/21 14:40:06 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

static char	*ifvalid(const char *haystack, size_t k, size_t j)
{
	if (k == j && k != 0)
		return ((char *)(haystack));
	else
		return (NULL);
}

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	size_t	j;

	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack && len > j)
	{
		while (haystack[j] == needle[j] && len > j && needle[j])
			j++;
		if (needle[j] == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (ifvalid((char *)haystack, ft_strlen((char *)needle), j));
}

// int main(void)
// {
// 	char haystack[30] = "";
// 	char needle[10] = "";
// 	char * empty = (char*)"";
//    printf("%s\n", strnstr(haystack, "b", 9));

//    return(0);
// }