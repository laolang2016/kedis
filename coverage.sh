#!/bin/bash
BUILD_PATH=cmake-build-debug

if [ -d BUILD_PATH ]; then
    rm -rf ${BUILD_PATH};
fi

cmake -S . -B ${BUILD_PATH} -DCMAKE_BUILD_TYPE=Debug -DGEN_COVERAGE=ON
cmake --build ${BUILD_PATH}
ctest --test-dir ${BUILD_PATH} -R test_all

lcov -d . -o ${BUILD_PATH}/app.info -b . -c --exclude '*/test/*' --exclude '*/third/*' --exclude '*/usr/*' --exclude '*/src/launch/*'
genhtml ${BUILD_PATH}/app.info -o ${BUILD_PATH}/lcov

cd ${BUILD_PATH}/lcov && serve

# cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug -DGEN_COVERAGE=ON && cmake --build cmake-build-debug
# ctest --test-dir cmake-build-debug -R test_all
