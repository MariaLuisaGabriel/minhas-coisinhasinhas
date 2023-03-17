--lista 2
--1: O operador  “ouexclusivo”  (xor,  denotado  por ⊗)  considera  dois  valores  lógicos  e devolve Truequando estesvalores são diferentes e Falsequando são iguais:
--𝑎⊗𝑏=(𝑎∨𝑏)∧¬(𝑎∧𝑏)
--a)Defina a função xorutilizando álgebra Booleana;

xor :: Bool -> Bool -> Bool
xor a b = (a||b)&&not(a&&b)

--b)Defina a função xor utilizando o operador relacional /=;

xor2 :: Bool -> Bool -> Bool
xor2 a b = a/=b

--c)Defina a função xor utilizando if then else;

xor3 :: Bool -> Bool -> Bool
xor3 a b = if a/=b then True else False

--d)Defina a função xorutilizando guardas.

xor4 :: Bool -> Bool -> Bool
xor4 a b | a/=b = True
         | otherwise = False

--2: Faça uma função parque recebe um número inteiro e devolve verdadeiro se o número for par e falso, caso contrário. Não se esqueça das definições de tipos.

par :: Int -> Bool
par a = if(mod a 2==0) then True else False

--3: Utilizando  a  função  do  item  anterior,  implemente  a  função imparque  recebe  um número inteiro e devolve verdadeiro se o número for ímpar e falso, caso contrário.

impar :: Int -> Bool
impar a = not(par a)

{-4: Crie as funções maior e menor,que se comportam da seguinte maneira:
> maior 2 4
4
> menor 2 4
2
Não se esqueça de declarar corretamente os tipos (assinatura) dessas funções.  
Em seguida, explique o funcionamento da seguinte função:
diferenca x y = l - s
where l = maior x y s = menor x y
-}

maior :: Int -> Int -> Int
maior a b = if(a>b)then a else b

menor :: Int -> Int -> Int 
menor a b = if(a<b)then a else b

--a funçao diferença funciona da seguinte forma: ela resulta na diferença absoluta entre x e y, procurando sempre subtrair o maior do menor, e o que torna isso possível é o auxilio das funcoes maior e menor.

--5: Utilizando  o  comando where, implemente  uma função  que  receba  o diâmetro de um círculo e calcule sua área.

areacirc :: Float -> Float
areacirc d = pi*r^2 where r = d/2

--6: Defina  uma  função  chamada numRaizes,  que  recebe  os  três  coeficientes  de  uma equação do segundo grau:𝑎𝑥2+𝑏𝑥+𝑐=0 e calcula a quantidade de raízes reais distintas da equação. Lembrando que, para isso, é necessário calcular o discriminante ∆da equação: ∆=𝑏2−4ac.
--Use  uma  definição  local  para  calculá-lo. Se ∆ for  positivo,a equação  tem  duas  reais reais e distintas, se for nulo, a equação tem uma raiz real, e se for negativo, a equação não tem raízes reais.

numRaizes :: Int -> Int -> Int -> Int
numRaizes a b c = if b^2 - 4*a*c > 0 
                  then 2 
                  else if b^2 - 4*a*c == 0 
                       then 1 
                       else 0

{-7: Considere o menu de opções abaixo:
1 -Soma de 2 números.
2 -Diferença entre 2 números (maior pelo menor).
3 -Produto entre 2 números.
4 -Divisão entre 2 números (maior dividido pelo menor. Se o denominador for nulo, retornar como resultado o valor -1)
Leia dois numeros inteiros, seguidos pela opção escolhida. 
Retorne como resultado o valor -1, caso o usuário digite uma operação que não pertence ao menu.
-}

menu :: Int -> Int -> Int -> Int
menu a b c = opcao a b c

diferenca :: Int -> Int -> Int
diferenca x y = l - s where l = maior x y 
                            s = menor x y

divisao :: Int -> Int -> Int
divisao a 0 = -1
divisao a b = div a b

opcao :: Int -> Int -> Int -> Int
opcao a b c | c == 1 = a + b
            | c == 2 = diferenca a b
            | c == 3 = a * b
            | c == 4 = divisao a b
            | otherwise = -1

menu2 :: IO()
menu2 = do putStr("escreva o numero 1: ")
           a<-readLn
           putStr("escreva o numero 2: ")
           b<-readLn
           putStr("escreva um comando do tipo:\n1:a+b\n2:a-b\n3:axb\n4:a/b\n->")
           c<-readLn 
           putStr("resposta: ")
           print(menu a b c)