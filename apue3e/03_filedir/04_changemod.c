/**
 * @author Clark
 * @email haixuanwo_clark@hotmail.com
 * @date 2021-09-10
 */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    int ret = -1;
	struct stat	statbuf;

	/* turn on set-group-ID and turn off group-execute */
    ret = stat("foo", &statbuf);
    if (ret < 0)
	{
	    perror("stat error for foo");
        return -1;
    }

    ret = chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID);
	if (ret < 0)
    {
	    perror("chmod error for foo");
        return -1;
    }

	/* set absolute mode to "rw-r--r--" */
    ret = chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (ret < 0)
    {
	    perror("chmod error for bar");
        return -1;
    }

	return 0;
}

