/*
 * test-ls.cc
 * A simple practice program to implement the `ls` Unix command for the lulz.
 * Uses the boost filesystem module.
 * This file is a placeholder for the eventual wshell implementation, which
 * will handle command execution.
 */

#include "../inc/ls.hpp"

using namespace::std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        ls lsobj(".");
        lsobj.print_directory_contents();
    } else {
        ls lsobj(argv[1]);
        lsobj.print_directory_contents();
    }

    return 0;
}

