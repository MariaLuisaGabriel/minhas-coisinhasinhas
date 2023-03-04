%questao 1: fazer um programa que escreve a piramide de pascal num arquivo (numero de linhas escrito pelo usuario)

help(N):-consult("pedidos.pl"),append('pedidos.pl'),help(1,N,[1]),told,!.
help(N,N,L):-write(L),!.
help(N0,N,L):-
write(L),nl,
geralista(L,L2),
N1 is N0+1,
help(N1,N,L2).

geralista(P,L):-geralista(P,[],L).
geralista(P,L0,L):-
insere(1,L0,L1),
inseresoma(P,L1,L2),
insere(1,L2,L).

insere(X,[],[X]):-!.
insere(X,[Y|Z],[X|[Y|Z]]):-!.

inseresoma([],A,A):-!.
inseresoma([X|Y],A,B):-
(Y = []->inseresoma(Y,A,B)
;   tirasegundo(Y,N),
    N1 is X+N,
    insere(N1,A,C),
    inseresoma(Y,C,B)).

tirasegundo([Y|_],Y):-!.

/*
    FUNÇÕES PROLOG DE REVISÃO:
    ~~funções para arquivos~~
    write(X) => escreve algo no meio de output
    read(X) => pega algo do meio de input (necessário a presença do ponto final)
    consult("arquivo.pl"). => bota oq ta em arquivo.pl para a base de conhecimento do prolog ("stdin" do prolog)
    reconsult("arquivo.pl"). => mesma coisa que o consult, soq faz de nv kkkk
    append('arquivo.pl') + told => acessa o que tem dentro do arquivo.pl sem alterar oq ta la dentro, e da acesso ao programador poder tanto escrever quanto capturar algo de lá de dentro (arquivo.pl vira meio de output e input até chegar no told)
    tell('arquivo.pl') + told => apaga tudo do arquivo.pl e o abre para inserção de novos dados (arquivo.pl vira o meio de input até chegar no told)
    see('arquivo.pl') + seen => torna arquivo.pl um meio de input (com dados já escritos) até chegar no seen
    findall(C,relacionamento(C,_,_,_),L) => procura em arquivo.pl um ou mais relacionamentos que batem com o parâmetro C, e os inserem na lista L (se L = [], é pq nao tem nada que bate com o parametro)
    retract(relacionamento(C,A,B,N)) => apaga da base de conhecimento do prolog um certo relacionamento que bate com o do argumento do retract 
    listing(relacionamento/N) => pega tudo q ta na base de conhecimento do prolog que é do tipo relacionamento/N e insere td de uma vez no meio de input escolhido
    dynamic(relacionamento/N) => jeito de avisar ao prolog que funções que acessarão dados de relacionamento/N (tipo findall e retract) vão agir no programa
    ~~funções http~~
    :- http_handler(root(nome_site),funcao_prolog,[]) => apontar para um site específico no qual serão tirados parâmetros para variáveis prolog
    http_parameters(parametro,[variavelHTML(variavelPROLOG,[])]) => converter o que foi inserido em variavelHTML para variavelPROLOG
    list(VARIAVELPROLOG) => converte oq está em VARIAVELPROLOG para lista (bom de se usar no http parameters, dentro dos colchetes menores), caso VARIAVEL PROLOG nao tenha nada, a lista sai vazia
    http_server(http_dispach,[port(numero_da_porta)]) => gerar servidor com um certo numero_da_porta
    format('algo escrito') => escrever na pagina html através de prolog
    **muitas outras funções estão escritas nos trabalhos do professor, mas essas são as mais usadas
*/