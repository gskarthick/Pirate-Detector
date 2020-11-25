#include <Arduino.h>
//analog out port 
#define APORT  0

struct Wifi {
   String  ssid;
   String  password;
};




//different hosts and SHA-1 keys from the certificate
const char* host = "appleid.apple.com";
const char* fingerprint = "C1 A0 0F CE D7 5B C3 56 A2 1C 86 21 0A C1 4C BD 9A FE AA 85";

const char* host2 = "www.snapchat.com";
const char* fingerprint2 = "49 73 A3 46 FC B6 14 3B 02 6C 70 6E 8A 26 92 CB 54 9A E7 D3";

const char* host3 = "www.instagram.com";
const char* fingerprint3 = "92 D1 B5 7C AE 6F 88 3F 62 E0 E8 C8 A5 EC 5C AF E2 D0 FF 37";

const char* host4 = "www.ebay.com";
const char* fingerprint4 = "F6 AC 99 99 F8 69 EB 25 91 6C F3 66 5A 1F AB 34 1B 39 F0 CE";

//stores if hacker is detected
bool appleHacker = false;
bool snapchatHacker = false;
bool instagramHacker = false; 
bool ebayHacker = false; 

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(LED_BUILTIN, OUTPUT);

Serial.begin(9600);
    //myservo.attach(4); 
    Serial.print("network(s) found");
  for (int i = 2; i <= 7; i++) {
    pinMode (i, OUTPUT);
  }
    Serial.println("WiFi connected");  
int countApple = 0;
int countSnap = 0;
int countInstagram = 0;
int countEbay = 0;
}
void apple()
{
  //Connects to a client via the host 
  WiFiClientSecure client;
Serial.print("connecting to ");
Serial.println(host);
delay(2000);
if (!client.connect(host, 443)) {
  Serial.println("connection failed for appleid.apple.com");
 //allows the connection to try and reconnect 4 times before assuming that there is a problem with the HTTPS port
 if(countApple == 3){
  Serial.println("No HTTPS port, hacker may be trying to force you to use HTTP!");
    
    appleHacker = true;
 }else{
   countApple = countApple + 1;
   apple();
  }
}else{
  //checks the certificate 
  if (client.verify(fingerprint, host)) {
  Serial.println("certificate matches for appleid.apple.com");
  client.flush();
  client.stop();
} else {
  
  client.flush();
  client.stop();
  Serial.println("certificate doesn't match for appleid.apple.com! Hacker dectected");

    
    appleHacker = true;


}
}
}
 
