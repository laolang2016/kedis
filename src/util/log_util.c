#include "kedis/util/log_util.h"

#include <stdio.h>
#include <stdlib.h>

static FILE* fp = NULL;

void kdeis_util_log_init() {
    fp = fopen("./log.log", "ab");
    if (NULL != fp) {
        log_add_fp(fp, LOG_TRACE);
    }
}

void kdeis_util_log_fini() {
    if (NULL != fp) {
        fclose(fp);
    }
}