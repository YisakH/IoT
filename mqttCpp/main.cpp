#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <ctime>
#include <fcntl.h>
#include <string>
#include <stdlib.h>
#include <json/json.h>
#include <json/value.h>
#include <json/writer.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include "mqtt/async_client.h"

using namespace std;

#define PACKETSIZE 32
#define ADDRESS "192.168.30.9"
#define PORT 1883
#define CLIENTID "ExampleClientPub"
#define TOPIC "test"
#define QOS 1
#define TIMEOUT 10000L
int fd;

int openi2c(int slave_addr)
{
	//----- OPEN THE I2C BUS -----
	char *filename = (char *)"/dev/i2c-1";
	int fd = open(filename, O_RDWR);
	if (fd < 0)
	{
		printf("Failed to open the i2c bus");
		return fd;
	}

	int io = ioctl(fd, I2C_SLAVE, slave_addr);
	if (io < 0)
		printf("Failed to acquire bus access and/or talk to slave.\n");
	return fd;
}

string replaceAll(const string &str, const string &pattern, const string &replace)
{
	string result = str;
	string::size_type pos = 0;
	string::size_type offset = 0;
	while ((pos = result.find(pattern, offset)) != string::npos)
	{
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
		offset = pos + replace.size();
	}
	return result;
}

void message_callback(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg)
{
	// json 만들기

	// i2c 읽어오기
	unsigned char data[PACKETSIZE];
	int n = read(fd, data, PACKETSIZE);


	if (n != PACKETSIZE)
	{ // 요청한 읽기 크기와 실제 읽어 온 크기 비교
		printf("Error in reading i2c. n=%d\n", n);
		exit(-1);
	}
	//시간 읽어오기
	time_t timer = time(NULL);
	struct tm *t = localtime(&timer);
	string date = to_string(t->tm_year + 1900) + "-" + to_string((t->tm_mon + 1)) + "-" + to_string(t->tm_mday) + " " + to_string(t->tm_hour) + ":" + to_string(t->tm_min) + ":" + to_string(t->tm_sec);

	// 읽어온 값 Json 쓰기
	Json::Value root;
	root["id"] = 3;
	root["time"] = date;
	root["type"] = "dustsensor";

	root["value"]["status"] = data[2];
	root["value"]["measuringMode"] = 256 * data[3] + data[4];
	root["value"]["calibCoeff"] = 256 * data[5] + data[6];

	Json::Value grim;
	grim["PM1.0"] = 256 * data[7] + data[8];
	grim["PM2.5"] = 256 * data[9] + data[10];
	grim["PM10"] = 256 * data[11] + data[12];

	Json::Value tsi;
	tsi["PM1.0"] = 256 * data[13] + data[14];
	tsi["PM2.5"] = 256 * data[15] + data[16];
	tsi["PM10"] = 256 * data[17] + data[18];

	Json::Value dust;
	dust["0.3um"] = 256 * data[19] + data[20];
	dust["0.5um"] = 256 * data[21] + data[22];
	dust["1.0um"] = 256 * data[23] + data[24];
	dust["2.5um"] = 256 * data[25] + data[26];
	dust["5.0um"] = 256 * data[27] + data[28];
	dust["10um"] = 256 * data[29] + data[30];

	root["value"]["GRIMM"] = grim;
	root["value"]["TSI"] = tsi;
	root["value"]["dust"] = dust;

	Json::FastWriter writer;
	string str = writer.write(root);

	mosquitto_publish(mosq, nullptr, TOPIC, str.length(), (char *)str.c_str(), 1, 0); // retain 생각해볼만 한 듯 싶음
}

int main(int argc, char *argv[])
{
	fd = openi2c(0x28);
	if (fd < 0)
	{
		printf("Error in opening i2c. fd=%d\n", fd);
		return fd;
	}

	// -------------------------------------------------------------------------
	// MQTTClient initial settings
	// -------------------------------------------------------------------------
	struct mosquitto *mosq;

	mosquitto_lib_init();
	char clientid[24]; // nullptr을 사용해도 상관 없음..
	int rc = 0;
  
	memset(clientid, NULL, sizeof(clientid));
	snprintf(clientid, sizeof(clientid) - 1, "mqttPRAC", getpid());

	mosq = mosquitto_new(clientid, true, nullptr);

	mosquitto_connect(mosq, ADDRESS, PORT, 10);

	MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
	int rc;

	if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to create client, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }*/
	

	
	mosquitto_message_callback_set(mosq, message_callback);

	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup(); // 라이브러리도 깔끔히 정리...

	return 0;
}
