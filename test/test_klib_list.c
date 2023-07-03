#include "test_klib_list.h"

#include <CUnit/Basic.h>

#include "kedis/klib/klib.h"
#include "kedis/util/log_util.h"

void test_sayHello(CuTest *cuTest) {
    dzlog_info("====> test klib list");
    CuAssert(cuTest, "\ntest3 not pass", 1 == sayHello());
}
