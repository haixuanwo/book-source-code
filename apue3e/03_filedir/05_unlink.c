/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int ret = -1;

    ret = open("tempfile", O_RDWR | O_CREAT);
	if (ret < 0)
    {
		perror("open error");
        return -1;
    }

	if (unlink("tempfile") < 0)
    {
		perror("unlink error");
        return -1;
    }

	printf("file unlinked\n");
	sleep(15);
	printf("done\n");

    return 0;
}

