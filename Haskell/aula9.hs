----LISTA5PF--------------------------------------------------------------------------------------

--3)
--a) tipo pessoa, com nome, idade e sexo
type Pessoa = (String, Int, Char)

--b) cadastro de pessoas (banquinho de dados) com casamento de padroes
{--
pessoa :: Int -> Pessoa
pessoa 1 = ("Joao", 20, 'M')
pessoa 2 = ("Maria", 18, 'F')
pessoa 3 = ("Jose", 19, 'M')
pessoa _ = error("n tem")
--}

--c) cadastro de pessoas (banquinho de dados) com guardas
pessoa :: Int -> Pessoa
pessoa x | x==1 = ("Joao", 20, 'M')
         | x==2 = ("Maria", 18, 'F')
         | x==3 = ("Jose", 19, 'M')
         |otherwise = error("n tem")

--d) recebe pessoa e retorna idade
idade :: Pessoa -> Int
idade (_,i,_) = i

--e) soma das idades, de acordo com o indice
sumidade :: Int -> Int
sumidade 0 = 0
sumidade n = sumidade (n-1) + idade (pessoa n)

--f)
mediaidades :: Int -> Float
mediaidades 0 = error("nao ha media")
mediaidades n = fromIntegral(sumidade n)/(fromIntegral n) --fromIntegral converte int pra float

-----LISTA3PF---aula 4-----------------------------------------------------------------------------

--1.
imprimeNvezes :: Int -> IO()
imprimeNvezes 1 = do putStrLn("Frase")
imprimeNvezes n = do putStrLn("Frase")
                     imprimeNvezes (n-1)

--2.eLogico de guardas
eLogico :: Bool -> Bool -> Bool
eLogico x y | x==True && y==True = True
            | otherwise = False

--3.
eLogico2 :: Bool -> Bool -> Bool
eLogico2 x y | x==True = y
             | otherwise = False

--4.
comb :: Int -> Int -> Int
comb n 1 = n
comb n k | n<k = error("nao pode")
         | n==k = 1
         | otherwise = comb (n-1) (k-1) + comb (n-1) k