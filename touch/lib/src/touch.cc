/*
 * touch.cc
 * Implements the touch class.
 */

#include "../inc/touch.hpp"
#include "boost/filesystem.hpp"
#include "boost/regex.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace boost::filesystem;

touch::touch()
{
    print_err("touch: missing file operand");
}

touch::touch(string path)
{
    filepath = path;

    try {
      if (!is_valid_base_dir()) {
        throw 2;
      }
    } catch (int e) {
      if (e == 2) {
        print_err("touch: cannot touch file: No such file or directory");
      }
    }

    if (check_file_exists()) {
      update_file_time();
    } else {
      create_file();
    }
}

int touch::create_file()
{
  ofstream newfile(filepath.c_str());
  newfile.close();

  if (exists(filepath)) {
    return 0;
  } else {
    return 2;
  }
}

int touch::update_file_time()
{
  path file_path(filepath);
  std::time_t n = std::time(0) ;
  boost::filesystem::last_write_time(filepath, n);
  std::time_t t = last_write_time(filepath) ;

  if(t == n) {
    return 0;
  } else {
    return 2;
  }
}

bool touch::check_file_exists()
{
    if (exists(filepath)) {
        return true;
    } else {
        return false;
    }
}

bool touch::is_valid_base_dir()
{
  boost::regex dirslash(".*/.*");
  if( !regex_match(filepath, dirslash)) {
    return true;
  }

  path base_dir = path(filepath).stem().string();
  if(exists(base_dir)) {
    return true;
  } else {
    return false;
  }
}

void touch::print_err(string msg)
{
  cout << msg << "\n";
}
