#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"

// from proc_info.h proc_info structure
// per-process state // proc_info.state contains states as integers. in xv6 we have these states for processes

enum procstate {
    UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE
};

struct proc_info {
    int pid;            // Process ID
    int memsize;          // process size
    int state;            // process state
    char name[16];        // process name
};


int
main(int argc, char *argv[]) {
    struct proc_info ptable[NPROC];
    struct proc_info *p;
    int err;

    err = proc_dump(NPROC * sizeof(struct proc_info), &ptable);
    if (err != 0)
        printf(1, "Error getting ptable");

    p = &ptable[0];

    while (p != &ptable[NPROC - 1]) {
        // I'm printing no UNUSED processes
        if (p->memsize > 0) {
            printf(1, "PID: %d    -    SIZE: %d    -    ", p->pid, p->memsize);
            switch (p->state) {
                case UNUSED:
                    printf(1, "STATE: %s ", "UNUSED");
                    break;
                case EMBRYO:
                    printf(1, "STATE: %s ", "EMBRYO");
                    break;
                case SLEEPING:
                    printf(1, "STATE: %s ", "SLEEPING");
                    break;
                case RUNNABLE:
                    printf(1, "STATE: %s ", "RUNNABLE");
                    break;
                case RUNNING:
                    printf(1, "STATE: %s ", "RUNNING");
                    break;
                case ZOMBIE:
                    printf(1, " %s ", "ZOMBIE");
                    break;
            }
            printf(1, "   -    NAME: %s \n", p->name);
        }
        p++;
    }

    exit();
}