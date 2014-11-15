// Require required stuff
#include "CarbonLibrary/CarbonLibrary.h"

// Carbon library setup
TCPClient tcpClient;
CarbonLibrary carbon;


// Global variables
uint8_t counter = 0;	// Increments value for posting
uint32_t last_ts = 0;	// The last timestamp (in millis) a post was sent


// Setup
void setup() {
	// Carbon library setup
	carbon.begin(&tcpClient, { 127, 0, 0, 1 });		// Set IP address of Carbon daemon
}


// Loop
void loop() {
	// If it's the first run (last_ts==0) or 5 seconds has elapsed since the last post
	if((last_ts==0 || millis()>last_ts+5000)) {
		// Increment the counter
		counter++;

		// Post the counter to the "stats.spark-test" metric in Carbon/Graphite
		carbon.sendData("stats.spark-test", counter, Time.now());

		// Record the current timestamp in millis()
		last_ts = millis();
	}
}
