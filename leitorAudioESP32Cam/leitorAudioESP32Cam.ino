/*
#include <WiFi.h>                 //importa biblioteca para conectar esp32 com wifi
#include <IOXhop_FirebaseESP32.h> //importa biblioteca para esp32 se comunicar com firebase
#include <ArduinoJson.h>          //importa biblioteca para colocar informação no formato json, utilizado no firebase (intalar versão 5)

// fazendo definições para não repetir muito texto durante o código
#define WIFI_SSID "Galaxy A51 7C6A"                // substitua "Nome_do_seu_wifi" pelo nome da sua rede wifi
#define WIFI_PASSWORD "adez6361"           // substitua "Senha_do_seu_wifi" pela senha da sua rede wifi
#define FIREBASE_HOST "https://esp32cambianch-default-rtdb.firebaseio.com"  // substitua "Link_do_seu_banco_de_dados" pelo link do seu banco de dados
#define FIREBASE_AUTH "G6Zdg1WiBv3GSPeV5fyHdjb7KTzZfzL64ZZyKIqx" // substitua "Senha_do_seu_banco_de_dados" pela senha do seu banco de dados
*/
int micVolume = 0;
int i = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  /*WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // inicia comunicação com wifi com rede definica anteriormente

    Serial.print("Conectando ao wifi");   // imprime "Conectando ao wifi"
    while (WiFi.status() != WL_CONNECTED) // enquanto se conecta ao wifi fica colocando pontos
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println(); // imprime pulo de linha

    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); // inicia comunicação com firebase definido anteriormente
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  micVolume = (analogRead(2));
  Serial.println(micVolume);
  //Firebase.setInt("/Som", micVolume);
  delay(50);
}
