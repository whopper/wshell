/*
 * ls.cc
 * Implements the ls class.
 */

#include "../inc/ls.hpp"
#include "boost/filesystem.hpp"
#include "boost/regex.hpp"
#include <iostream>

using namespace std;
using namespace boost::filesystem;

ls::ls()
{
    directory = ".";
    is_valid_path = check_directory_exists();
    if (is_valid_path) {
        get_directory_content_vector();
    }
}

ls::ls(string path)
{
    directory = path;
    is_valid_path = check_directory_exists();
    if (is_valid_path) {
        get_directory_content_vector();
    }
}

int ls::print_directory_contents()
{
    if ( ! is_valid_path) {
        cout << "ls: cannot access " << directory << ": No such file or directory\n";
        return 0;
    }

    // Copy each item of the vector to stdout
    copy(contents.begin(), contents.end(), ostream_iterator<string>(std::cout, "\t"));
    cout << endl;
    return 1;
}

int ls::get_directory_content_vector()
{
    if ( ! is_valid_path) {
        return 0;
    }

    directory_iterator end_itr;

    // Iterate over files in directory
    for (directory_iterator itr(directory); itr != end_itr; ++itr) {
        string filename;
        string current_file = itr->path().string();

        static const boost::regex filename_regex(".*/(.*)$");
        boost::match_results<std::string::const_iterator> results;
        // Strip out absolute path
        if (boost::regex_match(current_file, results, filename_regex)) {
            filename = results[1];
        }

        // Add file to content vector
        contents.push_back(filename);
    }
}

bool ls::check_directory_exists()
{
    if (is_directory(directory)) {
        return true;
    } else {
        return false;
    }
}

