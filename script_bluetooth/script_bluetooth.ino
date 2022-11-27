#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include <WiFi.h>
#include <HTTPClient.h>

String knownBLEAddresses[] = {"8c:d9:d6:4b:4d:41" ,"aa:bc:cc:dd:ee:ee", "54:2c:7b:87:71:a2","A8:16:D0:7E:97:D0","6e:ee:ee:ac:39:48", "E0:5F:5E:ED:7F:8D", "49:f0:cc:dd:e6:9c", "e0:5f:5e:ed:7f:8d", "45:d5:89:cd:3d:19"};
int RSSI_THRESHOLD = -55;
bool device_found;
int scanTime = 5; //In seconds
int LED_BUILTIN = LOW;

const char* wifiName = "NOMEWFI"; //CHANGE
const char* wifiPassword = "SENHAPASSWORD"; //CHANGE

String serverName = "localhost:8000/eugene";

unsigned long lastTime = 0;
unsigned long timerDelay = 5000; //5 Seconds



BLEScan* pBLEScan;
class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
      for (int i = 0; i < (sizeof(knownBLEAddresses) / sizeof(knownBLEAddresses[0])); i++)
      {
        //Uncomment to Enable Debug Information
        //Serial.println("*************Start**************");
        //Serial.println(sizeof(knownBLEAddresses));
        //Serial.println(sizeof(knownBLEAddresses[0]));
        //Serial.println(sizeof(knownBLEAddresses)/sizeof(knownBLEAddresses[0]));
        //Serial.println(advertisedDevice.getAddress().toString().c_str());
        //Serial.println(knownBLEAddresses[i].c_str());
        //Serial.println("*************End**************");
        if (strcmp(advertisedDevice.getAddress().toString().c_str(), knownBLEAddresses[i].c_str()) == 0)
                        {
          device_found = true;
                          break;
                        }
        else
          device_found = false;
      }
      //Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
    }
};
void setup() {
  Serial.begin(115200); //Enable UART on ESP32 AQUI DEFINE A BANDA DO MONITOR SERIAL, TE QUE TROCAR AQUI
  Serial.println("Scanning..."); // Print Scanning
  pinMode(LED_BUILTIN, OUTPUT); //make BUILTIN_LED pin as output
  BLEDevice::init("");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks()); //Init Callback Function
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  pBLEScan->setInterval(1000); // set Scan interval
  pBLEScan->setWindow(99);  // less or equal setInterval value

  WiFi.begin(wifiName,wifiPassword);
  Serial.println("Connecting Wifi")
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  char* listConnected[100]; //Não sei se tá certo

  for (int i = 0; i < foundDevices.getCount(); i++)
  {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);
    int rssi = device.getRSSI();
    Serial.print("RSSI: ");
    Serial.println(rssi);
    if (rssi > RSSI_THRESHOLD && device_found == true)
      digitalWrite(LED_BUILTIN, HIGH); // TODO HTTP REQUEST
      listConnected += rssid; //Não sei se tá certo
      listConnected += "&"; //Não sei se tá certo
    else
      digitalWrite(LED_BUILTIN, LOW);
  }
  
  if((millis() - lastTime) > timerDelay){
    //Initialize HTTP Client
    HTTPClient http;
    String serverPath = serverName + "?alunos=" + rssid; //Não sei se tá certo
    
    http.begin(serverPath.c_str());
    
    //Send Request
    int httpResponseCode = http.GET();
    
    if (httpResponseCode>0){
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString(); //Não vai precisar
      Serial.println(payload);
    }
    else{
      serial.print("Error code ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else{
    Serial.println("WiFi Disconnected");
  }
  lastTime = millis();
  pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
}
