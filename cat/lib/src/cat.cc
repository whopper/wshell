/*
 * cat.cc
 * Implements the cat class.
 */

#include "../inc/cat.hpp"
#include "boost/filesystem.hpp"
#include "boost/regex.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace boost::filesystem;

cat::cat()
{
    filepath = "";
    is_valid_file = false;
}

cat::cat(string path)
{
    filepath = path;
    is_valid_file = check_file_exists();
    if (is_valid_file) {
        get_file_contents();
    }
}

int cat::print_file_contents()
{
    if (is_valid_file) {
        cout << contents << endl;
    } else {
        cout << "cat: " << filepath << " No such file or directory\n";
    }
}

int cat::get_file_contents()
{
    ifstream filestream(filepath.c_str());
    stringstream buffer;
    buffer << filestream.rdbuf();
    contents = buffer.str();
}

bool cat::check_file_exists()
{
    if (exists(filepath)) {
        return true;
    } else {
        return false;
    }
}
