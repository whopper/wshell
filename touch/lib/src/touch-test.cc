/*
 * touch-test.cc
 * A simple practice program to implement the `touch` Unix command.
 * Uses the boost library.
 * This file is a placeholder for the eventual wshell implementation, which
 * will handle command execution.
 */

#include "../inc/touch.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        touch touchobj();
    } else {
        touch touchobj(argv[1]);
    }
}
