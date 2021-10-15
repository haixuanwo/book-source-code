/**
 * @author Clark
 * @email haixuanwoTxh@gmail.com
 * @date 2021-10-15
 */

#include <stdio.h>

class Trace
{
public:
    Trace()
    {
        noisy = 0;
        f = stdout;
    }

    Trace(FILE* ff)
    {
        noisy = 0;
        f = ff;
    }

    void print(const char *s)
    {
        if (noisy)
            fprintf(f, "%s", s);
    }

    void on()
    {
        noisy = 1;
    }

    void off()
    {
        noisy = 0;
    }

private:
    int noisy;
    FILE* f;
};

static void test1()
{
    Trace T;
    T.print("tan xiao hai\n");

    T.on();
    T.print("tan hui fang\n");

    T.off();
    T.print("tan heng\n");
}

static void test2()
{
    Trace T(stderr);
    T.on();
    T.print("tan xiao hai\n");

    T.off();
    T.print("tan hui fang\n");

    T.on();
    T.print("tan heng\n");
}

int main(int argc, char *argv[])
{
    //test1();
    test2();
    return 0;
}

