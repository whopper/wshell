/*
 * touch.h
 * Header for touch.cc
 */

#include <string>

using namespace std;

class touch
{
    public:
        touch();
        touch(string path);

    protected:
        int create_file();
        int update_file_time();
        bool check_file_exists();
        bool is_valid_base_dir();
        void print_err(string msg);
    private:
        string filepath;
};
