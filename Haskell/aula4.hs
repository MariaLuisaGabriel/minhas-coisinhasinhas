{-
fflush em Haskell : hflush stdout 
OU VC SO DESATIVA O BUFFER: hSetBuffering stdout NoBuffering

OPERAÇÕES COM ARQUIVOS
-appendFile "arquivo.txt" "texto a ser inserido no arquivo.txt" => escreve textos um do lado do outro, nao substitui o anterior (p/ pular linha, usa \n)
-writeFile "arquivo.txt" "texto a ser inserido no arquivo.txt" => escreve textos, apagando td q tinha antes no arquivo
-readFile "teste.txt" => retorna o arquivo INTEIRO como uma string só
-}

--lista pratica 3:

--1) verificar se uma palavra é palindromo

palindromo :: IO()
palindromo = do putStrLn("digite uma frase: ")
                a<-getLine
                if a==(reverse a) then putStrLn("eh palindromo") else putStrLn("nao eh palindromo")

--2) produto de float

prodfloat :: IO()
prodfloat = do putStrLn("escreva 3 numeros reais: ")
               a <- readLn
               b <- readLn
               c <- readLn
               putStrLn("resultado: "++show(mult a b c)) --usa do show pra converter pra string

mult :: Float -> Float -> Float -> Float
mult a b c = a*b*c

--3) conversao celcius pra float, com funçao main e celcius(auxiliar)

main :: IO()
main = do putStrLn("escreva um valor em Fahrenheit: ")
          a<-readLn
          putStrLn("temperatura em celcius: " ++ show(celcius a)) --show transforma oq ta dentro dele em string

celcius :: Double -> Double
celcius f = (5/9)*(f-32)

--4) media das notas

notas :: IO()
notas = do putStrLn("escreva suas tres notas para saber a media: ")
           a<-readLn
           b<-readLn
           c<-readLn
           if (a+b+c)/3>=7 then putStrLn("aprovado") else
                                                     if (a+b+c)/3>=3 then putStrLn("prova especial") else putStrLn("reprovado")

--5) Crie um programa que leia a idade de uma pessoa e informe a sua classe eleitoral:
--não eleitor  abaixo  de  16  anos;
--eleitor  obrigatório  entre  18  (inclusive)  e  65  anos;
--eleitor facultativo de 16 até 18 anos e acima de 65 anos (inclusive).

classeEleitoral :: IO()
classeEleitoral = do putStrLn("Classe Eleitoral\n----------------\nDigite a idade da pessoa: ")
                     a<-readLn
                     putStrLn(idade a)

idade :: Int -> String
idade a | a<16 = "nao eleitor"
        | a>=18 && a<65 = "eleitor obrigatorio"
        | (a>=16 && a<18) || a>=65 = "eleitor facultativo"

{-6) Faça um programa que apresente um menu, o qual permita ao usuário escolher a opção desejada, dentre:

1. Salvar uma frase em um arquivo texto
2. Imprimir o conteúdo do arquivo texto
3. Sair

A seguir, o usuário devedigitar uma opção desejada, a qual executará a ação solicitada. 
Teste a opção inválida.O menu deve ser repetido infinitamente.
-}

arquivo :: IO()
arquivo = do putStrLn("MENU\n----\n1. Salvar uma frase em um arquivo texto\n2. Imprimir o conteúdo do arquivo texto\n3. Sair\n->")
             a<-readLn
             if a==3 then putStrLn("o menu foi fechado") else opcao a

opcao :: Int -> IO()
opcao a | a==1 = do salvar
                    arquivo
        | a==2 = do imprimir
                    arquivo
        | otherwise = putStrLn("ERRO, essa opcao nao existe no menu")

salvar :: IO()
salvar = do putStrLn("escreva o nome do arquivo.txt (com o sufixo .txt)")
            a<-getLine
            putStrLn("escreva a frase a salvar no arquivo ")
            b<-getLine
            appendFile a ("\n"++b)
            putStrLn("frase salva com sucesso")

imprimir :: IO()
imprimir = do putStrLn("escreva o nome do arquivo.txt (com o sufixo .txt)")
              a<-getLine
              b<-readFile a
              putStrLn("DADOS DO ARQUIVO "++a++" :")
              putStrLn(b)