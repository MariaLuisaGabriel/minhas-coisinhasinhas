--lista 1: resolução
--1: O  que  são  paradigmas  de  programação?  Cite  exemplos  de  linguagens  de  cada paradigma.
--Resposta: paradigmas de programação são métodos que se tem de programar, e interagir com a máquina.
--exemplo de programação procedural: C
--exemplo de programação funcional: haskell
--exemplo de programação orientada a objetos: java

--2: Como o seu computador sabe que “/=” significa o operador “diferente de” em Haskell? Onde isto está definido? 
--Resposta: meu computador consegue identificar o sinal de desigualdade devido a uma lista de padrões de sinais traduzíveis a linguagem de máquina, que é importada junto com a linguagem Haskell, quando instalada no computador.

--3: Qual a diferença entre compilador e interpretador?
--Resposta: o compilador traduz um arquivo completo para a linguagem da máquina uma única vez por comando, enquanto o interpretador traduz o arquivo digitado à medida que esse é preenchido.

--4: Quando não definimos a assinatura de uma função, o que acontece com sua definição de tipos de dados? Como se chama essa característica do Haskell e qual a vantagem dela?
--Resposta: a linguagem Haskell procura deduzir qual o tipo de dado em que se trata. È uma vantagem pelo fato de que isso se torna uma medida de segurança, caso há falha por parte do programador.

--5: Qual a diferença entre os tipos Chare String? As expressões ‘a’ e “a” representam o mesmo valor? Justifique.
--Respota: variáveis Char são definidas como compartimentos de memória em que se cabe um único caractere (1 byte), facilmente convertido para Int ou Float.
--enquanto uma String se caracteriza por uma lista de caracterees do tipo Char, não passíveis de conversão.
-- 'a' e "a" possuem o mesmo valor na memória, ambos com 1 byte de espaço ocupado, mas não possuem a mesma flexibilidade de conversão para outros tipos.

--6: Quais dos seguintes nomes de funções estão corretos? Justifique.
--a) square_1,certo
--b) 1square,errado, não se pode começar nome de funçao com numero.
--c) Square,errado, nome de funções são com letra inicial minúscula.
--d) square!,certo
--e) square',errado, caracteres do tipo ' são reservados para descrição de caracteres.

--7: Faça uma função para calcular a subtração entre dois números.

subtracao:: Float->Float->Float
subtracao x y = x-y

--8: Faça uma função para determinar a área de um círculo. Use a constante pi, definida no Prelude.

circ:: Float->Float
circ r = pi * r * r

--9: Faça uma função composta, que determine a diferença entre as áreas de dois círculos, usando apenas as duas funções definidas nos itens 7 e 8 (sem usar operadores).

difcirc::Float->Float->Float
difcirc x y = subtracao (circ x) (circ y)

--10: Faça uma função que implemente a fórmulalógica: (p∨q)∧¬(p∧q)

e::Bool->Bool->Bool
e x y = x && y

ou::Bool->Bool->Bool
ou x y = x || y

nao::Bool->Bool
nao x = not(x)

formula::Bool->Bool->Bool
formula p q = e (ou p q) (nao (e p q))

--extra que eu inventei: faça uma funçao recursiva que retorne a potencia p de um numero x (x^p)

pot::Int->Int->Int
pot 1 x = x
pot p x = x*(pot (p-1) x)