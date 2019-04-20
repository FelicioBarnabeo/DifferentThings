#include "myvalidator.h"
#include <QDebug>

MyValidator::MyValidator(ValidateType type, int dataB)
    : m_typeState (type)
    , m_dataBits (dataB)
{}

QValidator::State MyValidator::validate(QString &str, int &) const
{
    switch (m_typeState)
    {
    case ValidateType::HEX:
        return validateHex(str);
        break;
    case ValidateType::DEC:
        return validateDec(str);
        break;
    case ValidateType::OCT:
        return validateOct(str);
        break;
    case ValidateType::BIN:
        return validateBin(str);
        break;
    case ValidateType::ASCII:
        return validateAscii(str);
        break;
    default:
        break;
    }
    return QValidator::State::Invalid;
}

int MyValidator::lengthOfValidType() const
{
    switch (m_typeState) {
    case ValidateType::HEX:
        return 2;
        break;
    case ValidateType::DEC:
        return 3;
        break;
    case ValidateType::OCT:
        return 3;
        break;
    case ValidateType::BIN:
        return 8;
        break;
    case ValidateType::ASCII:
        return 3;
        break;
    default:
        break;
    }
    return 0;
}

QValidator::State MyValidator::validateHex(const QString &str) const
{
    bool ok = true;
    //qDebug()<<"ok = " << ok;
    int hex = str.toInt(&ok, 16);
    if(ok || str==""){
        if(str.length() <= 2)
            if(hex < (pow(2,m_dataBits)))
                return State::Acceptable;
    }
    else
        return State::Invalid;
    return QValidator::State::Invalid;;
}

QValidator::State MyValidator::validateDec(QString str) const
{
    bool ok = true;
    int dec = str.toInt(&ok, 10);
    if(ok || str==""){
        if(str.length() <= 3)
            if( dec < (pow(2,m_dataBits)))
                return State::Acceptable;
    }
    else
        return State::Invalid;
    return QValidator::State::Invalid;;
}
QValidator::State MyValidator::validateOct(QString str) const
{
    bool ok = true;
    int oct = str.toInt(&ok, 8);
    if(ok || str==""){
        if(str.length() <= 3)
            if( oct < (pow(2,m_dataBits)))
                return State::Acceptable;
    }
    else
        return State::Invalid;
    return QValidator::State::Invalid;;
}

QValidator::State MyValidator::validateBin(QString str) const
{
    bool ok = true;
    int bin = str.toInt(&ok, 2);
    if(ok || str==""){
        if( bin < (pow(2,m_dataBits)))
            if(str.length() <= m_dataBits)
                return State::Acceptable;
    }
    else
        return State::Invalid;
    return QValidator::State::Invalid;;
}

QValidator::State MyValidator::validateAscii(QString str) const
{
    bool ok = true;
    if(ok || str==""){
        if(str.length() <= 1)
            return State::Acceptable;
    }
    else
        return State::Invalid;
    return QValidator::State::Invalid;;
}
