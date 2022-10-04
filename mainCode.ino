#include <DFRobot_SIM808.h>
#include <sim808.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#include <addons/RTDBHelper.h>

#define WIFI_SSID "sim808"
#define WIFI_PASSWORD "informatika"

#define DATABASE_URL "tugasakhir-a4150-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long dataMillis = 0;

DFRobot_SIM808 sim808(&Serial);//Connect RX,TX,PWR,


int halleffect = D0;
int hitung = 0; //kondisi awal perhitungan rotasi
int kondisi1 = 0; //kondisi awal keberadaan magnet (tidak ada)
int status1; //kondisi dari hall effect
String hasil; //menyimpan nilai rotasi

String the_year, the_month, the_day , the_minute, the_second, the_time;
int the_hour;
String latitude, longitude;
String rotasi;
String values;
String date;

void setup() {
   
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  config.database_url = DATABASE_URL;
  config.signer.test_mode = true;

  Firebase.reconnectWiFi(true);
  Firebase.begin(&config, &auth);

   while(!sim808.init()) { 
       delay(100);
       Serial.print("Sim808 init error\r\n");
   }
}

void loop() {
//************** Get GPS data *******************
  if (sim808.getGPS()) {
        latitude = String(sim808.GPSdata.lat, 6);
        longitude = String(sim808.GPSdata.lon, 6);
        the_year = sim808.GPSdata.year;
        the_month = sim808.GPSdata.month;
        the_day = sim808.GPSdata.day;

        date = (String)sim808.GPSdata.year + "/" + (String)sim808.GPSdata.month + "/" + (String)sim808.GPSdata.day + " " + (String)sim808.GPSdata.hour + ":" + (String)sim808.GPSdata.minute + ":" + (String)sim808.GPSdata.second;
        
        bacaHallefect();
        tampilSerial();
        kirimFirebase();

  }
}
   
  
        
