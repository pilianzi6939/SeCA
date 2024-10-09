cplusplus {{
    #include <bitset>  
}}

message NodeMessage {
    int senderId; 
    int receiverId; 
    int randomNumber; 
    int bitPosition; 
    int numBits = 6000; 
    string bitData; 
}
