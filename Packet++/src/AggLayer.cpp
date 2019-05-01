
#include "AggLayer.h"
#include <iostream>
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
    AggLayer::AggLayer(uint8_t worker, uint32_t* array)
    {
        m_DataLen = sizeof(agghdr);
        m_Data = new uint8_t[m_DataLen];
        memset(m_Data, 0, sizeof(m_DataLen));
        m_Protocol = AGG;

        agghdr* aggHeader = getAggHeader();
        aggHeader->worker = htons(worker);
        memcpy(aggHeader->vector, array, sizeof(uint32_t) * 10);

//        for (int i = 0; i < 10; i++) {
//            std::cout << aggHeader->vector[i] << std::endl;
//        }
    }

    void AggLayer::computeCalculateFields()
    {
        
    }

    std::string AggLayer::toString()
    {
        return "Agg To String";
    }
}