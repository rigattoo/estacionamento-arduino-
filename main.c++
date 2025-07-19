#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TRIG_PIN 3
#define ECHO_PIN 2
#define BUZZER_PIN 4
#define SERVO_PIN 9

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Servo cancela;
int vaga = 5;

void setup() {
Serial.begin(9600);
  
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(BUZZER_PIN, OUTPUT);

cancela.attach(SERVO_PIN);
cancela.write(0); // Cancela fechada
  
if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
Serial.println("Erro no display OLED");
while (true);

}

display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
mensagem("Sistema Pronto\nAguardando Veiculo");
}

void loop() {
  long distancia = medirDistancia();

  if (distancia < 10 && vaga > 0) {
 tone(BUZZER_PIN, 1000, 200); // Som curto
  mensagem("Veiculo Detectado\nAbrindo Cancela");

 cancela.write(90); // Abrir cancela
 delay(5000);
  cancela.write(0); // Fechar cancela


 vaga--;
 if (vaga > 0) {
  mensagem("Acesso Liberado\nVaga Disponivel: " + String(vaga));
  } else {
  mensagem("Estacionamento\nLotado");
  }

  delay(2000);
  mensagem("Sistema Pronto\nEstacionamento lotado");
   mensagem("Acesso Liberado\nVaga Disponivel: " + String(vaga));
  }


  else {
    tone(BUZZER_PIN, 1000, 200); // Som curto
    mensagem("Acesso Liberado\nVaga Disponivel: " + String(vaga));
  }
  
  delay(500);
}

long medirDistancia() {
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
long duracao = pulseIn(ECHO_PIN, HIGH);
long distancia = duracao * 0.034 / 2;
return distancia;
}

void mensagem(String texto) {

display.clearDisplay();
display.setCursor(0, 0);
display.println(texto);
display.display();
}