#ifndef MOBILENODE_H_
#define MOBILENODE_H_

#include <omnetpp.h>
#include "MobileNodeMsg_m.h"

using namespace omnetpp;

class MobileNode : public cSimpleModule
{
  private:
    int msg[3000] = {00};
    bool isMsgComplete = false;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void sendMsgToRandomNeighbor(int randomNum);
    bool checkIfComplete();
};

#endif /* MOBILENODE_H_ */
