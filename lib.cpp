#include "lib.hpp"

void PacketPopulator(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT *packet_struct)
{
    packet_struct->packet_number = buffer[0];
    packet_struct->FLAG = buffer[1];
    packet_struct->checksum = buffer[2];
    packet_struct->code = buffer[3];
    packet_struct->packet_size = buffer[4];
}

void BufferPopulator(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT packet_struct)
{
    
    buffer[0] = packet_struct.packet_number;
    buffer[1] = packet_struct.FLAG;
    buffer[2] = packet_struct.checksum;
    buffer[3] = packet_struct.code;
    buffer[4] = packet_struct.packet_size;

}

int Serialize(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT packet_struct)
{

    if(sizeof(packet_struct) == 0 )
    {
        return EMPTY_STRUCT;
    }

    BufferPopulator(buffer, packet_struct);



    return 0;
}

int Desirialize(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT *packet_struct)
{
    
    PacketPopulator(buffer, packet_struct);

    return 0;

}