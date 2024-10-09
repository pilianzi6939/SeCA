#include "BaseStation.h"
#include "MobileNodeMsg_m.h"

Define_Module(BaseStation);

void BaseStation::initialize()
{

    int randomDevice = intuniform(0, 2999);
    MobileNodeMsg *startMsg = new MobileNodeMsg("startMsg");
    startMsg->setRandomNumber(intuniform(1, 10000));


    sendDirect(startMsg, getModuleByPath("mobileNode[" + std::to_string(randomDevice) + "]"), "in");
}

void BaseStation::handleMessage(cMessage *msg)
{

    delete msg;
}
