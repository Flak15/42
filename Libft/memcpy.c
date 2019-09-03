void *memcpy(void *dst0, const void *src0, size_t length) //add "restricted"
{
  char *dst = dst0;
	const char *src = src0;
	size_t t;

  if (length == 0 || dst == src)
  		return (dst0);
  // if ((dst < src && dst + length > src) || 
	//     (src < dst && src + length > dst))
  //     return (0);
  while (length--)
      *dst++ = *src++;
  return (dst0);
}
