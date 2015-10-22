#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

struct stat statbuf;
mode_t modes;
mode_t inodes;

int main()
{

    stat("alice.txt", &statbuf);
    modes = statbuf.st_mode;
    inodes = statbuf.st_ino;


    printf("Modes = %d\n", modes);
    printf("inodes = %d\n", inodes);
}