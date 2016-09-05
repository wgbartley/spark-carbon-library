#include "CarbonLibrary.h"

SparkCarbon::SparkCarbon() {
    _carbonClient = NULL;
}


// IP address with port
bool SparkCarbon::begin(TCPClient * carbonClient, IPAddress carbonServer, uint16_t carbonPort) {
    _carbonClient = carbonClient;
    _carbonServer = carbonServer;
    _carbonPort = carbonPort;

    return true;
}


// IP address without port
bool SparkCarbon::begin(TCPClient * carbonClient, IPAddress carbonServer) {
    _carbonClient = carbonClient;
    _carbonServer = carbonServer;
    _carbonPort = 2003;

    return true;
}


// DNS name with port
bool SparkCarbon::begin(TCPClient * carbonClient, const char *carbonServer, uint16_t carbonPort) {
    _carbonClient = carbonClient;
    _carbonPort = carbonPort;

    // Resolve DNS hostname
    IPAddress remote_addr = Wifi.resolve((char*)carbonServer);
    if(remote_addr)
    {
      _carbonServer = remote_addr;
      return true;
    }
    else
      return false;
}


// DNS name without port
bool SparkCarbon::begin(TCPClient * carbonClient, const char *carbonServer) {
    _carbonClient = carbonClient;
    _carbonPort = 2003;

    // Resolve DNS hostname
    IPAddress remote_addr = Wifi.resolve((char*)carbonServer);
    if(remote_addr)
    {
      _carbonServer = remote_addr;
      return true;
    }
    else
      return false;
}


// Send data with a string metric and a string value
bool SparkCarbon::sendData(String carbonMetric, String carbonValue, uint32_t carbonTimestamp) {
    if(_carbonClient->connect(_carbonServer, _carbonPort)) {
        _carbonClient->print(carbonMetric);
        _carbonClient->print(" ");
        _carbonClient->print(carbonValue);
        _carbonClient->print(" ");
        _carbonClient->print(carbonTimestamp);
        _carbonClient->println("");
        delay(10);
        _carbonClient->stop();
        _carbonClient->flush();

        return true;
    } else
        return false;
}


// Send data with a string metric and an integer value
bool SparkCarbon::sendData(String carbonMetric, uint32_t carbonValue, uint32_t carbonTimestamp) {
    if(_carbonClient->connect(_carbonServer, _carbonPort)) {
        _carbonClient->print(carbonMetric);
        _carbonClient->print(" ");
        _carbonClient->print(carbonValue);
        _carbonClient->print(" ");
        _carbonClient->print(carbonTimestamp);
        _carbonClient->println("");
        delay(10);
        _carbonClient->stop();
        _carbonClient->flush();

        return true;
    } else
        return false;
}
