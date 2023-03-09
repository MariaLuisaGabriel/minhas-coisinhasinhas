:-use_module(library(http/thread_httpd)).
:-use_module(library(http/http_dispatch)).
:-use_module(library(http/http_parameters)).
:-use_module(library(http/html_write)).
:-use_module(library(uri)).
:-use_module(library(http/http_error)).
:-http_handler(root(ackermann),mensagem,[]).
servidor(Porta):-
http_server(http_dispatch,[port(Porta)]).

mensagem(R):-
http_parameters(R,[numero1(N1,[]),numero2(N2,[])]),
string_to_atom(N1,N01),%ESQUECI
string_to_atom(N2,N02),%ESQUECI
atom_number(N01,N11),%ESQUECI
atom_number(N02,N12),%ESQUECI
ack(N11,N12,R1),%PUS R LA EM VEZ DE R1 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA (E É O PARAMETRO DA MENSAGEM HTML AAAAAAAAAAAAAA ;-;)
format('Content-type: text/plain~n~n'),%AAAAAAAAAAAAAAAAA MANO EU VO CHORA EU ESQUECI DESSA FUNÇÃOOOOOOOO
format('resultado: ~n'),
write(R1).

ack(X,Y,Z):-
X=:=0,
Z is Y+1,!.
ack(X,Y,Z):-
Y=:=0,
X1 is X-1,
ack(X1,1,Z),!.
ack(X,Y,Z):-
X1 is X-1,
Y1 is Y-1,
ack(X,Y1,Z1),
ack(X1,Z1,Z).