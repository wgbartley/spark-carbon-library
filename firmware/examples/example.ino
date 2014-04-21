// Require required stuff
#include "main.h"

// Also include @bko's Spark Time library (https://community.spark.io/t/real-time-clock-library-for-spark/2925)
#include "SparkTime.h"


// Carbon library setup
TCPClient tcpClient;
SparkCarbon carbon;


// Time library setup
UDP UDPClient;
SparkTime rtc;


// Global variables
uint8_t counter = 0;	// Increments value for posting
uint32_t last_ts = 0;	// The last timestamp (in millis) a post was sent
bool sending = false;	// Failsafe to make sure we don't try to post while already posting (this is probably entirely unneeded, but I'm paranoid)


// Setup
void setup() {
	// Spark Time library setup
	rtc.begin(&UDPClient, "north-america.pool.ntp.org");	// Set NTP pool
	rtc.setTimeZone(-4);					// America/New_York

	// Carbon library setup
	carbon.begin(&tcpClient, { 127, 0, 0, 1 });		// Set IP address of Carbon daemon
}


// Loop
void loop() {
	// If it's the first run (last_ts==0) or 5 seconds has elapsed since the last post
	if((last_ts==0 || millis()>last_ts+5000) && sending==false) {
		// Set our sending failsafe
		sending = true;

		// Increment the counter
		counter++;

		// Get the current Unix epoch timestamp
		uint32_t now = rtc.nowEpoch();

		// Post the counter to the "stats.spark-test" metric in Carbon/Graphite
		carbon.sendData("stats.spark-test", counter, now);

		// Unset our sending failsafe
		sending = false;

		// Record the current timestamp in millis()
		last_ts = millis();
	}
}
