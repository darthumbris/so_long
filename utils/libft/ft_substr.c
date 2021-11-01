#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s)
	{
		i = 0;
		if (start >= ft_strlen(s))
			substr = ft_calloc(1, 1);
		if (len < ft_strlen(s) && start < ft_strlen(s))
			substr = malloc(sizeof(char) * len + 1);
		else if (start < ft_strlen(s))
			substr = malloc(sizeof(char) * ft_strlen(s) + 1);
		if (substr == 0)
			return (NULL);
		while (i < len && s[i] && start < ft_strlen(s))
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
