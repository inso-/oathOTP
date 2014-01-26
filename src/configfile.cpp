#include <iostream>
#include <fstream>
#include "configfile.h"


Configfile::Configfile(std::string const file) : _file(file)
{
}

void Configfile::setConfig(std::string const &param)
{
  std::ofstream      file;

  file.open(_file.c_str());
  if (file.is_open())
  {
    file << param;
    file.close();
  }
}

std::string Configfile::getConfig(int i)
{
    std::fstream       file;
    std::string        ret;

    file.open(_file.c_str(),  std::ofstream::in);
    if (file.is_open())
    {
        while (i > 0)
        {
            file >> ret;
            i--;
        }
        file.close();
    }
    return ret;
}

void Configfile::delFile()
{
    remove(_file.c_str());
}
