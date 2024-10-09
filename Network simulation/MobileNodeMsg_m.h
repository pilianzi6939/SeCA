
#ifndef __MOBILENODEMSG_M_H_
#define __MOBILENODEMSG_M_H_

#include <omnetpp.h>

using namespace omnetpp;

class MobileNodeMsg : public ::omnetpp::cMessage
{
  protected:
    int randomNumber;
    int dataArray[3000];

  private:
    void copy(const MobileNodeMsg& other);

  public:
    MobileNodeMsg(const char *name=nullptr, int kind=0);
    MobileNodeMsg(const MobileNodeMsg& other);
    virtual ~MobileNodeMsg();
    MobileNodeMsg& operator=(const MobileNodeMsg& other);
    virtual MobileNodeMsg *dup() const override {return new MobileNodeMsg(*this);}


    virtual void setRandomNumber(int randomNumber);
    virtual int getRandomNumber() const;

    virtual void setDataArray(int k, int dataArray);
    virtual int getDataArray(int k) const;
};

#endif // __MOBILENODEMSG_M_H_
