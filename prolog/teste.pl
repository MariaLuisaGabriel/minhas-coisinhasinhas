tira(_,[],[]).
/* tirar o X de X|Z é o mesmo que tirar X de Z, é um mecanismo para, se encontrar um X que é exigido
que tire, ele saia sem voltar ao tirar o próximo X (a cabeça da lista que é o primeiro X
tirado não é apagada se não for feita dessa forma), qualquer coisa, teste (trace) sem essa condição!*/
tira(X,[X|Z],R):-
tira(X,Z,R).
%loop permitido só se a cabeça não for o elemento que quer tirar.
tira(X,[Y|Z],[Y|L1]):-
    X=\=Y,
    tira(X,Z,L1).

%se não há o que ordenar, o resultado é nada.
ordenadireto([],[]).
%passa elemento por elemento até chegar no nada(Z=[]), e dali começa a se inserir(Y, do último elemento até o primeiro) em ordem direta(olhar condições de insere1).
ordenadireto([Y|Z],L):-
ordenadireto(Z,Z1),
insere1(Y,Z1,L).

%se não há o que ordenar, o resultado é nada.
ordenainverso([],[]).
%passa elemento por elemento até chegar no nada(Z=[]), e dali começa a se inserir(Y, do último elemento até o primeiro) em ordem contrária(olhar condições de insere2).
ordenainverso([Y|Z],L):-
ordenainverso(Z,Z1),
insere2(Y,Z1,L).

%insere para qualquer posição.
insere(X,[],[X]).
insere(X,[Y|Z],[X|[Y|Z]]).
insere(X,[Y|Z],[Y|Z1]):-
    insere(X,Z,Z1).

%insere de forma crescente
insere1(X,[],[X]).
%insere quando X<Y.
insere1(X,[Y|Z],[X|[Y|Z]]):-
    X=<Y.
%loop permitido se Y ainda for menor que X.
insere1(X,[Y|Z],[Y|Z1]):-
    X>=Y,
    insere1(X,Z,Z1).

%insere de forma decrescente
insere2(X,[],[X]).
%insere quando X>Y.
insere2(X,[Y|Z],[X|[Y|Z]]):-
    X>=Y.
%loop permitido se X ainda for menor que Y.
insere2(X,[Y|Z],[Y|Z1]):-
    X=<Y,
    insere2(X,Z,Z1).

pertence([],[Y|Z]).
pertence(X,[Y|Z]):-
    X=:=Y.
pertence(X,[Y|Z]):-
    X=\=Y,
    pertence(X,Z).

%o ultimo elemento de uma lista de um elemento é ele mesmo.
ultimo([X],X).
%reduz até uma lista com 1 elemento, que é o ultimo elemento.
ultimo([Y|Z],L):-
ultimo(Z,L).

primeiro([Y|Z],Y).

sublista([],[]).
sublista([Y|Z],[Y|Z]).
sublista([Y|Z],L):-
sublista(Z,L).

%uma permutação é tipo uma ordenação sem uma ordem específica, logo é só inserir de todas as formas possíveis.
permutacao([],[]).
permutacao([Y|Z],L):-
permutacao(Z,X),
insere(Y,X,L).

soma([],0).
soma([Y|Z],R):-
soma(Z,R1),
R is Y+R1.

%pratica dia 18/11
%questao 1
minimo(M,M,M):-!.
minimo(M,N,N):-
M>N,!.
minimo(M,N,M):-
M<N,!.

%questao 2
m(1).
m(2) :- !.
m(3).
/*
1. X=1;X=2.
2. X=Y=1;X=1,Y=2;X=2,Y=1;X=Y=2.
3. X=Y=1;X=1,Y=2.
4. true.
*/

%questao 3
membro3(X,[X|_]):-!.
membro3(X,[_|Ys]) :- membro3(X,Ys).

%questao 4
p(X, Y) :- q(X, Y).
p(a, b).
q(c, d).
q(e, f).
r(e).
r(f).
q(X, Y) :- r(X), !, s(Y). % o ! serve para barrar o processo, depois que prolog vai de r(X) p/ s(X), ele nao tem como voltar para analisar mais possibilidades de r(X), nem para fzr backtrack e analisar outras possibiidades de q(X,Y), como por exemplo onde tem t(X,Y).
q(X, Y) :- t(X, Y).
s(g).
s(h).
t(i, j).

%comando: ?- p(X,Y),write(X). - vai escrevendo o X e escreve os resultados de p(X,Y).
%comando: ?- p(X,Y),write(X),fail. - so escreve o X.
%comando: ?- nl = newline.(q nem \n).

%questao 5
u(a).
u(b).
v(1).
v(2).
v(3).
%o ! faz com que prolog passe uma só vez pelo que está antes dele, se ele está antes de tudo, é como se ! nao existisse. 
w1(X,Y) :- !, u(X), v(Y).
w2(X,Y) :- u(X), !, v(Y). %passa so uma vez por u
w3(X,Y) :- u(X), v(Y), !. %passa so uma vez por u e v
%qualquer coisa, teste o w1, w2 e w3, um por vez.