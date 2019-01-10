
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











<h3>Projetos realizados</h3>

[![Alt text](https://i.ytimg.com/vi/bxiT6m4V0zQ/hqdefault.jpg?sqp=-oaymwEXCNACELwBSFryq4qpAwkIARUAAIhCGAE=&rs=AOn4CLAAS1DTp2p8pIziuU-4SzAAVMacMw)](https://www.youtube.com/watch?v=bxiT6m4V0zQ&list=PLB3JsvtYkUUsx2X43MCU6g3JFl168cwRX)             [![Alt text](https://i.ytimg.com/vi/eRzkdTaYYJM/hqdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLAmyjIfCawxpc4xU8EF_3RDss9i3g)](https://www.youtube.com/watch?v=eRzkdTaYYJM&list=PLB3JsvtYkUUsx2X43MCU6g3JFl168cwRX&index=3&t=0s)







