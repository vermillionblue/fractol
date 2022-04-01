/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:59:33 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 03:46:43 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			len;
	char		*p;

	p = (char *)s;
	len = ft_strlen((char *)s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((p + len));
		len--;
	}
	return (NULL);
}

// int main () {
//   char		str2[] = "bonjour";
//   char *str;
// 		char *str3;

//   str = strrchr(str2, 'j');
// 		str3 = ft_strrchr(str2, 'j');
//   printf("%s:\n", str);
// 		printf("%s:\n", str3);
//   return(0);
// }