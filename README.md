## Add system call to xv6

In this project i tried to add a system call named proc_dump
which returns an array of processes information
and test it's functionality with a user program called ps (in ps.c file)


you can see all the steps required in a pdf file in
[this link](https://github.com/sinaziaee/xv6-add-ps-system-call/blob/master/xv6-add-system-call.pdf)

files that were modified or added are listed below: (listed by the order of modification)

- proc_info.h (added)
- syscall.h (modified)
- syscall.c (modified)
- usys.S (modified)
- user.h (modified)
- proc.c (modified)
- ps.c
- Makefile
