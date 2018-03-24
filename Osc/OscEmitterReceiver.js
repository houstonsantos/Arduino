/**
 * @brief Exemplo de utilização da api osc-emitter e osc-receiver com Arduino usando protocolo OSC.
 * @date 30/05/2016
 * @author Houston Santos
 */

// Carregando módulo
var OscEmitter = require('osc-emitter');
var OscReceiver = require('osc-receiver');

// Criando mensagens OSC
var emitter = new OscEmitter();
var receiver = new OscReceiver();
 
// Recebendo mensagem
receiver.bind(8000);

// Enviando mensagem
emitter.add('192.168.254.71', 9000);
emitter.emit('/HS/escada', 0);
