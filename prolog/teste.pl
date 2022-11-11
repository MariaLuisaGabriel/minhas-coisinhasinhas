telefone(maria, 123).
telefone(joaquim, 234).
telefone(marco, 345).
telefone(pedro, 456).
telefone(ana, 567).
telefone(juliana, 678).

visita(juliana, maria).
visita(ana, joaquim).
visita(marco, juliana).
visita(pedro, juliana).

emCasa(joaquim).
emCasa(maria).

acompanhado(X):-
    visita(_,X).

inconsistente:-
    visita(X,_),
    emCasa(X).

/* para quem esta na casa do amigo */
em_casa_de(Y,X):-
    visita(Y,X),
    emCasa(X).
/* para quem esta na casa do amigo, que esta na casa do amigo, que esta.... (depende das instancias)*/
em_casa_de(Y,X):-
    visita(Y,Z),
    em_casa_de(Z,X).
/* contato do X é o seu próprio (Y), caso ele esteja em sua propria casa*/
contato(X,Y):-
    emCasa(X),
    telefone(X,Y).
/* contato de X é o da casa em que ele está(Y), que é a casa de Z. ele pode estar visitando alguem, que esta visitando alguem.... (depende da instancia)*/
contato(X,Y):-
    em_casa_de(X,Z),
    telefone(Z,Y).
/* para ser festeiro, tem de se garantir 3 pessoas na casa, entao Z e Y devem estar na casa de X (nao importa a instancia, entao nao importa se entrar em recursividade), incluindo X.*/
festeiro(X):-
    em_casa_de(Y,X),
    em_casa_de(Z,X),
    Y\==Z.
/* use true e false nos termos */
/* prova retornará true se X=true, e false se X=false, ele será true ou false dependendo doq tem dentro dele, no caso, das funcoes que serao substituidas la*/
falso:-
    false.
verdade:-
    true.
prova(X):-
    X.
e(X,Y):-
    X,Y.
ou(X,Y):-
    X;Y.
nao(X):-
    not(X).
impl(X,Y):-
    not(X);Y.
equiv(X,Y):-
    impl(X,Y),
    impl(Y,X).

p(a).
p(b).
p(d).
q(a).
q(c).
q(d).
r(x) :- p(x),q(x).
s(X) :- q(X).
s(X) :- p(X).

a(1,1). 
a(2,1). 
a(3,2). 
a(4,4). 
b(1,2).
b(1,3).
b(2,3).
b(3,2).
b(4,4).

r(a,b). 
r(a,c). 
r(b,a). 
r(a,d). 
s(b,a).
s(b,d).
s(c,a).
s(c,c).
s(d,a).

u(a,b).
u(b,b).
u(c,d).
u(c,a).
u(d,a).
u(d,c).

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