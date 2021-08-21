
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "01_random.h"

void show(int id)
{
    switch(id)
    {
        case 1:
            printf("I love you\n");
            break;
        case 2:
            printf("I hate you\n");
            break;
        case 3:
            printf("you are son of betch\n");
            break;
        case 4:
            printf("stay hugry, stay folish\n");
            break;
        case 5:
            printf("I'm the man who can do anything\n");
            break;
        default:
            printf("Do you want to fuck me!!!\n");
            break;
    }
}

int main(int argc, char *argv[])
{
    Random r;
    int min = 0;
    int max = 0;

    if (3 == argc)
    {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
        r.set_range(min, max);
    }

    while (1)
    {
        show(r.get_random());
        sleep(1);
    }

    return 0;
}

