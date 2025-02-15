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

int main(int argc, char *argv[])
{
	struct stat	buf;

	for (int i = 1; i < argc; i++)
    {
		printf("%s: ", argv[i]);

        if (stat(argv[i], &buf) < 0)
        {
			perror("stat error");
			continue;
		}

		printf("dev = %d/%d", major(buf.st_dev),  minor(buf.st_dev));

		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
			printf(" (%s) rdev = %d/%d",
					(S_ISCHR(buf.st_mode)) ? "character" : "block",
					major(buf.st_rdev), minor(buf.st_rdev));
		}
		printf("\n");
	}

	return 0;
}


