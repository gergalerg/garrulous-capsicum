#include <stdio.h>
#include <string.h>

int main() {
    char work_area[1024];
    char *work = "ednd";
    if (strncmp("end", work, 3) == 0) 
        printf("It is true");
    else {
        printf("It is false");
    }
}
