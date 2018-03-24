/**
 * @brief Exemplo de utilização da api node-osc com Arduino usando protocolo OSC.
 * @date 30/05/2016
 * @author Houston Santos
 */

// Carregando módulo
var osc = require('node-osc');

// Cliente e Servidor OSC
var client = new osc.Client('192.168.25.245', 9000);
var oscServer = new osc.Server(8000, '0.0.0.0');

// Enviado mensagem
client.send('/HS/escada', 0, function () {
client.kill();
});

// Recebendo mensagem
oscServer.on("message", function (msg, rinfo) {
    console.log("TUIO message:");
    console.log(msg);
});
