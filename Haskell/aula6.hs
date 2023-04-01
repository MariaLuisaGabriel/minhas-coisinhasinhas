--1) fatorial duplo
fd :: Int -> Int
fd 1 = 1
fd 2 = 2
fd n = n * fd (n-2)

--2) quociente e resto por subtraçao sucessiva
quo :: Int -> Int -> Int
quo a b | a<b = 0
        | otherwise = 1 + quo (a-b) b

res :: Int -> Int -> Int
res a b = a - b*(quo a b)

--3) potencia com expoente a determinar

potn :: Int -> Int -> Int 
potn _ 0 = 1 -- * UM EXEMPLO DA OBSERVAÇÃO QUE TAVA LA EM CIMA
potn n m = n * potn n (m-1)

--4) nand (retorna True se ao menos um argumento é False)

nandA :: Bool -> Bool -> Bool
nandA a b = if (not(a&&b)) then True else False

nandB :: Bool -> Bool -> Bool
nandB a b | not(a&&b) = True
          | otherwise = False

nandC :: Bool -> Bool -> Bool
nandC True True = False
nandC _ _ = True
