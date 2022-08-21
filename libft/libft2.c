#include "push_swap.h"
bool ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 == *s2)
    {
        if (*s1 == '\0' && *s2 == '\0')
            return (true);
        s1++;
        s2++;
    }
	return (false);
}