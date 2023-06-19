%1)
estrada('A','B','A',150).
estrada('B','A','B',90).
estrada('C','B','C',211).
estrada('D','G','A',300).
estrada('E','B','D',50).
estrada('F','B','E',89).
estrada('G','A','G',187).
estrada('H','D','H',254).
estrada('I','F','I',621).
estrada('J','C','J',300).
estrada('K','I','J',41).
estrada('L','D','L',99).
estrada('M','H','M',148).
estrada('N','P','M',163).
estrada('O','P','N',69).
estrada('P','P','L',10).
estrada('Q','J','L',364).
estrada('R','R','L',79).
estrada('S','L','O',193).
estrada('T','p','P',311).
estrada('U','p','R',577).
estrada('V','N','P',150).
estrada('X','A','D',100).

percursos():-
    rotas('A'),!.

rotas('Y'):-!.

rotas(R):-
    estrada(R,I,F,C),
    write(I),write(' -> '),write(F),write(', '),writeln(C),
    char_code(R,R1),
    R2 is R1+1,
    char_code(R3,R2),
    rotas(R3),!.

rotas(R):-
    not(estrada(R,_,_,_)),
    char_code(R,R1),
    R2 is R1+1,
    char_code(R3,R2),
    rotas(R3),!.
