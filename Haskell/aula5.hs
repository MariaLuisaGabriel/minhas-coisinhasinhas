--RECURSIVIDADE

--soma de todos os elementos de 1 ate n (numero inteiro)
{-recursao por casamento de padrões-} -- * OBS: SIM DA PRA USAR O _ COMO ARGUMENTO DA RECURSAO
soma :: Int -> Int
soma 1 = 1 --caso base
soma n = n + (soma (n-1)) --caso recursivo (geral)

--ou

{-recursao por guarda-}
soma2 :: Int -> Int
soma2 n | n==1 = 1 --caso base
        | n > 1 = soma2 (n-1) + n --caso recursivo (geral)

--fatorial de n

fat :: Int -> Int
fat 0 = 1 --caso base
fat n = n * fat (n-1)

--potencia n de 2

pot :: Int -> Int
pot 0 = 1
pot n = 2 * pot (n-1)

--potencia m de n

potn :: Int -> Int -> Int 
potn _ 0 = 1 -- * UM EXEMPLO DA OBSERVAÇÃO QUE TAVA LA EM CIMA
potn n m = n * potn n (m-1)