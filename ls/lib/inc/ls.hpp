/*
 * ls.h
 * Header for ls.c
 */

#include <string>
#include <vector>

using namespace std;

class ls
{
    public:
        ls(string path);
        int print_directory_contents();

    protected:
        int get_directory_content_vector();
        bool check_directory_exists();

    private:
        string directory;
        vector<string> contents;
        bool is_valid_path;
};
