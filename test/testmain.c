#include <stdio.h>

#include "cutest/CuTest.c"
#include "test_klib_list.h"

static void suite_add_klib_list(CuSuite *suite) {
    SUITE_ADD_TEST(suite, test_sayHello);
}

static void suite_add_all(CuSuite *suite) {
    suite_add_klib_list(suite);
}

int main() {
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
    return 0;
}
