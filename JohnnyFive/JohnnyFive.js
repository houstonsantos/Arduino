/**
 * @brief Exemplo de utilização do modulo johnny-five com Arduino via serial. 
 * @date 30/05/2016
 * @author Houston Santos
 */

// Carregando módulo
var five = require("johnny-five");

// Crinado novo objeto do tipo placa
var board = new five.Board();

// Led pincando a 500 milissegundo
board.on("ready", function() {
  var led = new five.Led(13);
  led.blink(500);
});