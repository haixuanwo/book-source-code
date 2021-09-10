/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd = -1;
    int len = -1;
    int offset = -1;

    fd = creat("file.hole", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd < 0)
	{
	    perror("creat error");
        return -1;
    }

    len = write(fd, buf1, 10);
	if (10 != len)
    {
	    perror("buf1 write error");
        return -1;
    }
	/* offset now = 10 */

    // 产生空洞，文件大小包含空洞
    offset = lseek(fd, 16384, SEEK_SET);
    if (-1 == offset)
    {
	    perror("lseek error");
        return -1;
    }
	/* offset now = 16384 */

    len = write(fd, buf2, 10);
    if (10 != len)
    {
	    perror("buf2 write error");
        return -1;
    }
	/* offset now = 16394 */

	return 0;
}

