#include <SPI.h>
#include <ESP8266WiFi.h>



char ssid[] = "Anthony's";  //wifi name
char pass[] = "Jesus123"; //wifi password 
int status = WL_IDLE_STATUS;
WiFiClient client;

char server[] = "192.168.1.1"; //Server

void setup() 
{
  Serial.begin(9600);
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
          IPAddress ip = WiFi.localIP();   
          Serial.print("My IP address is: "); 
    Serial.println(ip);  
}

void loop() 
{
    

        if(client.connect(server, 80))
        {  

           int SID = 4;
           int TID = 1;
            Serial.println("\nconnected...");
            Serial.println("ARDUINO: forming HTTP request message");
    
            client.print("GET ");
            client.print("/mysql_1.php?");//php code for database
            client.print(SID);
            //client.print(TID);
            client.print(" HTTP/1.1");
            client.print("\r\n");
            client.print("User-Agent: Arduino1\r\n");
            client.print("Content-Type: application/x-www-form-urlencoded\r\n");
            client.print("Connection: Keep-Alive\r\n");
            client.print("\n\n"); 

            Serial.println("ARDUINO: HTTP message sent");
            delay(3000);
            if(client.available())
            {
                Serial.println("ARDUINO: HTTP message received");
                Serial.println("ARDUINO: printing received headers and script response...\n");
      
                while(client.available())
                {
                    char c = client.read();
                    Serial.print(c);
                }
            }
            else
            {
                Serial.println("ARDUINO: no response received / no response received in time");
            }
            client.stop();
        }
        else
        {
            Serial.println("connection failure");
        }

    }
   
