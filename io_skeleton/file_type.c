#include <err.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void file_type(char *filename)
{
    /*
     * 1. Take a good look at the stat(2) man-page to see what you need
     * to declare first.
     *
     * 2. Once you called stat and it works, you can check whether it
     * is a regular file or a directory.
     *
     */
    struct stat path_stat;
    stat(filename, &path_stat);
    if (S_ISREG(path_stat.st_mode))
            write(1, "The given file is a regular file!", 34);
    else
        write(1, "The given file is a directory!", 31);
    write(1, "\n", 1);

    
}

int main(int argc, char **argv)
{
    // TODO: Check that the number of arguments is equal to 2, exit otherwise.
    if (argc == 2)
        file_type(argv[1]);
    return 0;
}
