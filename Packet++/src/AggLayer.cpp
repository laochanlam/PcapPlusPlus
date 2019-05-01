
#include "AggLayer.h"
#include <string.h>
#if defined(WIN32) || defined(WINx64) || defined(PCAPPP_MINGW_ENV)
#include <winsock2.h>
#elif LINUX
#include <in.h>
#elif MAC_OS_X
#include <arpa/inet.h>
#endif

namespace pcpp
{
    AggLayer::AggLayer(AggOpcode opCode, const uint32_t& operand_a, const uint32_t& operand_b) 
    {
        m_DataLen = sizeof(agghdr);
        m_Data = new uint8_t[m_DataLen];
        memset(m_Data, 0, sizeof(m_DataLen));
        m_Protocol = AGG;

        agghdr* aggHeader = getAggHeader();
        aggHeader->opcode = htons(opCode);
        aggHeader->operand_a = operand_a;
        aggHeader->operand_b = operand_b;
    }

    void AggLayer::computeCalculateFields()
    {
        
    }

    std::string AggLayer::toString()
    {
        return "Agg To String";
    }
}