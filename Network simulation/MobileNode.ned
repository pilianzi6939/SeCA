// MobileNode.ned
import inet.physicallayer.ieee802154.packetlevel.Ieee802154ScalarRadio;
import inet.mobility.single.RandomWaypointMobility;
import inet.linklayer.ieee802154.Ieee802154Mac;
import inet.applications.contract.IApp;

module MobileNode
{
    parameters:
        @display("i=device/cellphone"); 
        double mobility.speed;          

    submodules:
        
        app: IApp {
            @display("p=50,50");
        }

        
        mobility: RandomWaypointMobility {
            @display("p=100,50");
        }

        
        mac: Ieee802154Mac {
            @display("p=150,50");
        }

        
        radio: Ieee802154ScalarRadio {
            @display("p=200,50");
        }

    connections allowunconnected:
        app.upperOut --> mac.upperIn;      
        mac.upperOut --> app.upperIn;

        mac.lowerOut --> radio.upperIn;    
        radio.upperOut --> mac.lowerIn;
}
