#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


#define EMPTY_STRUCT        1
#define INSUFICIENT_SPACE   1
#define EMPTY_DATA          1

#define MAXIMUM_LENGHT      500
#define MINIMUM_INDEX       4


struct PACKET_STRUCT
{
    uint32_t        packet_number;
    uint32_t        acknoledgement_number;
    uint8_t         END_STREAM : 1;
    uint16_t        checksum;
    uint8_t         data_offset : 4;
    char            packet_data[MAXIMUM_LENGHT];
    uint32_t        packet_size;

};

int BufferPopulator(unsigned char* buffer, PACKET_STRUCT packet_struct)
{
    buffer[0] = packet_struct.packet_number;
    buffer[1] = packet_struct.acknoledgement_number;
    buffer[2] = packet_struct.END_STREAM;
    buffer[3] = packet_struct.checksum;
    buffer[4] = packet_struct.data_offset;

    
    for(int i = 0; i < sizeof(buffer); i++)
    {
        buffer[MINIMUM_INDEX + i] = packet_struct.packet_data[i];
    
    }
}


int Serialize(unsigned char* buffer, PACKET_STRUCT packet_struct){
    if(sizeof(packet_struct) == 0)
    {
        return EMPTY_STRUCT;
    }

    if(sizeof(buffer) < sizeof(packet_struct))
    {
        return INSUFICIENT_SPACE;
    }

    if(packet_struct.packet_data == NULL)
    {
        return EMPTY_DATA;
    }

    



    

    return 0;
}