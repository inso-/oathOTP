#ifndef OTP_H
#define OTP_H

#include <string>

class OTP
{
public:
    OTP(std::string const &, int = 0, int = 6);

    std::string hotp(int counter);
    std::string totp();
    std::string generate();
    void        setSecret(std::string const &secret) { _secret = secret ;}
    std::string getSecret() const { return _secret;}
    void        setCounter(int counter) { _counter = counter ;}
    int         getCounter() { return _counter;}
    std::string otp(std::string const &);

private:
    std::string     _secret;
    int             _counter;
    int             _nbDigit;
    unsigned char   *_base32;
};

#endif // OTP_H
