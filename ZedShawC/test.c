#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr,\
        "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__,\
        clean_errno(), ##__VA_ARGS__)

#define check(A, M, ...) if (!(A)) {\
        log_err(M, ##__VA_ARGS__); errno = 0; goto error;}


int dosomething() {
    return -1;
}

int main(int argc, char *argv[])
{

    int rc = dosomething();
    check(rc == 0, "Something went wrong");

    error:
        fprintf(stderr, "Seomthing went wrong");

}
