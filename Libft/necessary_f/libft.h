#ifndef LIBFT_H
#define LIBFT_H

void  bzero(void *b, size_t length);
void *memset(void *dst, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
void *memcpy(void *restrict dst0, const void *restrict src0, size_t length);
void *memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
void *memmove(void *dst, const void *src, size_t len);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *s);
char *strdup(const char *s);
char *strcpy(char *dest, const char *src);
char *ft_strncpy(char *dest, const char *src, size_t n);
char *strcat(char *str, const char *append);
char *strncat(char *str, const char *append, size_t n);
size_t strlcat(char *dest, const char *src, size_t size);
char *strchr(const char *p, int ch);
#endif
