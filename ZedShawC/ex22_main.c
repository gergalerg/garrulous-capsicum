#include "ex22.h"
#include "debug.h"

const char *MY_NAME = "Greg A. Russell";

void scope_demo(int count)
{
    log_info("Count is: %d", count);

    if (count > 10) {
        int count = 100;   // bad! bugs!

        log_info("count in this scope is %d", count);
    }
    log_info("count is at exit: %d", count);

    count = 3000;

    log_info("Count after assign: %d", count);
}

int main(int argc, char const *argv[])
{
    // test out the AGE accessors
    log_info("My name: %s, age: %d", MY_NAME, get_age());

    set_age(100);

    log_info("My age is now %d", get_age());

    // test out the size extern
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();

    THE_SIZE = 0;

    log_info("The size is now: %d", THE_SIZE);
    print_size();

    // test the ratio function static
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(300.00));

    // test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("Count after calling scope_demo: %d", count);
    
    return 0;
}