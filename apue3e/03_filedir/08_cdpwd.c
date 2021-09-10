/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(void)
{
	char *ptr = NULL;
	size_t size = MAX_SIZE;

	if (chdir("/tmp") < 0)
	{
	    perror("chdir failed");
        return -1;
    }

	ptr = malloc(size);	/* our own function */
	if (getcwd(ptr, size) == NULL)
		perror("getcwd failed");

	printf("cwd = %s\n", ptr);

    return 0;
}

