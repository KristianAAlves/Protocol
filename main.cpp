#include <iostream>
#include "lib.hpp"


int main(){
    
    PACKET_STRUCT ps;
    PACKET_STRUCT ps2;
    uint8_t buff[MAXIMUM_LENGTH];

    ps.packet_number = static_cast<uint8_t>(3432);
    ps.FLAG = 0;
    ps.checksum = 4242;
    ps.code = 3432;
    ps.packet_size = 333;

    Serialize(buff, ps);

    std::cout << buff[0] << "\n";
    
    Desirialize(buff, &ps2);

    std::cout << ps2.packet_number << "\n";
 
    

    return 0;
}

