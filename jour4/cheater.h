#ifndef CHEATER_H
#define CHEATER_H

#define _POSIX_C_SOURCE 200809l

#define NB_SIGNALS sizeof(signals) / sizeof(char *)
#define BUFF_SIZE 256

#include <err.h>
#include <fcntl.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

char *signals[] = {
    "SIGHUP",      "SIGINT",      "SIGQUIT",     "SIGILL",      "SIGTRAP",
    "SIGABRT",     "SIGBUS",      "SIGFPE",      "SIGKILL",     "SIGUSR1",
    "SIGSEGV",     "SIGUSR2",     "SIGPIPE",     "SIGALRM",     "SIGTERM",
    "SIGSTKFLT",   "SIGCHLD",     "SIGCONT",     "SIGSTOP",     "SIGTSTP",
    "SIGTTIN",     "SIGTTOU",     "SIGURG",      "SIGXCPU",     "SIGXFSZ",
    "SIGVTALRM",   "SIGPROF",     "SIGWINCH",    "SIGIO",       "SIGPWR",
    "SIGSYS",      "SIGWAITING",  "SIGLWP",      "SIGRTMIN",    "SIGRTMIN+1",
    "SIGRTMIN+2",  "SIGRTMIN+3",  "SIGRTMIN+4",  "SIGRTMIN+5",  "SIGRTMIN+6",
    "SIGRTMIN+7",  "SIGRTMIN+8",  "SIGRTMIN+9",  "SIGRTMIN+10", "SIGRTMIN+11",
    "SIGRTMIN+12", "SIGRTMIN+13", "SIGRTMIN+14", "SIGRTMIN+15", "SIGRTMAX-14",
    "SIGRTMAX-13", "SIGRTMAX-12", "SIGRTMAX-11", "SIGRTMAX-10", "SIGRTMAX-9",
    "SIGRTMAX-8",  "SIGRTMAX-7",  "SIGRTMAX-6",  "SIGRTMAX-5",  "SIGRTMAX-4",
    "SIGRTMAX-3",  "SIGRTMAX-2",  "SIGRTMAX-1",  "SIGRTMAX"
};

#endif
