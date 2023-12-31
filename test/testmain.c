#include <stdio.h>

#include "cutest/CuTest.c"
#include "kedis/util/log_util.h"
#include "test_klib_list.h"

static void suite_add_klib_list(CuSuite *suite) {
    SUITE_ADD_TEST(suite, test_sayHello);
    SUITE_ADD_TEST(suite, test_sayHi);
}

static void suite_add_all(CuSuite *suite) {
    suite_add_klib_list(suite);
}

int main() {
    kdeis_util_log_init();
    log_info("hello kedis test");
    // 定义用于存储测试信息的字符串
    CuString *output = CuStringNew();

    // 新建测试套件
    CuSuite *suite = CuSuiteNew();
    // 把 test 方法加入到测试套件中
    suite_add_all(suite);
    // 运行测试套件
    CuSuiteRun(suite);
    // 把运行后的结果存入到 output 中
    CuSuiteDetails(suite, output);
    // 打印测试结果
    printf("%s\n", output->buffer);
    kdeis_util_log_fini();
    return suite->failCount;
}
