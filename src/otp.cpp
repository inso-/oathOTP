#include <QMessageAuthenticationCode>
#include <QCryptographicHash>
#include <QString>
#include <ctime>
#include <sstream>
#include <fstream>
#include <QDebug>
#include "otp.h"
#include "base32.h"

#include <qdebug.h>

OTP::OTP(std::string const &secret, int counter, int nbDigit)
    : _secret((secret)),
      _counter(counter),
      _nbDigit(nbDigit)
{
    unsigned char *tmp = (unsigned char*)malloc(sizeof(unsigned char) * secret.length());

    _base32 = (unsigned char*)(_secret.c_str());
    base32_decode(_base32, tmp, secret.length());
    _base32 = tmp;
}

std::string
OTP::generate()
{
    return totp();
}

std::string
OTP::otp(std::string const & hmacHex)
{
    unsigned char               DBC1[4], DBC2[4];
    std::string                 DBC2Hex;;
    unsigned int                otp;
    std::stringstream           ss;
    std::ostringstream          oss;
    std::string                 hmac = (QByteArray::fromHex(hmacHex.c_str())).data();
    int                         offset = *(hmac.substr(hmac.length() - 1)).c_str() & 15; // last octet & 00001111 for get offset
    int                         divisor = 1;

    for (int i = 0; i < _nbDigit; ++i)
        divisor *= 10;
    // DBC1 traitment
    for (int i = 0; i <= 3; i++)
        DBC1[i] = (unsigned char)hmac[offset + i];
    // DBC2 traitment
    DBC2[0] = DBC1[0] & 0x7f;
    DBC2[1] = DBC1[1] & 0xff;
    DBC2[2] = DBC1[2] & 0xff;
    DBC2[3] = DBC1[3] & 0xff;
    for (int i = 0; i <= 3; i++)
        DBC2Hex += QByteArray((char*)&DBC2[i], 1).toHex().data();
    // get otp result in decimal
    ss << DBC2Hex.c_str();
    ss >> std::hex >> otp;
    qDebug() << otp;
    oss << otp  % divisor;  //% divisor (nb digit selection)
    return (QString(oss.str().c_str()).rightJustified(_nbDigit, '0').toStdString());
}

std::string
OTP::hotp(int counter)
{
    QMessageAuthenticationCode  code(QCryptographicHash::Sha1); //HMAC SHA1 QT
    QByteArray                  hashmac, secretHex, counterHex, secret;
    std::string                 hashmacHex;

    if (_secret.length() >= 32)
        secret = QByteArray::fromRawData((char*)_base32, _secret.length() - 12);
    else if (_secret.length() >= 16)
        secret = QByteArray::fromRawData((char*)_base32, _secret.length() - 6);
    else
        secret = QByteArray::fromRawData((char*)_base32, _secret.length());
    secretHex = secret.toHex();
    counterHex = QString::number(counter, 16).rightJustified(16, '0').toStdString().c_str();
    code.setKey(QByteArray::fromHex(secretHex));
    code.addData(QByteArray::fromHex(counterHex));
    hashmac = code.result();
    hashmacHex = hashmac.toHex().data();
    qDebug() << "counter" << _counter;
    qDebug() << "time" << counter;
    qDebug() << "timeHex" << counterHex;
    qDebug() << "secret " << _secret.c_str();
    qDebug() << "";
    qDebug() << "secret decode" << secret;
    qDebug() << "";
    qDebug() << "secretHex" << secretHex.data();
    qDebug() << "hasMac" << hashmac.data();
    qDebug() << "hasMacHex" << hashmacHex.data();
    return otp(hashmacHex);
}

std::string
OTP::totp()
{
    std::time_t t = std::time(0); // Totp is a hotp(Key, Time / counter)
    if (_counter != 0)
        return (hotp(t / _counter));
    return (hotp(t / 30));
}
