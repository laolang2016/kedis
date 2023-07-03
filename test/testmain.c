#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>

#include "kedis/util/log_util.h"
#include "test_klib_list.h"

static int suite_init(void) {
    return 0;
}

static int suite_clean(void) {
    return 0;
}

static CU_TestInfo tests_klib[] = {
    {"test_sayHello", test_sayHello},
    CU_TEST_INFO_NULL,
};

static CU_SuiteInfo tests_klib_suites[] = {
    {"tests_klib_suites", suite_init, suite_clean, NULL, NULL, tests_klib},
    CU_SUITE_INFO_NULL,
};

#define ADD_SUITE(suite)                            \
    if (CUE_SUCCESS != CU_register_suites(suite)) { \
        CU_cleanup_registry();                      \
        return CU_get_error();                      \
    }

int main() {
    kdeis_util_log_init();
    // CU_pSuite pSuite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    /* Register suites. */
    ADD_SUITE(tests_klib_suites);

    // basic
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // automated
    CU_list_tests_to_file();
    CU_automated_run_tests();

    /* Clean up registry and return */
    CU_cleanup_registry();

    zlog_fini();
    return CU_get_error();
}