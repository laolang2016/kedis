#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import shutil


debug_dir = 'cmake-build-debug'
release_dir = 'cmake-build-release'


def linux_configure_release():
    command = 'cmake --preset=gnu-ninja-release'
    ret = os.system(command)
    return 0 == ret

def linux_run():
    command = 'cmake --build ' + release_dir + ' --target run'
    ret = os.system(command)
    return 0 == ret

def linux_configure_debug():
    command = 'cmake --preset=gnu-ninja-debug'
    ret = os.system(command)
    return 0 == ret

def linux_configure_build():
    command = 'cmake -S . -G Ninja -B build -DBUILD_TEST=on && cmake --build build'
    ret = os.system(command)
    if 0 != ret:
        print('configure failed')
        return False
    command = 'cmake --build build'
    ret = os.system(command)
    if 0 != ret:
        print('generate failed')
        return False
    return True

def linux_test():
    command = 'ctest --test-dir build'
    ret = os.system(command)
    return 0 == ret


def windows_configure_release():
    command = 'cmake --preset=tdm-release'
    ret = os.system(command)
    return 0 == ret

def windows_run():
    command = 'cmake --build ' + release_dir + ' --target run'
    ret = os.system(command)
    return 0 == ret

def windows_configure_build():
    command = 'cmake -S . -G Ninja -B build -DBUILD_TEST=on && cmake --build build'
    ret = os.system(command)
    if 0 != ret:
        print('configure failed')
        return False
    command = 'cmake --build build'
    ret = os.system(command)
    if 0 != ret:
        print('generate failed')
        return False
    return True

def windows_test():
    command = 'ctest --test-dir build'
    ret = os.system(command)
    return 0 == ret


def rmdir(build_dir):
    dir = os.getcwd() + os.path.sep + build_dir
    if os.path.exists(dir):
        shutil.rmtree(dir)


if __name__ == '__main__':
    run_type = sys.argv[1]

    platform_windows = False
    if sys.platform == 'win32':
        print('Windows ' + run_type)
        platform_windows = True
    elif sys.platform == 'linux':
        print('Linux ' + run_type)

    if 'run' == run_type:
        if platform_windows:
            if windows_configure_release():
                windows_run()
        else:
            if linux_configure_release():
                linux_run()

    if 'cleanall' == run_type:
        rmdir(debug_dir)
        rmdir(release_dir)
        rmdir('build')

    if 'test' == run_type:
        if platform_windows:
            if windows_configure_build():
                windows_test()
        else:
            if linux_configure_build():
                linux_test()