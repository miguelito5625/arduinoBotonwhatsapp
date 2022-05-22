#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#define LEDVERDE D8     // Pin digital al que esta conectado el led verde
#define LEDAMARILLO D7     // Pin digital al que esta conectado el led amarillo
#define LEDROJO D6     // Pin digital al que esta conectado el led rojo
#define BOTON1 D1     // Pin digital al que esta conectado el led rojo
#define BOTON2 D2     // Pin digital al que esta conectado el led rojo


const char* ssid = "Exbinario";
const char* password = "a1a2a3a4a5";

//Your Domain name with URL path or IP address with path
String serverName = "http://47.252.35.87:3000";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 5000;
int statudLedRojo = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAMARILLO, OUTPUT);
  pinMode(LEDROJO, OUTPUT);
  pinMode(BOTON1, INPUT);
  pinMode(BOTON2, INPUT);

  digitalWrite(LEDROJO, HIGH);


  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LEDROJO, statudLedRojo=!statudLedRojo);
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
  digitalWrite(LEDROJO, LOW);
}

void loop() {

  pedir25();
  pedir35();

}

void pruebaBoton() {

  int  buttonState = digitalRead(BOTON1);

  if (buttonState == HIGH) {

    digitalWrite(LEDVERDE, HIGH);
  } else {

    digitalWrite(LEDVERDE, LOW);
  }

}

void pruebaLeds() {
  digitalWrite(LEDVERDE, HIGH);
  digitalWrite(LEDAMARILLO, HIGH);
  digitalWrite(LEDROJO, HIGH);
  delay(1000);
  digitalWrite(LEDVERDE, LOW);
  digitalWrite(LEDAMARILLO, LOW);
  digitalWrite(LEDROJO, LOW);
  delay(1000);
}



void pedir25() {

  int  button1State = digitalRead(BOTON1);

  if (button1State == HIGH) {

    digitalWrite(LEDAMARILLO, HIGH);
    delay(500);
    digitalWrite(LEDAMARILLO, LOW);
    delay(500);
    digitalWrite(LEDAMARILLO, HIGH);
    delay(500);
    digitalWrite(LEDAMARILLO, LOW);
    delay(500);
    digitalWrite(LEDAMARILLO, HIGH);
    delay(1500);

    // Send an HTTP POST request depending on timerDelay
    if ((millis() - lastTime) > timerDelay) {
      //Check WiFi connection status
      if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;

        String serverPath = serverName + "/pedir25";



        // Your Domain name with URL path or IP address with path
        http.begin(client, serverPath.c_str());

        // Send HTTP GET request
        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
          String payload = http.getString();
          Serial.println(payload);

          digitalWrite(LEDVERDE, HIGH);
          digitalWrite(LEDAMARILLO, LOW);
          delay(2000);
          digitalWrite(LEDVERDE, LOW);

        }
        else {
          Serial.print("Error code: ");
          Serial.println(httpResponseCode);
        }
        // Free resources
        http.end();
      }
      else {
        Serial.println("WiFi Disconnected");
      }
      lastTime = millis();
    }


  }



}


void pedir35() {

  int  button2State = digitalRead(BOTON2);

  if (button2State == HIGH) {

    digitalWrite(LEDAMARILLO, HIGH);
    delay(500);
    digitalWrite(LEDAMARILLO, LOW);
    delay(500);
    digitalWrite(LEDAMARILLO, HIGH);
    delay(500);
    digitalWrite(LEDAMARILLO, LOW);
    delay(500);
    digitalWrite(LEDAMARILLO, HIGH);
    delay(1500);

    // Send an HTTP POST request depending on timerDelay
    if ((millis() - lastTime) > timerDelay) {
      //Check WiFi connection status
      if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;
        HTTPClient http;

        String serverPath = serverName + "/pedir35";



        // Your Domain name with URL path or IP address with path
        http.begin(client, serverPath.c_str());

        // Send HTTP GET request
        int httpResponseCode = http.GET();

        if (httpResponseCode > 0) {
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
          String payload = http.getString();
          Serial.println(payload);

          digitalWrite(LEDVERDE, HIGH);
          digitalWrite(LEDAMARILLO, LOW);
          delay(2000);
          digitalWrite(LEDVERDE, LOW);

        }
        else {
          Serial.print("Error code: ");
          Serial.println(httpResponseCode);
        }
        // Free resources
        http.end();
      }
      else {
        Serial.println("WiFi Disconnected");
      }
      lastTime = millis();
    }


  }



}
