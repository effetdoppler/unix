#include <err.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 128

void my_puts(char *s)
{
    /*
     * Given a string s, print it on stdout.
     * However, remember the behaviour of puts(3),
     * since printing a string is not the only thing puts does.
    */
    while(*s != '\0')
    {
        write(1, s, 1);
        s++;
    }
    write(1, "\n", 1);

}

int main(void)
{
    /*
     * This main function is only here for you to briefly test your code.
     * You can hence do whatever you want with it.
     */
    my_puts("Bonjour");
    my_puts("au revoir");
    return 0;
}
