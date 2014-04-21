#ifndef _SPARKCARBON
#define _SPARKCARBON

#include "application.h"

class SparkCarbon {
    public:
        SparkCarbon();
        bool begin(TCPClient * carbonClient, IPAddress carbonServer, uint16_t carbonPort);
        bool begin(TCPClient * carbonClient, IPAddress carbonServer);
        bool begin(TCPClient * carbonClient, const char *carbonServer, uint16_t carbonPort);
        bool begin(TCPClient * carbonClient, const char *carbonServer);
        bool sendData(String carbonMetric, String carbonValue, uint32_t carbonTimestamp);
        bool sendData(String carbonMetric, uint32_t carbonValue, uint32_t carbonTimestamp);
    
    private:
        TCPClient * _carbonClient;
        IPAddress _carbonServer;
        uint16_t _carbonPort;
};

#endif
