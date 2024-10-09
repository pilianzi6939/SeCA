#include "MobileNodeMsg_m.h"



MobileNodeMsg::MobileNodeMsg(const char *name, int kind) : ::omnetpp::cMessage(name, kind)
{

    for (int i = 0; i < 3000; i++) {
        this->dataArray[i] = 0;
    }
}

MobileNodeMsg::MobileNodeMsg(const MobileNodeMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MobileNodeMsg::~MobileNodeMsg()
{
}

MobileNodeMsg& MobileNodeMsg::operator=(const MobileNodeMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MobileNodeMsg::copy(const MobileNodeMsg& other)
{
    this->randomNumber = other.randomNumber;
    for (int i = 0; i < 3000; i++) {
        this->dataArray[i] = other.dataArray[i];
    }
}

void MobileNodeMsg::setRandomNumber(int randomNumber)
{
    this->randomNumber = randomNumber;
}

int MobileNodeMsg::getRandomNumber() const
{
    return this->randomNumber;
}

void MobileNodeMsg::setDataArray(int k, int dataArray)
{
    if (k < 0 || k >= 3000) throw omnetpp::cRuntimeError("Array index out of bounds");
    this->dataArray[k] = dataArray;
}

int MobileNodeMsg::getDataArray(int k) const
{
    if (k < 0 || k >= 3000) throw omnetpp::cRuntimeError("Array index out of bounds");
    return this->dataArray[k];
}
