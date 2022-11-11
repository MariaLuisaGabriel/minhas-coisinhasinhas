
%questao 1.
fat(0,1).
fat(1,1).
fat(2,2).
fat(N,R):-
N1 is N-2,
fat(N1,R1),
R is N*R1.

%questao 2.
mn(Y,Y,Y).
mn(M,N,R):-
M=<N,
M1 is M+1,
mn(M1,N,R1),
R is M*R1.

%questao 3.
succ(M,N):-
N is M+1.
pred(M,N):-
N is M-1.
soma(M,0,M).
soma(0,M,M).
soma(M,M,R):-
R is M+M.
soma(M,N,R):-
M1 is M+1,
M1<M+M+1,
succ(N,R1),
R is R1.
