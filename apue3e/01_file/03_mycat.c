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

#define	BUFFSIZE	4096

int main(void)
{
	int	read_len = -1;
	int	write_len = -1;
	char buf[BUFFSIZE] = {0};

    while (1)
    {
        read_len = read(STDIN_FILENO, buf, BUFFSIZE);
        if (read_len <= 0)
        {
            break;
        }

        write_len = write(STDOUT_FILENO, buf, read_len);
		if (read_len != write_len)
			perror("write error");
    }

	return 0;
}

