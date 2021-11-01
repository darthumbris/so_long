char	*ft_strchr(const char *s, int c)
{
	while (c > 256)
		c -= 256;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
