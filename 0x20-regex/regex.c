#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: string to check
 * @pattern: pattern to check agains
 *
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */

int regex_match(char const *str, char const *pattern)
{
	int verify_dot = 0, verify_star = 0;

	if (!str || !pattern)
		return (0);

	verify_dot = *str && (*str == *pattern || *pattern == '.');
	verify_star = *(pattern + 1) == '*';

	if (!*str && !verify_star)
		return (*pattern ? 0 : 1);

	if (verify_dot && verify_star)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (verify_dot && !verify_star)
		return (regex_match(str + 1, pattern + 1));
	else if (verify_star)
		return (regex_match(str, pattern + 2));

	return (0);
}
