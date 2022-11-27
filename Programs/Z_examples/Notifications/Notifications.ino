#include <WiFiNINA.h>

//please enter your sensitive data in the Secret tab
char ssid[] =  //"Mbphone";
char pass[] = //"Mauricio123";

WiFiClient client;

char   HOST_NAME[] = "maker.ifttt.com";
String PATH_NAME   = "/trigger/LowChargeAlarm/with/key/bBZfl5MtmOYi2FWDIFTZ7Iozu3qwcZ0uVMxVnTTnwV0"; // change your EVENT-NAME and YOUR-KEY
String queryString = "?value1=30 Volts&value2=25";

void setup() {
  
  // initialize WiFi connection
  WiFi.begin(ssid, pass);

  Serial.begin(9600);
  while (!Serial);
  byte ok = 1;
  while (ok)
  {

    // connect to web server on port 80:
    if (client.connect(HOST_NAME, 80)) {
      // if connected:
      Serial.println("Connected to server");
      ok = 0;
    }
    else {// if not connected:
      Serial.println("connection failed");
      delay(2000);
       WiFi.begin(ssid, pass);
    }
  }

}

void loop() {
  while (true)
  {
    Serial.print("Try Again 0:");
    while (Serial.read() != 's') {
      delay(1000);
    }
    //if (Serial.read() == 's') {

      // make a HTTP request:
      // send HTTP header
      client.println("GET " + PATH_NAME + queryString + " HTTP/1.1");
      client.println("Host: " + String(HOST_NAME));
      client.println("Connection: open");
      client.println(); // end HTTP header


      //while (client.connected()) {
        if (client.connected() && client.available()) {
          // read an incoming byte from the server and print it to serial monitor:
          char c = client.read();
          Serial.println("Message From Server: ");
          Serial.print(c);
        }
        else
        {
          Serial.println("Not Available:");
        }
      //}

      // the server's disconnected, stop the client:
      // client.stop();
      // Serial.println();
      // Serial.println("disconnected");
    //}

    delay(3000);
    Serial.print("Try Again 2:");


  }
}