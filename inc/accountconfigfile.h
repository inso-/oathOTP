#ifndef ACCOUNTCONFIGFILE_H
#define ACCOUNTCONFIGFILE_H

#include "configfile.h"

class Accountconfigfile : public Configfile
{
public:
    Accountconfigfile(std::string);

    std::string getName();
    std::string getSecretkey();
    int         getnbDigit();
    int         getTime();

    void        setAccountConfig(std::string Name, std::string key, int nbDigit, int time);

 private:
    std::string makeSecret(std::string const &src);
};
#endif // ACCOUNTCONFIGFILE_H
