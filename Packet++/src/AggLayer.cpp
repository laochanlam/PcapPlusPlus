
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
    AggLayer::AggLayer(uint64_t key, uint32_t len_tensor, uint32_t workerID, uint8_t agtr, uint32_t round, uint32_t* data)
    {
        m_DataLen = sizeof(agghdr);
        //fake data
        m_Data = new uint8_t[m_DataLen];
        memset(m_Data, 0, sizeof(m_DataLen));
        m_Protocol = AGG;

        agghdr* aggHeader = getAggHeader();

        aggHeader->key = key;
        aggHeader->len_tensor = len_tensor;
        aggHeader->bitmap = htonl(1 << workerID);
        aggHeader->reserved = 0;
        aggHeader->agtr = agtr;
        aggHeader->round = htonl(round);
//        printf("value of a = 0x%08x\n",  aggHeader->bitmap);
//         printf("A: 0x%X \n", workerID);
//         printf("B: 0x%X \n", htons(workerID));
//         printf("C: 0x%X \n", aggHeader->workerID);
//         printf("A: %08X \n", workerID);
//         printf("B: %08X \n", htons(workerID));
//         printf("C: %08X \n", aggHeader->workerID);

        memcpy(aggHeader->vector, data, sizeof(uint32_t) * (MAX_ENTRIES_PER_PACKET));
    }

    void AggLayer::computeCalculateFields()
    {
        
    }

    std::string AggLayer::toString()
    {
        return "Agg To String";
    }
}