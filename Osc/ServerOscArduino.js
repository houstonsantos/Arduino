/**
 * @brief Web Service de comunicação com app cliente. Arduino usando protocolo OSC via tcp/ip.
 * @date 30/05/2016
 * @author Houston Santos
 */

// Carregando módulos
var http = require('http');
var OscEmitter = require('osc-emitter');
var OscReceiver = require('osc-receiver');

// Criando mensagens OSC
var emitter = new OscEmitter();
var receiver = new OscReceiver();
receiver.bind(8000);

// Definindo variável Data
var date = (new Date()).toJSON();

// Variáveis com mensagens de SUCESSO E ERRO de comunicação com Web Service
var SUCCESS = {version: '1.0', autor: 'Houston Santos', returned_at: date};
var ERRO = {message: "Não encontrado"};

// Criando o server http, podemos usar (request, response) ou (req, res)
http.createServer(function(req, res) {
	if(req.url === '/led/liga') {
		res.writeHead(200, {"Content-Type": "application/json; charset = utf-8"});
		res.write(JSON.stringify(SUCCESS));
		emitter.add('192.168.254.71', 9000);
		emitter.emit('/HS/escada', 1);
	}

	else {
		res.writeHead(404, {"Content-Type": "application/json; charset = utf-8"});
		res.write(JSON.stringify(ERRO));	
	}
	res.end();

// Abilitando o server na porta 3000		
}).listen(3000, function() {
	console.log('Servidor rodando em localhost:3000');
});
