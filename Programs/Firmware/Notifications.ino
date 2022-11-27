#include <WiFiNINA.h>

char ssid[] = "dlink-D654";  //"Mbphone";
char pass[] = "37ADrive";    //"Mauricio123";

WiFiClient client;

char HOST_NAME[] = "maker.ifttt.com";
String PATH_NAME = "/trigger/LowChargeAlarm/with/key/bBZfl5MtmOYi2FWDIFTZ7Iozu3qwcZ0uVMxVnTTnwV0";  // change your EVENT-NAME and YOUR-KEY

bool IsWifiConnected() {
  return (WiFi.status() == WL_CONNECTED);
}

bool InitWifi() {

  // initialize WiFi connection
  WiFi.begin(ssid, pass);

  byte count = 0;

  for (int i = 0; i >= 4; i++) {

    if (IsWifiConnected()) {
      Serial.println("Connected to WiFi");
      delay(5000);

      return true;
    } else {
      Serial.print("connection failed");
      Serial.println(i);
      delay(50000);
    }
  }

  bool SendNotification(float AmpHour, char* message) {

    // String to send: ?value1=AmpHourAh&value2=25";
    // String buf;
    // buf += F("?value1=");
    // buf += String(AmpHour, 2);
    // buf += F("Ah &value2=");
    // buf += message;
    // Serial.println(buf);

    // if (!client.connect(HOST_NAME, 80)) return false;
    // client.println("GET " + PATH_NAME + buf + " HTTP/1.1");
    // client.println("Host: " + String(HOST_NAME));
    // client.println("Connection: open");
    // client.println();  // end HTTP header

    // if (client.connected() && client.available()) {
    //   // read an incoming byte from the server and print it to serial monitor:
    //   char c = client.read();
    //   Serial.print("Message sent to server. Response: ");
    //   Serial.println(c);
    // } else {
    //   Serial.println("Message not sent. Client Not connected or Available:");
    // }
  }