void Thingspeak_1() {
  // Sensor 1
  h1 = dht1.getHumidity();
  // Read temperature as Celsius (the default)
  t1 = dht1.getTemperature();
  // Sensor 2
  h2 = dht2.getHumidity();
  // Read temperature as Celsius (the default)
  t2 = dht2.getTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  if (client.connect("api.thingspeak.com", 80)) {
    request_string = "/update?";
    request_string += "key=";
    request_string += "MKE5FAKIKLWQ1DF3";
    request_string += "&";
    request_string += "field1";
    request_string += "=";
    request_string += t1;
    request_string += "&";
    request_string += "field2";
    request_string += "=";
    request_string += h1;
    request_string += "&";
    request_string += "field3";
    request_string += "=";
    request_string += t2;
    request_string += "&";
    request_string += "field4";
    request_string += "=";
    request_string += h2;
    request_string += "&";
    Serial.println(String("GET ") + request_string + " HTTP/1.1\r\n" + //
                   "Host: " + thingSpeakAddress + "\r\n" +
                   "Connection: close\r\n\r\n");

    client.print(String("GET ") + request_string + " HTTP/1.1\r\n" +
                 "Host: " + thingSpeakAddress + "\r\n" +
                 "Connection: close\r\n\r\n");
    unsigned long timeout = millis();
    while (client.available() == 0) {
      if (millis() - timeout > 5000) {
        Serial.println(">>> Client Timeout !");
        client.stop();
        return;
      }
    }
  }
}
