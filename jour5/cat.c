#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <err.h>
#define BUF_SIZE 256

 
void cat(char *file)
{
    struct stat path_stat;
    stat(file, &path_stat);
    if (!S_ISREG(path_stat.st_mode))
        errx(1, "file must be a regular file");
    ssize_t txt;
    char buf[BUF_SIZE];
    int fd;
    fd = open(file, O_RDONLY);
    txt = read(fd, buf, BUF_SIZE);
    write(STDOUT_FILENO, buf, txt);
    close(fd);
    write(1, "\n", 1);
}


int main(int argc, char **argv)
{
    if (argc==2)
        cat(argv[1]);
    return 0;
}
