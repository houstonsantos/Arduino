
![alt text](https://github.com/houstonsantos/Arduino/blob/master/img/iot.png "Logo Title Text 2")


 <h1>IoT - Arduino</h1>
   
Projetos de IoT usando sensores, atuadores e diferentes conexões como bluetooth (serial) e TCP/IP, com protocolos http, OSC, WebSocket, MQTT e etc. Bibliotecas como JohnnyFive com NodeJS fazendo uso do JavaScript e outras liguagens, a intensão e demostrar diversas possibilidades de integrações entre divices e plataformas.


* **Projetos** 

    * DisplayLcd 
    * DisplayLcdSerial
    * EntradaAnalogicaSaidaPwm
    * JohnnyFive
    * LeituraSeria
    * Osc
    * OscLed
    * OscLedInterruptor
    * OscLedRgbDimmer
    * PushButonPullDown
    * PushButonPullUp
    * SensorPir

### DisplayLcd

Exemplo de utilização de um display lcd 16x2 com movimentação do texo.


### DisplayLcdSerial

Imprimindo em um display lcd 16x2 a leitura da porta serial. Será impresso no display o que for digitado no teclado. 

❗️ Montagem do ```display 16x2```:

![alt text](https://github.com/houstonsantos/Arduino/blob/master/img/display.png "Display")


### EntradaAnalogicaSaidaPwm

Leitura Analógica Mapeada para uma saída PWM - Este exemplo mostra como ler um pino de uma entrada analógica, mapear 
o resultado para um intervalo de 0 a 255, e usar esse resultado para definir a modulação PWM de um pino de saída 
para acender e apagar um LED como um dímer. Note que as entradas analógicas do Arduino têm uma resolução de 10 bits	
(valores de 0 a 1023) mas as saídas analógicas por PWM têm uma resolução de 8 bits (valores de 0 a 255). É por isso 
que é necessária a função 'map', para "mapear" os valores de modo que se mantenham proporcionais.

```C
 outputValue = map(sensorValue, 0, 1023, 0, 255);
 ```

 ### JohnnyFive

Exemplo de utilização do modulo johnny-five com Arduino via serial, para controlo das portas digitais. 

❗️ Você deve ter o [Nodejs](https://nodejs.org/en/) e o gerenciador de pacotes do node o [npm](https://www.npmjs.com/) instalados, para instalar o modulos do arquivo packge.json use o comando:

 ```javascript
 npm install
 ```

 ### LaituraSerial

 Imprime na porta serial o valor lido da porta do Arduino associada ao led.


### OscLed

Acionamento de led com utilização do protocolo [OSC](https://es.wikipedia.org/wiki/OpenSound_Control) para comunicação com o Arduino via tcp/ip. 

❗️ Informe aqui o mac dos seu  e o ip que desejar(disponivél) na faixa de sua rede.

```C
// IP & MAC para shield ethernet 
byte myMac[] = { 0x90, 0xA2, 0xDA, 0x0F, 0x2C, 0xDE };				
byte myIp[] = { 192, 168, 25, 155 };
```


### Osc

Neste projeto temos 3 experimentos usando JavaScript com algumas bilbiotecas(modulos) do Nodejs, usando comunicação serial e tambem um WebService 

```
.
├── NodeOsc.js
├── OscEmitterReceiver.js
└── ServerOscArduino.js

0 directories, 3 files
```

### OscLed
### OscLedInterruptor
### OscLedRgbDimmer
### SensorPir

Led acendera quando houver movimento no sensor Pir. 










<h3>Projetos realizados</h3>

[![Alt text](https://i.ytimg.com/vi/bxiT6m4V0zQ/hqdefault.jpg?sqp=-oaymwEXCNACELwBSFryq4qpAwkIARUAAIhCGAE=&rs=AOn4CLAAS1DTp2p8pIziuU-4SzAAVMacMw)](https://www.youtube.com/watch?v=bxiT6m4V0zQ&list=PLB3JsvtYkUUsx2X43MCU6g3JFl168cwRX)             [![Alt text](https://i.ytimg.com/vi/eRzkdTaYYJM/hqdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLAmyjIfCawxpc4xU8EF_3RDss9i3g)](https://www.youtube.com/watch?v=eRzkdTaYYJM&list=PLB3JsvtYkUUsx2X43MCU6g3JFl168cwRX&index=3&t=0s)







