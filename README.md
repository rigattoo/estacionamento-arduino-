# Sistema de Estacionamento Inteligente com Arduino

Este repositório contém o código Arduino para um sistema de estacionamento inteligente que automatiza o acesso a um estacionamento com base nas vagas disponíveis. O sistema utiliza um sensor ultrassônico para detectar veículos, um servo motor para controlar uma cancela, um buzzer para feedback de áudio e um display OLED para mostrar informações em tempo real.

---

## 🚀 Funcionalidades

* **Detecção de Veículos:** Utiliza um sensor ultrassônico para detectar a presença de veículos na entrada.
* **Cancela Automatizada:** Controla um servo motor para abrir e fechar uma cancela para o acesso de veículos.
* **Gerenciamento de Vagas:** Monitora as vagas de estacionamento disponíveis e restringe o acesso quando o estacionamento está lotado.
* **Feedback Visual:** Um display OLED mostra o status do sistema, detecção de veículos, mensagens de acesso e vagas de estacionamento disponíveis.
* **Alertas Sonoros:** Um buzzer emite bipes curtos para detecção de veículos e ações do sistema.

---

## 🛠️ Componentes Utilizados

* **Arduino Uno:** O microcontrolador principal do sistema.
* **Sensor Ultrassônico HC-SR04:** Detecta a distância de objetos (veículos).
* **Servo Motor SG90:** Atua como a cancela do estacionamento.
* **Buzzer:** Fornece feedback sonoro.
* **Display OLED SSD1306 (128x64):** Exibe informações do sistema.
* **Protoboard e Jumpers:** Para conectar os componentes.

---

## 🔌 Diagrama de Circuito (Conexões)

Para configurar o hardware, siga estas conexões:

* **Sensor Ultrassônico HC-SR04:**
    * `VCC` $\rightarrow$ Arduino `5V`
    * `GND` $\rightarrow$ Arduino `GND`
    * `TRIG_PIN` $\rightarrow$ Pino Digital Arduino `3`
    * `ECHO_PIN` $\rightarrow$ Pino Digital Arduino `2`

* **Buzzer:**
    * `Terminal Positivo (+)` $\rightarrow$ Pino Digital Arduino `4`
    * `Terminal Negativo (-)` $\rightarrow$ Arduino `GND`

* **Servo Motor SG90:**
    * `Fio Vermelho (VCC)` $\rightarrow$ Arduino `5V`
    * `Fio Marrom (GND)` $\rightarrow$ Arduino `GND`
    * `Fio Laranja (Sinal)` $\rightarrow$ Pino Digital Arduino `9`

* **Display OLED SSD1306 (I2C):**
    * `VCC` $\rightarrow$ Arduino `5V`
    * `GND` $\rightarrow$ Arduino `GND`
    * `SDA` $\rightarrow$ Arduino `A4` (ou pino SDA dedicado em alguns Arduinos)
    * `SCL` $\rightarrow$ Arduino `A5` (ou pino SCL dedicado em alguns Arduinos)

---

## 💻 Software Requisitos

* **Arduino IDE:** Baixe e instale no [site oficial do Arduino](https://www.arduino.cc/en/software).
* **Bibliotecas:**
    * `Servo.h`: Biblioteca padrão do Arduino para controle de servo motores.
    * `Wire.h`: Biblioteca padrão do Arduino para comunicação I2C (necessária para o OLED).
    * `Adafruit GFX Library`: Biblioteca gráfica principal para displays Adafruit.
    * `Adafruit SSD1306 Library`: Driver para o display OLED SSD1306.

Para instalar as bibliotecas: Abra a Arduino IDE $\rightarrow$ Sketch $\rightarrow$ Incluir Biblioteca $\rightarrow$ Gerenciar Bibliotecas... Pesquise por "Adafruit GFX" e "Adafruit SSD1306" e instale-as.

---

## 🚀 Como Usar

1.  **Conecte os Componentes:** Monte seu circuito de acordo com a seção "Diagrama de Circuito".
2.  **Abra o Código:** Abra o arquivo `arduino_parking_system.ino` (o código que você forneceu) na Arduino IDE.
3.  **Instale as Bibliotecas:** Certifique-se de ter instalado todas as bibliotecas necessárias (veja "Requisitos de Software").
4.  **Selecione a Placa e a Porta:** Na Arduino IDE, vá em `Ferramentas` $\rightarrow$ `Placa` e selecione "Arduino Uno". Em seguida, vá em `Ferramentas` $\rightarrow$ `Porta` e selecione a porta serial conectada ao seu Arduino.
5.  **Carregue o Código:** Clique no botão "Carregar" (ícone de seta para a direita) na Arduino IDE para compilar e carregar o código para o seu Arduino Uno.
6.  **Operação:**
    * O sistema exibirá "Sistema Pronto\nAguardando Veiculo".
    * Quando um veículo for detectado pelo sensor ultrassônico (distância menor que 10 cm) e houver vagas disponíveis, a cancela abrirá por 5 segundos e depois fechará.
    * As vagas de estacionamento disponíveis serão decrementadas, e o display será atualizado com a nova contagem.
    * Se o estacionamento estiver lotado, o display mostrará "Estacionamento\nLotado" e o acesso será negado.
    * Um breve bipe soará ao detectar um veículo.

---

## ⚙️ Configuração

* **Variável `vaga`:** Na função `setup()`, você pode alterar o número inicial de vagas de estacionamento disponíveis modificando a variável `vaga`:
    ```cpp
    int vaga = 5; // Altere este valor para definir o número total de vagas de estacionamento
    ```

