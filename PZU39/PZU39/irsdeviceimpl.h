#ifndef IRSDEVICEIMPL_H
#define IRSDEVICEIMPL_H


class IRSDeviceImpl
{
public:
    virtual ~IRSDeviceImpl();
    virtual void turnOnSD;
    virtual void turnOffSD;
    virtual void turnOnEthD;
    virtual void turnOffEthD;
};

#endif // IRSDEVICEIMPL_H
