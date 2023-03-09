:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/http_parameters)).
:- use_module(library(uri)).

:- http_handler(root(processa_pedido), cadastra, []).
:- http_handler(root(cancela_pedido), cancela, []).

:- dynamic(nomeCliente/2).
:- dynamic(telCliente/2).
:- dynamic(pedido/7).

servidor(Porta) :-
 http_server(http_dispatch, [port(Porta)]).

cancela(J):-
reconsult("pedidos.pl"),
http_parameters(J,[nomeCliente(C,[]),emailCliente(K,[])]),
findall(C,pedido(C,_,K,_,_,_,_),L),%se retornar lista vazia, é porque não existe relacionamento que envolva
testar(L,K,C).

testar([],_,_):-
    format('Content-type: text/plain~n~n'),
    format('cadastro inexistente!verifique seu email e/ou nome novamente.~n'),!.

testar([L|_],K,C):-
    format('Content-type: text/plain~n~n'),
    format('cadastro cancelado com sucesso!~n'),
    retract(pedido(C,_,K,_,_,_,_)),
    tell('pedidos.pl'),
    listing(pedido/7),
    told.

cadastra(R) :-
http_parameters(R,
[nomeCliente(C,[]),
telCliente(T,[]),
emailCliente(E,[]),
tamanho(S,[]),
ing1(I0,[list(I0)]),%list(type) retorna lista vazia caso nao se insira nenhum elemento em seu "type"
ing2(I1,[list(I1)]),
ing3(I2,[list(I2)]),
ing4(I3,[list(I3)]),
tempo(H,[]),
obs(O,[])]),
consult("pedidos.pl"),
geralista(I0,I1,I2,I3,L),
(L = [] ->
    format('Content-type: text/plain~n~n'),
    format('ERRO: impossivel de cadastrar por falta de dados, insira os Ingredientes!~n')
;   findall(A,pedido(_,A,_,_,_,_,_),L0),
    length(L0,N),
    append('pedidos.pl'),
    nl,
    write('pedido('),
    write('\''),
    write(C),
    write('\','),
    write(T),
    write(',\''),
    write(E),
    write('\','),
    write(S),
    write(','),
    write(L),
    write(','),
    write(H),
    write(',\''),
    write(O),
    write('\')'),
    write('.'),
    told,
    write('|Nome: '),
    write(C),nl,
    write('|Telefone: '),
    write(T),nl,
    write('|Email: '),
    write(E),nl,
    write('|Tamanho: '),
    write(S),nl,
    write('|Ingredientes: '),
    mostraing(L),nl,
    write('|Tempo: '),
    write(H),nl,
    write('|Obs: '),
    write(O),nl,
    apresentaFila(N)).

geralista([],[],[],[],[]):- !.

geralista(A,B,C,D,L3):-
insere(D,[],L),
insere(C,L,L1),
insere(B,L1,L2),
insere(A,L2,L3),
format('Content-type: text/plain~n~n'),
format('DADOS CADASTRADOS!~n'),
format('==================~n').

insere([],L,L):-!.
insere([X],[],[X]):-!.
insere([X],[Y|Z],[X|[Y|Z]]):-!.

apresentaFila(0):-
    nl,write('|DADOS DA FILA: voce eh o primeiro da fila!'),!.
apresentaFila(N):-
    nl,write('|DADOS DA FILA: ha '),
    write(N),
    write(' cliente(s) a sua frente.'),!.

mostraing([]):-!.
mostraing([X|Y]):-
    write(X),
    (Y = [] -> write('.')
    ;write(',')),
    mostraing(Y).