#include <stdio.h>
int str_to_int(char *str);

int main(int argc, char **argv)
{
	int m = str_to_int(argv[1]);
	if (m < 0)
		printf("error encountered");
	else
		printf("THe niumber s %i\n", m);
	return (0);
}
