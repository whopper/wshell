/*
 * ls.h
 * Header for ls.c
 */

#include "boost/filesystem.hpp"
#include "boost/regex.hpp"
#include <string>
#include <vector>

using namespace std;

class ls
{
    public:
        ls(string path);
        int print_directory_contents();

    protected:
        int get_directory_content_vector(string path);

    private:
        vector<string> contents;
};
