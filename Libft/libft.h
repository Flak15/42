#ifndef LIBFT_H
#define LIBFT_H

void	ft_bzero(void *b, size_t length);
void	*ft_memset(void *dst, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *restrict dst0, const void *restrict src0, size_t length);
void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *str, const char *append);
char	*ft_strncat(char *str, const char *append, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *p, int ch);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
#endif
