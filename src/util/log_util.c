#include "kedis/util/log_util.h"

#include <stdio.h>
#include <stdlib.h>

void kdeis_util_log_init() {
    int rc;
    rc = dzlog_init("zlog.conf", "my_cat");

    if (rc) {
        printf("zlog 初始化失败\n");
        zlog_fini();
        exit(EXIT_FAILURE);
    }
}