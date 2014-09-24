/*
 * cat-test.cc
 * A simple practice program to implement to `cat` Unix command.
 * Uses the boost library.
 * This file is a placeholder for the eventual wshell implementation, which
 * will handle command execution.
 */

#include "../inc/cat.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cat catobj;
        catobj.print_file_contents();
    } else {
        cat catobj(argv[1]);
        catobj.print_file_contents();
    }
}
