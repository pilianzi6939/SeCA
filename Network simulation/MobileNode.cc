#include "MobileNode.h"
#include "MobileNodeMsg_m.h"

Define_Module(MobileNode);

void MobileNode::initialize()
{

    int id = getIndex();
    msg[id] = 01;
}

void MobileNode::handleMessage(cMessage *msg)
{
    MobileNodeMsg *recvMsg = check_and_cast<MobileNodeMsg *>(msg);
    int *receivedData = recvMsg->getDataArray();


    for (int i = 0; i < 3000; i++) {
        msg[i] |= receivedData[i];
    }


    if (checkIfComplete()) {
        isMsgComplete = true;
        endSimulation();
    } else {
        sendMsgToRandomNeighbor(recvMsg->getRandomNumber());
    }

    delete recvMsg;
}

void MobileNode::sendMsgToRandomNeighbor(int randomNum)
{

    int randomNeighbor = intuniform(0, 2999);
    MobileNodeMsg *newMsg = new MobileNodeMsg("dataMsg");
    newMsg->setRandomNumber(randomNum);


    for (int i = 0; i < 3000; i++) {
        newMsg->setData(i, msg[i]);
    }


    sendDirect(newMsg, getModuleByPath("mobileNode[" + std::to_string(randomNeighbor) + "]"), "in");
}

bool MobileNode::checkIfComplete()
{
    for (int i = 0; i < 3000; i++) {
        if (msg[i] == 0) {
            return false;
        }
    }
    return true;
}
