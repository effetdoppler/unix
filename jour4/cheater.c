#include "cheater.h"

int execute(char executable[], int P[2])
{
    // TODO:
    // - Fork the current process
    // - Setup the pipes correctly for each process (dup stdout and close
    // correct ends of pipe)
    // - In one of the processes, execute the given game (using execvp)
    // - Return the PID of the process created
    pipe(P);
    if (fork())
    {
        int r;
        char buf[256];
        while ((r= read(P[0], buf, 256)))
        {
            dup(P[0]);
            close(P[0]);
        }
        return execvp(executable, buf);

    }

    return 0;
}

// function that compares two NULL terminated strings safely
int my_strcmp(const char ref_signal[], const char target_signal[])
{
    return strncmp(ref_signal, target_signal, strlen(ref_signal) + 1);
}

int string_to_signal(char signal[])
{
    // - Loop through the signals, if string matches, return the number of the
    // signal (signal_nb = index + 1)
    int index = 0;
    for(size_t i = 0; i < NB_SIGNALS; i++)
    {
        if (my_strcmp(signals[i], signal) == 0)
            return index+1;
        index++;
    }

    errx(1, "Signal %s Not recognized!", signal);
}

void read_until(int fd, char buf[], size_t buf_size, char delim)
{
    // - Read from fd into buffer character by character until buffer is filled
    // (error in this case) or the last read character is delim
    // - Don't forget to null terminate the buffer at the correct place
    ssize_t r;
    for (size_t i = 0; i < buf_size; i ++)
    {
        read(fd, buf[i], buf_size);
        if (i == buf_size-1 && buf[i] == delim)
            errx(1, "Error, your last character is %c", delim);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        errx(1, "Usage: %s [executable_name]", argv[0]);

    // TODO:
    // Create and initialize the pipes
    // Execute the game and get PID to be able to send the signals

    // Initialize buffer of size BUFF_SIZE
    printf("%d", string_to_signal(argv[1]));
    printf("\n");

    for (size_t i = 0; i < 100; i++)
    {
        // Read a signal string through the pipe
        // Get the signal number from the signal string
        // Send the signal to the correct process (using kill function)
    }

    // Wait until other process has finished

    return 0;
}
