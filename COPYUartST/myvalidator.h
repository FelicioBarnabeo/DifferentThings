#ifndef MYVALIDATOR_H
#define MYVALIDATOR_H

#include <QValidator>

class MyValidator : public QValidator
{
public:
    enum class ValidateType{ HEX, DEC, OCT, BIN, ASCII};
    MyValidator() = default;
    explicit MyValidator(ValidateType type, int dataB);
    void setTypeState(ValidateType type){
        m_typeState = type;
    }
    ValidateType typeState() const
    {
        return m_typeState;
    }
    int lengthOfValidType() const;
    int formatNumber() const;

protected:
    State validate(QString &str, int &) const override;
private:
    ValidateType m_typeState = ValidateType::HEX;
    int m_dataBits = 8;
    State validateHex(const QString &str)   const;
    State validateDec(QString str)   const;
    State validateOct(QString str)   const;
    State validateBin(QString str)   const;
    State validateAscii(QString str) const;
};

#endif // MYVALIDATOR_H
