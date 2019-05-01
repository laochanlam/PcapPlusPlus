#ifndef PACKETPP_AGG_LAYER
#define PACKETPP_AGG_LAYER

#include "Layer.h"

namespace pcpp 
{
// I guess use this for no alignment
#pragma pack(push, 1)
    struct agghdr {
        uint8_t opcode;
        uint32_t operand_a;
        uint32_t operand_b;
        uint32_t result;
    };
#pragma pack(pop)

    enum AggOpcode
    {
        ADD = 0x01,
        SUB = 0x02
    };

    class AggLayer : public Layer
    {
        public:
        /**
		 * A constructor that creates the layer from an existing packet raw data
         */
        AggLayer(uint8_t* data, size_t dataLen, Layer* prevLayer, Packet* packet) : Layer(data, dataLen, prevLayer, packet) { m_Protocol = AGG; m_DataLen = sizeof(agghdr); }
        /**
		 * A constructor that allocates a new ARP header
         */
        AggLayer(AggOpcode opCode, const uint32_t& operand_a, const uint32_t& operand_b);
        ~AggLayer() {}

        inline agghdr* getAggHeader() const { return (agghdr*)m_Data; }
    };
}
#endif 