
%questao 1.
fat2(0,1).
fat2(1,1).
fat2(2,2).
fat2(N,R):-
N1 is N-2,
fat2(N1,R1),
R is N*R1.

%questao 2.
mn(Y,Y,Y).
mn(M,N,R):-
M=<N,
M1 is M+1,
mn(M1,N,R1),
R is M*R1.

%questao 3.
pred(M,N):-
N is M-1.

succ(M,N):-
N is M+1.

soma(0,N,N).
soma(M,N,R):-
M>=0,
pred(M,M1),
succ(N,N1),
soma(M1,N1,R).

soman(-1,R,P):-
P is R-1.
soman(M,N,R):-
M<0,
succ(M,M1),
pred(N,N1),
soman(M1,N1,R).

%questao 4
%busca descobrir o valor absoluto de um valor.
abs(X,X) :- integer(X), X >= 0.
abs(X,Y) :- integer(Y), Y > 0, X is -Y.
abs(X,Y) :- integer(X), X < 0, Y is -X.

%pega valores entre um A e um B. esse valor é A se A é menor ou igual a B (esse A é levado pra função, para testar se seu valor respeita a igualdade, senão, ele volta pra "entre" e aumenta em uma unidade, e anda na recursividade.)
entre(A, B, A) :- A =< B.
entre(A, B, C) :- A < B, A1 is A+1,
entre(A1, B, C).

%verifica a raiz numerica, primeiro se ela é positiva ou zero, depois ela busca um valor entre 0 e N, e o que satisfazer a igualdade vai para determinar o valor absoluto e dar a resposta.
raiz(N, R) :- N >= 0, entre(0, N, S),
S*S =< N, (S+1)*(S+1) > N,
abs(R,S).

% impedir de sair false no final das respostas: mostrado na questão 5!

%questao 5
/*divisao = divisor, dividendo, resto e quociente.

        dividendo = divisor*quociente + resto.

->por subtracoes sucessivas:

        (dividendo - resto)/divisor = quociente.

        dividendo - divisor*quociente = resto.
*/

r(N,N,0):-!. %resto zero se a divisao é N/N
r(0,N,0):-!. %resto zero se o dividendo é zero
r(M,N,M):- %resto é o proprio elemento se dividendo menor que divisor
N=\=0,
M<N,!.
r(M,N,R):- %resto é o resultado antes de dar negativo de infinitas subtraçoes do dividendo por quociente vezes divisor
M1 is M-N,
M1>=0,
r(M1,N,R1),
R is R1.

q(0,B,0):-!.
q(A,B,R):- %dividendo nao pode ser zero, tirando o resto, as infinitas subtracoes do divisor no dividendo, em quantidade, resultam no quociente
B=\=0,
r(A,B,RE),
A1 is A-B-RE,
A1>=0, %infinitas subtraçoes,podem no minimo resultar em zero(A1 é multiplo de B)
q(A1,B,R1),
R is R1 + 1.%quando A1 é zero, R1 será zero, e a cada subtração dada será adicionada uma unidade

%questao 6
/*
mdc(a,b) = a se b = 0,
mdc(a,b) = mdc(b,a mod b) se b > 0,
mdc(a,b) = mdc(a,-b) se b < 0
*/

mdc(A,0,A):-!.

mdc(A,B,R):-
B>0,
A1 is A mod B,
mdc(B,A1,R),!.

mdc(A,B,R):-
B<0,
mdc(A,-B,R).

%questao 7
%fibs: 0 1 1 2 3 5 8 13 21 34

fibs(0,0):-!.
fibs(N,R) :- fibs(1,N,0,1,R). %primeiro 1: elemento q vai subindo até chegar em N(sobe de posicao até a posicao do elemento escolhido), primeiro 0: auxiliar para a escalada do valor(a partir da posicao 1) do elemento na posicao N, segundo 1:guarda o valor do elemento escalando(R1 é passado para representar a soma do antecessor com o antecessor do antecessor)
fibs(N,N,_,R,R):-!. % quando N0 atinge N, o valor guardado por R1 vai para R
fibs(N0,N,R0,R1,R):- % N0 aumenta, enquanto vai se escalando o valor em R2(R2 = R0 + R1, R3 = R1 + R2...) 
N1 is N0 + 1,
R2 is R0 + R1,
fibs(N1,N,R1,R2,R). %passa para a proxima posicao para somar e guardar o valor, enquanto N1 se aproxima de N.

%questao 8
%valor aproximado da sequencia de taylor(com propagacao de desvio)

fat(0,1):-!.
fat(1,1):-!.
fat(N,R):-
N1 is N-1,
fat(N1,R1),
R is N*R1.

pot(X,N,R):-pot(X,N,1,R).% 10: é uma recursividade de 11 termos: potencias de X de 0 a 10, 1: potencia sendo acumulada.
pot(X,0,Y,Y):-!.
pot(X,N,Y,R):-
N1 is N-1,
Y1 is X*Y,
pot(X,N1,Y1,R).

taylor(0,1):-!.%taylor com X=0 é 1
taylor(X,R):- taylor(X,1,1,1,R). %a potencia, fatorial e a propria sequencia de taylor comecam com 1
taylor(X,10,10,T,T):-!. %quando a potencia atinge 10(recomendado na questao, e coincidentemente o fatorial tb bate 10), o taylor acumulado vira resultado
taylor(X,N,F,T,R):- %a potencia anda 1, o fatorial anda 1, taylor é a soma da potencia/fatorial com ela mesma(iniciando com 1 e escalando o proprio tamanho)
pot(X,N,H),
N1 is N+1,
N1=<10,
fat(F,K),
F1 is F+1,
T1 is T + H//K,
taylor(X,N1,F1,T1,R).