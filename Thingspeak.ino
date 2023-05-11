#include <DHTesp.h> // librari untuk DHT11
#include <WiFi.h> // Librari WIFi koneksi
//#include <Wire.h>
#define dhtPin1 13
#define dhtPin2 14

DHTesp dht1,dht2;

WiFiClient client;

String thingSpeakAddress = "api.thingspeak.com"; 
String writeAPIKey;
String tsfield1Name;
String request_string;
const char *ssid =  "realme 5 Pro";                                    // replace with your wifi ssid and wpa2 key
const char *pass =  "mus123411";
String kirim_thingspeak();
float t1 = 0;
float h1 = 0;
float t2 = 0;
float h2 = 0;

void setup()
{
  dht1.setup(dhtPin1, DHTesp::DHT11);
  dht2.setup(dhtPin2, DHTesp::DHT11);
  Serial.begin(115200);
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
//  dht.begin();
}

void loop()
{
  Thingspeak_1();
  delay(10);
  while (client.available()) {
  String line = client.readStringUntil('\r');
  Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");
}
