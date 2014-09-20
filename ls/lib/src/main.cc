/*
 * mainls.cc
 * A simple practice program to implement the `ls` Unix command for the lulz.
 * Uses the boost filesystem module.
 */

#include "../inc/ls.hpp"
#include <iostream>

using namespace::std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Too few arguments\n";
        return 1;
    } else if (argc > 2) {
        cout << "Too many arguments\n";
        return 1;
    }

    ls lsobj(argv[1]);
    lsobj.print_directory_contents();
    return 0;
}

