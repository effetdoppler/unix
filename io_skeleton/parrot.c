#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 256

void parrot(char *filename)
{
    /*
     * 1. Write the initial message onto stdout.
     *
     * 2. Read the user-input. Only consider the first character entered,
     * you can discard the rest.
     *
     * 3. Check that the given input is a number between 0 and 9, both
     * included.
     * If the input is not correct, use the warn(3) function and restart parrot.
     *
     * 4. Open the file at the path given in parameter.
     *
     * 5. Write the content of the file as many time as the number
     * the user entered previously.
     *
     */
    write(1, "Squuuuaaaaaawk! Hello human, give me a number!", 47);
    write(1, "\n", 1);
    ssize_t r;
    char buf[BUF_SIZE ];
    r = read(STDIN_FILENO, buf, BUF_SIZE);
    int t = atoi(buf);
    if (t == 0)
    {
        write(1, "Squuuuaaaaaawk! Hello human, give me a number!", 47);
        write(1, "\n", 1);
    }
    int fd = open(filename, O_RDONLY);
    ssize_t txt;
    txt = read(fd, buf, BUF_SIZE);
    for (ssize_t i = 0; i < t; i++)
    {
        write(STDOUT_FILENO, buf, txt);
    }
    close(fd);
    

}

int main(int argc, char **argv)
{
    // Check that the number of arguments given is equal to 2, exit otherwise.
    // Call parrot with the correct argument.
    if (argc == 2)
        parrot(argv[1]);
    return 0;
}
