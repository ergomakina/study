#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
	FILE *fp = stdin;
	char buff[256];
	for (int i = 1; fgets(buff, 256, fp); i++)
	{
		printf("%d  %s", i, buff);
	}
}
