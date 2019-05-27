#ifndef PACKETPP_AGG_LAYER
#define PACKETPP_AGG_LAYER

#define MAX_ENTRIES_PER_PACKET 32
#include "Layer.h"
#include <iostream>
namespace pcpp 
{
// I guess use this for no alignment
#pragma pack(push, 1)
    struct agghdr {
        uint32_t bitmap;
            uint8_t reserved: 7,
                ACK: 1;
        uint32_t vector[MAX_ENTRIES_PER_PACKET+1];
    };
#pragma pack(pop)

//    enum AggOpcode
//    {
//        ADD = 0x01,
//        SUB = 0x02
//    };

    class AggLayer : public Layer
    {
        public:
        /**
		 * A constructor that creates the layer from an existing packet raw data
         */
        AggLayer(uint8_t* data, size_t dataLen, Layer* prevLayer, Packet* packet) : Layer(data, dataLen, prevLayer, packet) { m_Protocol = AGG; m_DataLen = sizeof(agghdr); }
        /**
		 * A constructor that allocates a new AGG header
         */
        AggLayer(uint32_t worker, uint32_t* array);
        ~AggLayer() {}

        /**
		 * Get a pointer to the AGG header. Notice this points directly to the data, so every change will change the actual packet data
         */
        inline agghdr* getAggHeader() const { return (agghdr*)m_Data; }

        /**
		 * Does nothing for this layer (AggLayer is always last)
		 */
        void parseNextLayer() {}

        void setACK(void) { getAggHeader()->ACK = 1; }
		/**
		 * @return The size of @ref arphdr
		 */
		inline size_t getHeaderLen() { return sizeof(agghdr); }

        /**
		 * Calculate the following fields
		 */
		void computeCalculateFields();

        std::string toString();

        OsiModelLayer getOsiModelLayer() { return OsiModelApplicationLayer; }
    };
}
#endif 