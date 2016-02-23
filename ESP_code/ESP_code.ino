#include <ESP8266WiFi.h>

//update planeGo
//figure out how to read GPS String coordinates
//figure out how to set servos, and what servos we're using

//WiFi Definitions
const char WiFiAPPSK[] = "tuckersmith";

//Pin Definitions
const int GYRO_PIN = 5; // Gyro pin
const int MOTOR_PIN = 2; // Motor pin
String GPString = "";
boolean planeGone = false;

WiFiServer server(80);

void setupWiFi()
{
  WiFi.mode(WIFI_AP);

  //change adress name
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) +
                 String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
   macID.toUpperCase();
   String AP_NameString = "Plane Ap";

   char AP_NameChar[AP_NameString.length() + 1];
   memset(AP_NameChar, 0, AP_NameString.length() + 1);

   for(int i = 0; i < AP_NameString.length(); i++)
     AP_NameChar[i] = AP_NameString.charAt(i);

     WiFi.softAP(AP_NameChar, WiFiAPPSK);
}

void setup()
{
  Serial.begin(115200);
  setupWiFi();
  server.begin();
}

void planeGo()
{
  planeGone = true;
}

void planeLand()
{
  planeGone = false;
}

void loop()
{
  //Check if a client has connected
  WiFiClient client = server.available();
  if(!client) {
    return;
  }

  //Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  client.flush();

  //Prepare the response. Start with common header:
  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";

  //match the request
  int val = -1; // We'll use 'val' to keep track of both the
                // request type (read/set) and value if set.
  if (req.indexOf("/planeGo") != -1)
    val = 0; // Will write LED low
  else if (req.indexOf("/setGPS") != -1)
    val = 1; // Will print pin reads
  else if (req.indexOf("/planeState") != -1)
    val = -2;

  //add displays and call methods dependent on 
  if (val = -2)
  {
    s += "Your plane is ";
    s += (planeGone)?"gone.":"not gone.";
  }
  else if (val == 0)
  { 
    planeGo();
  }
  else if (val == 1)
  {
     s+= "<form action=\"demo_form.asp\">GPS: <input type=\"text\" name=\"GPS\" value=""><br><input type=\"submit\" value=\"Submit\">\"</form>";
     
  }
  else
  {
    s+= "Invalid request. \rPlease use:\r\t/planeGo\r\t/setGPS\r\t/planeState";
  }

  //close
  s += "</html>\n";
  

  //send the response to the client
  client.print(s);
  delay(1);

  // The client will be disconnected
  //when the function returns and 'client' is destroyed.
}
