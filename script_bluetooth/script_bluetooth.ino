#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
String knownBLEAddresses[] = {"8c:d9:d6:4b:4d:41" ,"aa:bc:cc:dd:ee:ee", "54:2c:7b:87:71:a2","A8:16:D0:7E:97:D0","6e:ee:ee:ac:39:48", "E0:5F:5E:ED:7F:8D", "49:f0:cc:dd:e6:9c", "e0:5f:5e:ed:7f:8d", "45:d5:89:cd:3d:19"};
int RSSI_THRESHOLD = -55;
bool device_found;
int scanTime = 5; //In seconds
int LED_BUILTIN = LOW;

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
}
void loop() {
  // put your main code here, to run repeatedly:
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  for (int i = 0; i < foundDevices.getCount(); i++)
  {
    BLEAdvertisedDevice device = foundDevices.getDevice(i);
    int rssi = device.getRSSI();
    Serial.print("RSSI: ");
    Serial.println(rssi);
    if (rssi > RSSI_THRESHOLD && device_found == true)
      digitalWrite(LED_BUILTIN, HIGH); // TODO HTTP REQUEST
    else
      digitalWrite(LED_BUILTIN, LOW);
  }
  pBLEScan->clearResults();   // delete results fromBLEScan buffer to release memory
}
