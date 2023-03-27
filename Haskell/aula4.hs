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
          putStrLn("temperatura em celcius: "++ show(celcius a))

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

--5) 