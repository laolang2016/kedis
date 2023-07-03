#include <stdio.h>


#include "kedis/klib/klib.h"

#include "kedis/util/log_util.h"

int main(){
    kdeis_util_log_init();

    dzlog_info("k_list sayHello:%d",sayHello());
    printf("\n\nHello kedis.\n");
    zlog_fini();
    return 0;
}