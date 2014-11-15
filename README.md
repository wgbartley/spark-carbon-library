spark-carbon-library
====================

About
-----
A library for posting metrics to a Carbon daemon.


What You Need
-------------

 - A Spark Core
 - A Carbon daemon    


How to Use
----------

1. Set up a TCPClient to use with SparkCarbon.
2. Instantiate the SparkCarbon library.  We'll use a variables named `tcpClient` and `carbon` for this example.
3. In `setup()`, "begin" the library using `carbon.begin()`.  `carbon.begin()` will work with a few variations.
    1. IP Address without port (defaults to 2003): `carbon.begin(tcpClient, { 127, 0, 0, 1 });`
    2. IP Address with port: `carbon.begin(tcpClient, { 127, 0, 0, 1}, 2003);`
    3. DNS name without port (defaults to 2003): `carbon.begin(tcpClient, "my-carbon-server.mydomain.com", 2003);`
    4. DNS name with port: `carbon.begin(tcpClient, "my-carbon-server.mydomain.com", 2003);`
4. Finally, elsewhere in your code, you can use `carbon.sendData("stats.spark-test", 1, 1302905160)` (metric, value, timestamp) to post data to your Carbon daemon.


Links
-----

 - [Graphite/Carbon](http://graphite.readthedocs.org/)
