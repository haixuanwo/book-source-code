/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ret = -1;

	if (argc != 2)
    {
		perror("usage: a.out <pathname>");
        return -1;
    }

    ret = access(argv[1], R_OK);
	if (ret < 0)
	{
	    perror("access error");
        return -1;
    }
	else if (0 == ret)
    {
		printf("read access OK\n");
    }
    else
    {
        printf("cann't read access\n");
    }

    ret = open(argv[1], O_RDONLY);
	if (ret < 0)
    {
		perror("open error");
        return -1;
    }

    printf("open for reading OK\n");

    return 0;
}

