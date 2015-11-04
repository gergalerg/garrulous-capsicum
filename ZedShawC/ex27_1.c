#undef NDEBUG
#include "debug.h"
#include <stdio.h>
#include <assert.h>

void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}


int safercopy(int from_len, char *from, int to_len, char *to)
{
    assert(from != NULL && to != NULL && "from and to can't be NULL");
    int i = 0;
    int max = from_len > to_len -1 ? to_len -1 : from_len;

    // to_len must have at least 1 byte
    if (from_len < 0 || to_len <= 0)
        return -1;

    for (i = 0; i < max; i++) {
        to[i] = from[i];
    }

    to[to_len -1] = '\0';

    return i;
}

int main(int argc, char const *argv[])
{
    char from[] = "0123456789";
    int from_len = sizeof(from);

    // notice that it's 7 chars + \0
    char to[] = "0123456";
    int to_len = sizeof(to);

    debug("Copying '%s: %d to '%s': '%d'", from, from_len, to, to_len);

    int rc = safercopy(from_len, from, to_len, to);
    check(rc > 0, "Failed to safercopy");
    check(to[to_len -1] == '\0', "String not terminated");

    debug("Result is %s:%d", to, to_len);


    return 0;
    error:
        return 1;

    return 0;
}