#include <CUnit/Basic.h>

#include "kedis/klib/klib.h"
#include "kedis/util/log_util.h"

void test_sayHello(){
    dzlog_info("====> test klib list");
    CU_ASSERT_EQUAL(sayHello(), 3);
}
