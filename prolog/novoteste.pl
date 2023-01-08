/*
Cada fato ator/4 é composto por:
1. argumento (ator): nome completo do ator colocado (entre apóstrofos);
2. argumento (filme): nome completo do filme (entre apóstrofos);
3. argumento (data): ano de lançamento do filme (número inteiro);
4. argumento (rank): o rank (colocação) do ator no filme, de acordo com os
créditos (por exemplo,1 se protagonista ou 0 se não recebeu créditos).
*/

inicio:-
    escreve_menu,
    le_escolha(Op),
    executa(Op).

escreve_menu:-
    write('1-lista atores;'),
    write('2-adiciona ator;'),
    write('3-remove ator;'),
    write('4-sair.').

le_escolha(Op):-
    write('digite sua opcao: '),
    le_atomo(Op).

%leitura de um valor sem necessidade de um ponto:
le_atomo(Atomo) :-
le_str(String),
name(Atomo, String).

le_str(String) :-
get0(Char),
le_str_aux(Char, String).

le_str_aux(-1, []) :- !. % EOF
le_str_aux(10, []) :- !. % EOL(UNIX)
le_str_aux(13, []) :- !. % EOL (DOS)

le_str_aux(Char, [Char|Resto]) :-
le_str(Resto).

%fim do código da leitura sem precisar de ponto

executa(Op):-
    Op =:= 1,
    see(help),
    processaArquivo,
    seen.
    
processaArquivo:-
    read(ator(X,_,_,_)),
    processa(X).

processa(end_of_file):-!.
processa(X):-
    write(X),
    processaArquivo.

executa(Op):-
    Op =:= 2,
    see(help),
    escreveArquivo,
    seen.

escreveArquivo:-
    write('nome do ator : '),
    read(X),nl,
    write('nome do filme:'),
    read(Y),nl,
    write('ano do filme: '),
    read(Z),nl,
    write('ranking do filme: '),
    read(W),nl,
    see(help),
    le_arq,
    seen,
    tell(help),
    assertz(ator(X,Y,Z,W)),
    told.

le_arq:-
    read(X),
    le(X).

le(end_of_file):-!.
le(X):-
    le_arq.

executa(Op):-
    Op =:= 3,
    see(help),
    removeLinha,
    seen.

removeLinha:-
    

executa(Op):-
    Op=:=4,
    !.