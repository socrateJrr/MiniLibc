// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *original = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return original;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *original = destination;
	size_t i = 0;
	while (i < len)
	{
		if (*source != '\0')
		{
			*destination = *source;
			source++;
		}
		else
			*destination = '\0';
		destination++;
		i++;
	}
	while (i < len)
	{
		*destination = '\0';
		destination++;
		i++;
	}
	return original;
}

char *strcat(char *destination, const char *source)
{
	char *original = destination;
	while (*destination != '\0')
		destination++;
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
	return original;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *original = destination;
	size_t i = 0;
	while (*destination != '\0')
		destination++;
	while (i < len)
	{
		if (*source != '\0')
		{
			*destination = *source;
			source++;
		}
		else
			*destination = '\0';
		destination++;
		i++;
	}
	*destination = '\0';
	return original;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 < *str2)
			return -1;
		else
			return 1;
	}
	if (*str1 != '\0')
		return 1;
	if (*str2 != '\0')
		return -1;
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t i = 0;
	while (i < len)
	{
		if (*str1 != '\0' && *str2 != '\0')
			if (*str1 == *str2)
			{
				str1++;
				str2++;
			}
			else if (*str1 < *str2)
				return -1;
			else
				return 1;
		else
		{
			if (*str1 != '\0')
				return 1;
			if (*str2 != '\0')
				return -1;
		}
		i++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	char *adr;
	int ok = 0;
	while (*str != '\0' && ok == 0)
	{
		if (*str == c)
		{
			adr = str;
			ok = 1;
		}
		str++;
	}
	if (ok)
		return adr;
	else
		return NULL;
}

char *strrchr(const char *str, int c)
{
	char *adr;
	int ok = 0;
	while (*str != '\0')
	{
		if (*str == c)
			adr = str, ok = 1;
		str++;
	}
	if (ok)
		return adr;
	else
		return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	while (*haystack != '\0')
	{
		char *adr_hay = haystack;
		char *adr_need = needle;
		while (*adr_hay == *adr_need && *adr_hay != '\0' && *adr_need != '\0')
		{
			adr_hay++;
			adr_need++;
		}
		if (*adr_need == '\0')
			return haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	char *adr;
	int ok = 0;
	while (*haystack != '\0')
	{
		char *adr_hay = haystack;
		char *adr_need = needle;
		while (*adr_hay == *adr_need && *adr_hay != '\0' && *adr_need != '\0')
		{
			adr_hay++;
			adr_need++;
		}
		if (*adr_need == '\0')
			adr = haystack, ok = 1;
		haystack++;
	}
	if (ok)
		return adr;
	else
		return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	size_t i = 0;
	char *dest = destination;
	char *src = source;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	size_t i = 0;
	char *dest = destination;
	char *src = source;
	if (dest < src || dest > (src + num))
	{
		while (i < num)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{
		i = num - 1;
		while (i >= 0)
		{
			dest[i] = src[i];
			i--;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t i = 0;
	char *alt_ptr1 = ptr1;
	char *alt_ptr2 = ptr2;
	while (i < num)
	{
		if (alt_ptr1[i] < alt_ptr2[i])
			return -1;
		if (alt_ptr1[i] > alt_ptr2[i])
			return 1;
		i++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *src = source;
	char val = value;
	size_t i = 0;
	while (i < num)
		src[i] = val, i++;
	return source;
}