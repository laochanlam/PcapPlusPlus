
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
    AggLayer::AggLayer(uint8_t workerID, uint32_t* data)
    {
        m_DataLen = sizeof(agghdr);
        m_Data = new uint8_t[m_DataLen];
        memset(m_Data, 0, sizeof(m_DataLen));
        m_Protocol = AGG;

        agghdr* aggHeader = getAggHeader();
        // std::cout <<  "worker: " << +worker << std::endl;
        aggHeader->workerID = htons(workerID) >> 8;
        aggHeader->entry_count = htons(MAX_ENTRIES_PER_PACKET) >> 8;
//         printf("A: 0x%X \n", workerID);
//         printf("B: 0x%X \n", htons(workerID));
//         printf("C: 0x%X \n", aggHeader->workerID);
//         printf("A: %08X \n", workerID);
//         printf("B: %08X \n", htons(workerID));
//         printf("C: %08X \n", aggHeader->workerID);

        // std::cout <<  "aggHeader->worker: " << +htons(worker) << std::endl;
        memcpy(aggHeader->vector, data, sizeof(uint32_t) * (MAX_ENTRIES_PER_PACKET+1));

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