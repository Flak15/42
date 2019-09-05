#include <string.h>

/*
 * Find the first occurrence of find in s, where the search is limited to the
 * first slen characters of s.
 */
// char *strnstr(const char *s, const char *find, size_t slen)
// {
// 	char c, sc;
// 	size_t len;
//
// 	if ((c = *find) != '\0')
//   {
//     find++;
// 		len = ft_strlen(find);
// 		do {
// 			do {
// 				if ((sc = *s++) == '\0' || slen-- < 1)
// 					return (NULL);
// 			} while (sc != c);
// 			if (len > slen)
// 				return (NULL);
// 		} while (ft_strncmp(s, find, len) != 0);
// 		s--;
// 	}
// 	return ((char *)s);
// }
