%meu simuladinho para a prova 1
%questao 1:converta uma lista em binário para uma lista em octal.

tam(L,N):-tam(L,0,N).
tam([],R,R):-!.
tam([X|Y],N,R):-
N1 is N+1,
tam(Y,N1,R).

insere(X,[],[X]):-!.
insere(X,[Y|Z],[X|[Y|Z]]).

inverte(L,L1):- inverte(L,[],L1).
inverte([],L1,L1):-!.
inverte([Y|X],L2,L1):-
insere(Y,L2,L3),
inverte(X,L3,L1).

corrige(L,N,R):-
insere(0,L,L1),
N1 is N+1,
converte(L1,N1,R).

separa(L,N,L1,L3):- separa(L,N,0,[],L1,L3).
separa(L,N,N,L2,L2,L):-!.
separa([X|Y],N,N1,L2,L1,L3):-
N2 is N1+1,
insere(X,L2,L4),
separa(Y,N,N2,L4,L1,L3).

pot2(0,1):-!.
pot2(P,R):-
P1 is P-1,
pot2(P1,R1),
R is 2*R1.

decimal(L,N1,N):-decimal(L,N1,0,N).
decimal([],_,N,N):-!.
decimal([X|Y],N1,S,N):-
pot2(N1,N2),
S1 is (X*N2)+S,
N3 is N1-1,
decimal(Y,N3,S1,N).

octal(L,R1,R2):-
decimal(L,2,N),
insere(N,R1,R2).

converte(L,R):-tam(L,N),converte(L,N,R).

converte(L,N,R):-
N mod 3 =\= 0,
corrige(L,N,R),!.

converte(L,N,R):- N mod 3 =:= 0,inverte(L,L1),converte(L1,N,[],R).

converte([],0,R,R):-!.
converte(L,N,R1,R):-
N mod 3 =:= 0,
separa(L,3,L1,L3),
octal(L1,R1,R2),
N1 is N-3,
converte(L3,N1,R2,R).

%questao 2: converta de binario para gray, de 3 em 3 bits

inseremult([H|[H1|[H2]]],L,R):-%inserçao de 3 elementos diretão
    insere(H2,L,L1),
    insere(H1,L1,L2),
    insere(H,L2,R).

soma(M,N,0):-M=:=N,!.
soma(M,N,1):-M=\=N,!.
gray([H1|[H2|[H3]]],[H1|[R1|[R2]]]):-
    soma(H1,H2,R1),
    soma(H2,H3,R2).

convgray(L,R):- tam(L,N),convgray(L,N,[],R).

convgray(L,N,R1,R):-
N mod 3 =\= 0,
insere(0,L,L1),
N1 is N+1,
convgray(L1,N1,R1,R).

convgray(L,N,R1,R):- inverte(L,L1),convgrayI(L1,N,R1,R).

convgrayI([],0,R,R):-!.
convgrayI(L,N,R1,R):-
    separa(L,3,L1,L2),
    gray(L1,L3),
    inseremult(L3,R1,R2),
    N1 is N-3,
    convgrayI(L2,N1,R2,R).

%questao 4: converta uma lista de 2 bits p/ decimal e depois p/ alfabeto(ou seja, 2 retornos).

alf(0,a).
alf(1,b).
alf(2,c).
alf(3,d).
ba(L,N,A):-
decimal(L,1,N),
alf(N,A).

%questao 5: receba uma lista e devolva outra que é resultado da soma de pares da lista dada.

pares(L,R):-tam(L,N),inverte(L,L1),separa(L1,1,H,L2),pares(H,N,L2,[],R).
pares(_,1,[],R,R):-!.
pares(H,N,[H1|L3],R1,R):-
    J is H+H1,
    insere(J,R1,R2),
    N1 is N-1,
    pares(H1,N1,L3,R2,R).

%questao 6: receba uma lista e a divida numa lista so de pares e uma so de impares.(2 retornos)

pi(L,P,I):-inverte(L,L1),par(L1,P),impar(L1,I),!.
par(L,P):-par(L,[],P).
impar(L,I):-impar(L,[],I).
par([],P,P):-!.
impar([],I,I):-!.
par([H|L1],P1,P):-
    H mod 2 =:= 0,
    insere(H,P1,P2),
    par(L1,P2,P).
par([H|L1],P1,P):-
    H mod 2 =\= 0,
    par(L1,P1,P).
impar([H|L1],I1,I):-
    H mod 2 =\= 0,
    insere(H,I1,I2),
    impar(L1,I2,I).
impar([H|L1],I1,I):-
    H mod 2 =:= 0,
    impar(L1,I1,I).

%questao 9: gere uma lista de 5 elementos pseudoaleatorios, com classe de aleatoriedade(m) escolhida pelo usuario.
%pseudo-aleatoriedade, fórmula: Xn+1 = (aXn+c) mod m.
%para essa questão, c=0(crescendo) e a=1234, Xn=1(crescendo). (padrões)

aleatorio(M,R):-aleatorio(M,1,0,5,0,[],R).

aleatorio(M,X,_,N,N,R,R):-!.

aleatorio(M,X,C,N,N1,R1,R):-
X1 is (1234*X + C) mod M,
insere(X1,R1,R2),
N2 is N1+1,
C1 is C+1,
aleatorio(M,X1,C1,N,N2,R2,R).
