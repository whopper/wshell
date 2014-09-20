/*
 * ls.cc
 * Implements the ls class.
 */

#include "../inc/ls.hpp"
#include <iostream>

using namespace std;
using namespace boost::filesystem;

ls::ls(string path)
{
    get_directory_content_vector(path);
}

int ls::get_directory_content_vector(string path)
{
    directory_iterator end_itr;

    // Iterate over files in directory
    for (directory_iterator itr(path); itr != end_itr; ++itr) {
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

int ls::print_directory_contents()
{
    // Copy each item of the vector to stdout
    copy(contents.begin(), contents.end(), ostream_iterator<string>(std::cout, " "));
}
