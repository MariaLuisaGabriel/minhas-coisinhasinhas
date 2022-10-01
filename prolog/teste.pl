homem(eduardo).
homem(silvio).
mulher(maria).
mulher(silvia).
pais(eduardo,silvio,silvia).
pais(maria,silvio,silvia).
irmao_de(X,Y) :-
    mulher(X),
    homem(Y),
    pais(X,M,P),
    pais(Y,M,P).
a(b).