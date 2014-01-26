#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <string>

class Configfile
{
public:
    Configfile(std::string const file);
    ~Configfile() {}

    void        setConfig(std::string const &);
    std::string getConfig(int i = 1);
    void        delFile();

private:
    std::string _file;
};

#endif // CONFIGFILE_H
