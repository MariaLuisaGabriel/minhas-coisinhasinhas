:-use_module(library(http/thread_httpd)).
:-use_module(library(http/http_dispatch)).
:-use_module(library(http/http_parameters)).
:-use_module(library(http/html_write)).
:-use_module(library(uri)).
:-use_module(library(http/http_error)).
:-http_handler(root(processa_pedido),mensagem,[]).
:-http_handler(root(cancela_pedido),mensagem2,[]).
:-dynamic(nomeCliente/2).
:-dynamic(telCliente/2).
:-dynamic(pedido/8).
servidor(Porta):-
http_server(http_dispatch,[port(Porta)]).
mensagem(R) :-
http_parameters(R,[nomeCliente(C,[]),telCliente(T,[]),
 emailCliente(E,[]),tamanho(S,[]),
 tipo(Tp,[]),ing(I,[list(char),optional(true)]),
 tempo(H,[]),obs(O,[])]),
reply_html_page(title('Pedido Confirmado!'),
[h1('Seu pedido foi processado!')]),
append('pedidos.pl'),write('pedido('),write('\''),write(C),write('\''),write(','),write(T),write(','),write('\''),write(E),write('\''),write(','),write(S),write(','),write(Tp),write(','),write(I),write(','),write('\''),write(H),
write('\''),write(','),write('\''),write(O),write('\''),write(').'),nl,
told.
mensagem2(J):-
http_parameters(J,[telCliente(T,[])]),
string_to_atom(T,T1),
atom_number(T1,T2),
consult("pedidos.pl"),
findall(T2,pedido(_,T2,_,_,_,_,_,_),L),
(L=[]-> write('erro:pedido inexistente!consulte novamente seu telefone')
;   write('pedido cancelado!'),
    retract(pedido(_,T2,_,_,_,_,_,_)),
    tell('pedidos.pl'),
    listing(pedido/8),
    told).