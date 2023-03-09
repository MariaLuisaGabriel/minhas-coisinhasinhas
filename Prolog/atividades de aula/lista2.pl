
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

/*soma(0,N,N).
soma(M,N,R):-
M>=0,
pred(M,M1),
succ(N,N1),
soma(M1,N1,R).*/

soma(M,N,R):-soma(M,0,N,R).
soma(M,M,N,N).
soma(M,M0,N,R):-
M1 is M0+1,
succ(N,N1),
soma(M,M1,N1,R).

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

/*FUNÇÕES DAQUELAS QUESTAO MT DOIDA DO PROF*/

%decimal -> "binario".

par(X):- (X mod 2) =:= 0.
impar(X):- not(par(X)).

%separa a cabeça da lista em uma unica variavel
tira([Y|Z],Y).

%varre a funçao ate chegar em lista vazia, e a cada vez que se ignora uma cabeça, se acrescenta 1 num contador (quando se chega a lista vazia, o valor do contador é dado como resposta para o tamanho da lista)
qtdd(Z,T):-qtdd(Z,T,0).
qtdd([],T,T).
qtdd([X|W],T,T1):-
T2 is T1+1,
qtdd(W,T,T2).

%faz uma varredura na lista dada T vezes, e a cada passo, se guarda em uma variavel uma copia da cabeça da lista analisada (se a funçao chegar em T, a cabeça guardada é a resposta da funçao)
buscaelemento(T,[Y|Z],R):-buscaelemento(T,0,[Y|Z],[],R).
buscaelemento(T,T,_,R,R).
buscaelemento(T,T1,[Y|Z],R1,R):-
T2 is T1+1,
tira([Y|Z],R2),
buscaelemento(T,T2,Z,R2,R).

%só coloca do lado mais esquerdo o novo elemento
insere(X,[],[X]).
insere(X,[Y|Z],[X|[Y|Z]]).

%insere X vezes em R1, se R1 esta vazia, usa a base 1 do insere, caso contrario, usa a base 2 do insere até chegar em X vezes
insira(Y,X,R1,R):-insira(Y,X,0,R1,R).
insira(Y,X,X,R,R).
insira(Y,X,X1,R1,R):-
X2 is X1+1,
insere(Y,R1,R2),
insira(Y,X,X2,R2,R).

%a funcao bin se divide em primeira cabeça, cauda, tamanho da cauda e resultado
bin([Y|Z],R):-qtdd(Z,T),bin(Y,Z,T,R).

%como mechemos do fim para o inicio da cauda, é importante saber qual o conteúdo do ultimo conjunto de numeros(1 ou 0), o que depende do comprimento da cauda
bin(Y,Z,T,R):-Y=:=0,par(T),Y1 is 1,bin(Y1,Z,T,[],R),!.
bin(Y,Z,T,R):-Y=:=1,par(T),Y1 is 0,bin(Y1,Z,T,[],R),!.
bin(Y,Z,T,R):-impar(T),bin(Y,Z,T,[],R),!.

%quando a analise de todos os elementos da cauda(a cada vez que acaba de analisar um, decresce em um no total de elementos), a cadeia acumulada se torna a resposta
bin(Y,Z,0,R,R).

%para cabeça 0, verifica o elemento da posicao T da cauda, e insere X vezes (X é o elemento da posiçao T da cauda) o valor da cabeça original na lista a acumular. assim que acaba o processo, troca a cabeça pelo valor contrario(0->1) e descresce em 1 o T(o elemento em T ja foi totalmente aproveitado).
bin(Y,Z,T,R1,R):-
Y=:=0,
buscaelemento(T,Z,X),
insira(Y,X,R1,R2),
T1 is T-1,
Y1 is 1,
bin(Y1,Z,T1,R2,R).

%para cabeça 1, verifica o elemento da posicao T da cauda, e insere X vezes (X é o elemento da posiçao T da cauda) o valor da cabeça original na lista a acumular. assim que acaba o processo, troca a cabeça pelo valor contrario(1->0) e descresce em 1 o T(o elemento em T ja foi totalmente aproveitado).
bin(Y,Z,T,R1,R):-
Y=:=1,
buscaelemento(T,Z,X),
insira(Y,X,R1,R2),
T1 is T-1,
Y1 is 0,
bin(Y1,Z,T1,R2,R).

%"binario" -> decimal

binario(0).
binario(1).

%recebe a lista, e a separa em cauda e cabeça, a cabeça original da lista se torna a cabeça da resposta. é verificado se realmente a cabeça é binaria. se tudo der certo, é chamada uma nova funçao que tem a cauda original, a cabeça original, um contador e a area de resposta.
fila([H|T], [H|X]):-
  binario(H),
  fila(T, H, 1, X),!.

%essa é a condiçao de parada(que sempre vai ocorrer na funçao da linha 237): quando acaba os elementos da lista analisada, seja qual for a cabeça dessa lista, agora a lista resposta para [] é o valor do contador.
fila([], _, N, X):-
  X=[N],!.

%essa é uma funçao que é chamada se a cabeça de T for de um valor diferente da cabeça da lista anteriormente analisada(isso significa que a contagem para elementos iguais consecutivos acabou). enquanto a troca acontece, X(lista-resposta) recebe a quantidade de elementos contados antes da diferença entre H e H1.
fila([H|T], H1, N, [N|X]):-
  H \= H1,
  fila(T, H, 1, X).

%essa é uma funçao que é chamada se a cabeça de T for de mesmo valor que a cabeça da lista anteriormente analisada(isso significa que nao acabou a contagem de elementos iguais consecutivos). enquanto a contagem acontece, X(lista-resultado) é simplesmente carregado.
fila([H|T], H, N, X):-
  N1 is N+1,
  fila(T, H, N1, X).

%aula dia 19/12
/*
lendo info : read(X); vc recebe alguma coisa e é guardado em X
escrevendo coisa : write(X); vc escreve oq tá guardado em X
*/

%exemplo:
cubo:-
read(X),processa_cubo(X).
processa_cubo(end_of_file):-!.
processa_cubo(N):-
  Y is N*N*N,
  write(Y),
  nl,
  cubo.
%chama a funçao para pedir um novo X
%digitar no input do read no vscode: numero q ce quer + . (ex: 5.)
%digitar end of file: EOF.

/*
outros streams para entrada e saída de dados:
->see(X). : X é o novo stream de entrada
->seen. : fecha o stream de entrada
->tell(X). : X é o novo stream de saída
->told. : fecha o stream de saída
*/

%OBS: DEPOIS ESTUDAR ESSA AULA, NOS SLIDES.

%pratica dia 20/01

inicio :- 
  	repeat,
	hipotetiza(Animal),
	write('O animal eh: '),
	write(Animal),
	nl,
	removeRespostas,
  write('quer que o programa continue adivinhando?'),
  read(X),
  (X == s -> fail;!).

/* hipoteses a serem testadas*/
hipotetiza(leopardo) :- leopardo, !.
hipotetiza(tigre) :- tigre, !.
hipotetiza(girafa) :- girafa, !.
hipotetiza(zebra) :- zebra, !.
hipotetiza(avestruz) :- avestruz, !.
hipotetiza(pinguim) :- pinguim, !.
hipotetiza(albatroz) :- albatroz, !.
hipotetiza(desconhecido). /* nao diagnosticado */

/* regras de identifica��o do animal */
leopardo :- 
	mamifero,
	carnivoro,
	verifica(tem_manchas_escuras).
tigre :- 
	mamifero,
	carnivoro,
	verifica(tem_listras_pretas).
girafa :- 
	ungulado,
	verifica(tem_pescoco_grande),
	verifica(tem_pernas_grandes).
zebra :- 
	ungulado,
	verifica(tem_listras_pretas).
avestruz :- 
	passaro,
	verifica(nao_voa),
	verifica(tem_pescoco_grande).
pinguim :- 
	passaro,
  not(verifica(voa)),
  not(verifica(tem_penas)),
	verifica(nao_voa),
	verifica(nada),
	verifica(branco_e_preto).
albatroz :- 
	passaro,
	verifica(aparece_em_estoria_de_marinheiro),
	verifica(voa).

/* regras de classifica��o */

mamifero :- 
	verifica(tem_pelo), !.
mamifero :- 
	verifica(amamenta).
passaro :- 
  not(mamifero),
  not(ungulado),
	verifica(tem_penas), !.
passaro :- 
  not(mamifero),
  not(verifica(tem_penas)),
  not(ungulado),
	verifica(voa),
	verifica(poe_ovos).
carnivoro :- 
	verifica(come_carne), !.
carnivoro :- 
	verifica(tem_dentes_pontiagudos),
	verifica(tem_garras).
ungulado :- 
  not(carnivoro),
	mamifero,
	verifica(tem_cascos), !.
ungulado :- 
  not(carnivoro),
	mamifero,
	verifica(rumina).

/* formulando perguntas */
pergunta(Pergunta) :-
	write('O animal tem a seguinte caracteristica: '),
	write(Pergunta),
	write('? '),
	read(Resposta),
	nl,
	trate(Pergunta,Resposta).

trate(Pergunta,Resposta) :-
	Resposta == s,
	assert(sim(Pergunta)),!.
trate(Pergunta,_) :-
	assert(nao(Pergunta)),fail.

:- dynamic sim/1,nao/1.

/* verificando */

verifica(S) :- sim(S),!.
verifica(S) :- nao(S),!, fail.
verifica(S) :- pergunta(S).

/* remove todas as assercoes de sim e nao */

removeRespostas :- retract(sim(_)),fail.
removeRespostas :- retract(nao(_)),fail.
removeRespostas. %para o ultimo caso de retract (EOF), pra n dar o fail final.