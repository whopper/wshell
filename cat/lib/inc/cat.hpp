/*
 * cat.h
 * Header for cat.cc
 */

#include <string>

using namespace std;

class cat
{
    public:
        cat();
        cat(string path);
        int print_file_contents();

    protected:
        int get_file_contents();
        bool check_file_exists();

    private:
        string filepath;
        string contents;
        bool is_valid_file;
};
