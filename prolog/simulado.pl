%meu simuladinho para a prova 1
%questao 1:converta uma lista em binário para uma lista em octal.

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

decimal(L2,N):- decimal(L2,2,0,N).
decimal([],_,N,N):-!.
decimal([X|Y],N1,S,N):-
pot2(N1,N2),
S1 is (X*N2)+S,
N3 is N1-1,
decimal(Y,N3,S1,N).

octal(L,R1,R2):-
decimal(L,N),
insere(N,R1,R2).

converte(L,R):-tam(L,0,N),converte(L,N,R).

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

%questao 2:converta binario para grey
