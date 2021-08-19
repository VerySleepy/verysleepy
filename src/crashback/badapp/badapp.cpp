#include <stdio.h>
#include <stdlib.h>
#include "../client/crashback.h"

int *x = NULL;

void dosomething()
{
	*x = 4;
}

int main()
{
	cbStartup();

	dosomething();
	return 0;
}
