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

//COLORS FUNCTIONS
void sky()
{
	printf("\x1b[30;106m");
}
void red () {
  printf("\x1b[1;31m");
}
void yellow() {
  printf("\x1b[1;33m");
}
void grey(){
	printf("\x1b[30;47m");
}
void reset () {
  printf("\x1b[0m");
}
void bold(){
	printf("\x1b[1m");
}
void green(){
	printf("\x1b[30;42m");
}
void error() {
	printf("\x1b[37;41m");
	printf("ERROR:");
}
void success(){
	printf("\x1b[37;42m");
	printf("SUCCESS:");
}
void warning(){
	yellow();
	printf("WARNING:");
}


//CENTRE PRINTING FUNCTION

void centreprint(char *s){

	int len = strlen(s);
	int x = 136;

	int sp = x - len;

	for (int i = 0; i < sp / 2; ++i)
	{

		printf(" ");
	}
	printf("%s", s);
	for (int i = 0; i < sp / 2; ++i)
	{
		printf(" ");
	}

}

void print_success(char *s){

	printf("\x1b[1;32m");
	printf("%s", s);
}

void print_error(char *s){
	printf("\x1b[1;31m");
	printf("%s", s);
}

void print_warning(char *s){
	printf("\x1b[1;93m");
	printf("%s", s);
}



