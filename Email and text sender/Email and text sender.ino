/*
 * MADE BY J-oseph ON GITHUB
 * MOST OF THIS CODE IS NOT MY OWN
 * PLEASE CHECK OUT MY VIDEO https://youtu.be/GFDTMFBPCn4 TO SEE HOW TO SET EVERYTHING UP
 * AND TO FIND LINKS TO OTHER PEOPLE'S CODE
 * THIS CODE WORKS WITH ARDUINO NANO 33 IOT
 * USE WITH OTHER ARDUINOS AT YOUR OWN RISK ;)
*/
#include <WiFiNINA.h>
#include <EMailSender.h>

char ssid[] = "dlink-D654"; 
char pass[] = "37ADrive";    
char eMailUser[] = "SoftwareMB@hotmail.com"; // account must have correct settings (see video)
char eMailPass[] = "ybdsoogeurfvcase"; // has to be an app password (see video)
char eMailRecipient[] = "mauricio.b3@gmail.com";  // if you want to send an email  
char phoneRecipient[] = "3433331818@msg.koodomobile.com";    // if you want to send a text (formatted for at&t)
//1234567890@vtext.com (formatted for verizon)
//1234567890@tmomail.net (formatted for tmobile)

const String TEXT = "T E X T"; // main body text of the email
const char SUBJ[] = "S U B J"; // subject of the email


WiFiClient client; // sets up the wifi client

void setup(){  
  Serial.begin(9600);
  
  // all we do is connect to wifi and send and email
  setupWifi();
  
  sendEmail();
}

// ***DO NOT PUT THE sendEmail FUNCTION IN A LOOP UNLESS YOU CAN PREVENT 
//    IT FROM TRYING TO SEND AN EMAIL CONTINUOUSLY. GOOGLE WILL BLOCK
//    YOUR DEVICE IF YOU DO THAT. BE VERY CAREFUL :) ****
void loop() {}





void setupWifi(){
  // connects to the wifi (duh)
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.print("...");

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    // will stay in a loop if it doesnt connect
    delay(2000);
    Serial.print(".");
  }
  Serial.println("Connected");
  Serial.print("Local IP address: ");
  Serial.println(WiFi.localIP());   // prints your local IP address, not needed for anything in the program
  Serial.println("");              
  Serial.println("");
}


void sendEmail(){
    // sends an email or text depending on which recipient you choose
    char senderName[] = "SENDER"; // the name it will display who the email is from

    // the actual stuff that sends the email:
    EMailSender emailSend(eMailUser, eMailPass, eMailUser, senderName);
    EMailSender::EMailMessage msg;
    EMailSender::Response resp;
    Serial.println("Sending email...");
    msg.subject = SUBJ;
    msg.message = TEXT;
    resp = emailSend.send(eMailRecipient, msg); // change eMailRecipient to phoneRecipient to send a text instead

    // all of this just prints the info
    Serial.println("Sending status: ");
    Serial.print(resp.status);
    Serial.println(resp.code);
    Serial.println(resp.desc);
    Serial.println("");
    Serial.print("FROM: ");
    Serial.println(eMailUser);
    Serial.print("TO: ");
    Serial.println(eMailRecipient);
    Serial.print("SUBJECT: ");
    Serial.println(SUBJ);
    Serial.print("DATA:");
    Serial.println(TEXT);
    Serial.println("");
}
