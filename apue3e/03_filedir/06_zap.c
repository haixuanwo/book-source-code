/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int fd = -1;
	struct stat	statbuf;
	struct timespec	times[2];

	for (int i = 1; i < argc; i++)
    {
        /* fetch current times */
		if (stat(argv[i], &statbuf) < 0)
        {
			perror("stat error");
			continue;
		}

        /* truncate */
        fd = open(argv[i], O_RDWR | O_TRUNC);
		if (fd < 0)
        {
			perror("open error");
			continue;
		}

		times[0] = statbuf.st_atim; // 访问时间
		times[1] = statbuf.st_mtim; // 修改时间

        /* reset times */
        if (futimens(fd, times) < 0)
        {
			perror("futimens error");
        }

		close(fd);
	}

    return 0;
}

