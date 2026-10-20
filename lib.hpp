
#include <stdint.h>

#define EMPTY_STRUCT 1

#define MAXIMUM_LENGTH 255

struct PACKET_STRUCT
{
    uint32_t        packet_number;
    uint8_t         FLAG : 1;
    uint16_t        checksum;
    uint8_t         code;
    uint32_t        packet_size;

};

void BufferPopulator(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT packet_struct);

void PacketPopulator(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT *packet_struct);


int Serialize(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT packet_struct);


int Desirialize(uint8_t buffer[MAXIMUM_LENGTH], PACKET_STRUCT *packet_struct);