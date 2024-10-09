#ifndef BASESTATION_H_
#define BASESTATION_H_

#include <omnetpp.h>
#include "MobileNodeMsg_m.h"

using namespace omnetpp;

class BaseStation : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif /* BASESTATION_H_ */
