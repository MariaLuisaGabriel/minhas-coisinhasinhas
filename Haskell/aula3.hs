--LISTA 2: ELEMENTOS NAO-FUNCIONAIS
--1:Faça uma função chamada ordena2 :: Int -> Int -> (Int, Int)que aceita dois valores inteiros como argumentos  e retorna-os como um par ordenado(em ordem crescente). Por exemplo,ordena2 5 3 e igual a (3,5). Defina essa função utilizando:
--(a) if then else.
--(b) Guardas.

ordena2 :: Int -> Int -> (Int, Int)
ordena2 a b = if a>b then (b,a) else (a,b)

ordena2g :: Int -> Int -> (Int, Int)
ordena2g a b   | a>b = (b,a)
               | a<b = (a,b)

--2: Faça uma função que tenha como saída um mês,de acordo com um número de entrada, informado  pelo  usuário.  Ou  imprimaa  mensagem  “Erro!”  se  o  número  digitado não corresponder a nenhum mês. Exemplo:Entrada: 4 Saída: Abril Defina essa função utilizando:(a) Guardas.(b) Expressão case.
--Responda: é possível utilizar if then else nesse caso? É interessante fazer isso? Por quê?

mes :: Int -> String
mes a   | a==1 = "Janeiro"
        | a==2 = "Fevereiro"
        | a==3 = "Março"
        | a==4 = "Abril"
        | a==5 = "Maio"
        | a==6 = "Junho"
        | a==7 = "Julho"
        | a==8 = "Agosto"
        | a==9 = "Setembro"
        | a==10 = "Outubro"
        | a==11 = "Novembro"
        | a==12 = "Dezembro"
        | otherwise = "Erro!"

mes_sofrimento :: Int -> String
mes_sofrimento a = if a==1 then "Janeiro" else if a==2
                                               then "Fevereiro"
                                               else if a==3
                                                    then "Março"
                                                    else if a==4
                                                         then "Abril"
                                                         else if a==5
                                                              then "Maio"
                                                              else if a==6
                                                                   then "Junho"
                                                                   else if a==7
                                                                        then "Julho"
                                                                        else if a==8
                                                                             then "Agosto"
                                                                             else if a==9
                                                                                  then "Setembro"
                                                                                  else if a==10
                                                                                       then "Outubro"
                                                                                       else if a==11
                                                                                            then "Novembro"
                                                                                            else if a==12
                                                                                                 then "Dezembro"
                                                                                                 else "Erro!"

--3:Escreva uma função que, dado o comprimento de três segmentos de reta, determine seeles formam um triângulo e, caso formem, diga se o triângulo éequilátero, isósceles ouescaleno.
--Lembrando que:
-- •Condições da existência de um triângulo: todos os lados são positivos e a soma das  medidas  de quaisquer dois lados é  sempre  maior  que  a  medida  do  terceirolado.
-- •Equilátero: as medidas dos lados são todas iguais.
-- •Isósceles:pelo menos dois lados possuem a mesma medida.
-- •Escaleno: as medidas dos lados são todas diferentes.
-- •Se um triângulo não é equilátero nem escaleno, ele é isósceles.

triangulo :: Int -> Int -> Int -> IO()
triangulo a b c | a > b+c = putStrLn "Erro!"
                | b > a+c = putStrLn "Erro!"
                | c > b+c = putStrLn "Erro!"
                |otherwise = verifica a b c

verifica :: Int -> Int -> Int -> IO()
verifica a b c | a==b && b==c = putStrLn "Equilatero"
               | a/=b && b/=c && a/=c = putStrLn "Escaleno"
               | otherwise = putStrLn "Isosceles"

--4:Escreva uma função que receba dois argumentos e retorne o maior entre a soma dos quadrados dos argumentos e o quadrado da soma dos argumentos. Use a definição local let.

quad :: Int -> Int -> Int
quad a b  | (let c = a+b in c^2) > (a^2+b^2) = (let c = a+b in c^2)
          | otherwise = a^2+b^2

--5:Faça  um  menu  que  cadastre  o  nome,  número  de  matrícula  e  nota  de  um  aluno,  e imprima esses valores em uma frase de apenas uma linha.

aluno ::IO()
aluno = do putStr("escreva o nome: ")
           a<-getLine
           putStr("escreva a matricula: ")
           b<-getLine
           putStr("escreva a nota: ")
           c<-getLine
           putStrLn("nome: " ++ a ++ ", matricula: "++b++", nota: "++c)