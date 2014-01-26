#include <string>
#include <sstream>
#include "accountconfigfile.h"

Accountconfigfile::Accountconfigfile(std::string name) : Configfile(name + ".conf")
{
}

std::string Accountconfigfile::makeSecret(std::string const &src)
{
//    std::string     dest;
//    unsigned int    size = src.size();

//    for (unsigned int i = 0; i <= size; ++i)
//        dest += src[i] ^ (42 + i * 2);
    return src;
}

std::string Accountconfigfile::getName()
{
    std::string name;
    std::istringstream     line(getConfig());

    line >> name;
    return name;
}

std::string Accountconfigfile::getSecretkey()
{
    std::string secret;
    std::istringstream     line(getConfig(2));

    line >> secret;
    return makeSecret(secret);
}

int Accountconfigfile::getnbDigit()
{
    int nb;
    std::istringstream     line(getConfig(3));

    line >> nb;
    return nb;
}

int Accountconfigfile::getTime()
{
    int time;
    std::istringstream     line(getConfig(4));

    line >> time;
    return time;
}

void        Accountconfigfile::setAccountConfig(std::string Name, std::string SecretKey,
                                                int nbdigit, int time)
{
    std::ostringstream oss;
    std::ostringstream oss2;

    oss << nbdigit;
    oss2 << time;

    setConfig(Name + " " + makeSecret(SecretKey) + " " + oss.str() + " " + oss2.str());
}
