/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <error.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int val = -1;

	if (argc != 2)
	{
	    perror("usage: a.out <descriptor#>");
        return -1;
    }

    // 获取文件描述符的mode
	if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		perror("fcntl error");

	switch (val & O_ACCMODE) {
	case O_RDONLY:
		printf("read only");
		break;

	case O_WRONLY:
		printf("write only");
		break;

	case O_RDWR:
		printf("read write");
		break;

	default:
		perror("unknown access mode");
	}

	if (val & O_APPEND)
		printf(", append");
	if (val & O_NONBLOCK)
		printf(", nonblocking");
	if (val & O_SYNC)
		printf(", synchronous writes");

	putchar('\n');

	return 0;
}

