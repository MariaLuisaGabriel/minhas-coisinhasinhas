:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- http_handler(root(minha_pagina), mensagem, []).
servidor(Porta) :-
 http_server(http_dispatch, [port(Porta)]).
mensagem(_Request) :-
 format('Content-type: text/plain~n~n'),
 format('Seja bem-vindo!~n').