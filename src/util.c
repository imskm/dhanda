#include <dhanda/dhanda.h>
#include <dhanda/util.h>

int get_line(char line[], int size)
{
	int i;
	char ch;

	i = 0;
	do
	{
		ch = getchar();
		line[i] = ch;
		++i;
	} while (ch != EOF && ch != '\n' && i < size - 1);

	if (ch == EOF)
		line[--i] = '\0';
	else
		line[i] = '\0';

	return i;
}

int
get_string(char line[], int size)
{
	int len;

	len = get_line(line, size);
	line[len - 1] = '\0';

	return len - 1;
}

