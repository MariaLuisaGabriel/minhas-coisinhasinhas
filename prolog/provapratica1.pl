/*questao 1*/

inverte([],R,R).
inverte([X|Y],R1,R):-
    insere(X,R1,R2),
    inverte(Y,R2,R).
insere(X,[],[X]).
insere(X,[H|L],[X|[H|L]]).

obtemimpares([],[]):-!.
obtemimpares(L,R):-oi(L,[],R). %função principal

oi([],R1,R):-inverte(R1,[],R2),R = R2,!.
oi([H|C],R1,R):-
    H mod 2 =\= 0,
    insere(H,R1,R2),
    oi(C,R2,R).
oi([H|C],R1,R):-
    H mod 2 =:= 0,
    oi(C,R1,R).

/*questao 2, "soma" é a letra a, e "soma1" é a letra b*/

quadrado(N,X):-X is N*N.
soma(N,R):-soma(N,1,R).
soma(0,R,R):-!.
soma(N,R1,R):-
    quadrado(N,X),
    R2 is R1+(1/X),
    N1 is N-1,
    soma(N1,R2,R).

soma1(0,1):-!.
soma1(N,R):-
    N1 is N-1,
    soma1(N1,R1),
    quadrado(N,X),
    R is R1+(1/X).