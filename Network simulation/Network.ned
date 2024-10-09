
package Network;

import inet.node.inet.INetworkNode;
import inet.mobility.single.RandomWaypointMobility;
import inet.physicallayer.ieee802154.packetlevel.Ieee802154ScalarRadio;
import inet.linklayer.ieee802154.Ieee802154Mac;
import inet.networklayer.contract.INetworkLayer;
import inet.application.contract.IApp;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;


network ZigbeeNetwork
{
    parameters:
        int numNodes = default(3000); 
        @display("bgb=1000,1000");    

    submodules:
        
        baseStation: BaseStation {
            @display("p=500,500;is=s"); 
        }

        
        mobileNode[numNodes]: MobileNode {
            @display("p=uniform(0,1000),q=uniform(0,1000);is=s"); 
        }

        
        visualizer: IntegratedCanvasVisualizer {
            @display("p=900,100");
        }
}
