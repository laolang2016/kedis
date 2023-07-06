#include <stdio.h>

#include "kedis/klib/klib.h"
#include "kedis/util/log_util.h"

int main() {
    kdeis_util_log_init();
    log_trace("hello kedis");
    log_debug("hello kedis");
    log_info("hello kedis");
    log_warn("hello kedis");
    log_error("hello kedis");
    log_fatal("hello kedis");
    // printf("\n\nHello kedis.\n");
    return 0;
}