import Data.Char (toUpper)

--1)
type Pares = (Int, Int)
addPares :: [Pares] -> [Int]
addPares [] = []
addPares ((a,b):t) = concat[[a+b],addPares t]

--2)
--a)
upper :: [Char] -> [Char]
upper [] = []
upper (a:t) = concat[[toUpper a], upper t]

--b)
-- **lembrando que String = [Char]
type Socorro = (String, String)
k :: String -> Socorro
k a = (a, upper a)

--3)
maior :: [Int] -> Pares
maior (h:t) = maior2 (h:t) h 1

maior2 :: [Int] -> Int -> Int -> Pares
maior2 [] a b = (a,b)
maior2 (h:t) a b = if h>a then maior2 t h (b+1) else maior2 t a b

--4)
type Par = ([Int], Int)
retira :: [Int] -> Int -> Par
retira a b = (tira a 1 b, elrel a 1 b)

tira :: [Int] -> Int -> Int-> [Int]
tira [] a b = []
tira (h:t) a b = if a==b then concat[[],tira t (a+1) b] else concat[[h],tira t (a+1) b]

elrel :: [Int] -> Int -> Int -> Int
elrel (h:t) a b = if a/=b then elrel t (a+1) b else h

--5)
type NomeAluno = String
type MediaNota = Int
type Aluno = (NomeAluno, MediaNota)

--a)
type Turma = [Aluno]

--b)
aprovados :: Turma -> MediaNota -> [NomeAluno]
aprovados [] c = []
aprovados ((a,b):t) c = if b>c then concat[[a],aprovados t c] else concat[[],aprovados t c]



{--PRÁTICA 6--}
--1)
--a) válido, é uma lista
--b) válido, é uma tupla
--c) válido, é uma lista de tuplas
--d) válido, é uma tupla de listas
--e) inválido, é uma lista com elementos não determinados

--2)
--a) a funçao second :: [Int] -> Int retorna a cabeça da cauda maior, que simboliza o segundo elemento da lista
--b) a funçao pair :: Int -> Int -> (Int,Int) retorna dois inteiros unidos para formar uma tupla
--c) a funçao palindrome :: [Int] -> Bool retorna True para quando uma lista é palíndrome e false para quando nao é

--3)
ult1 :: [t] -> t
ult1 (h:t) = if igual t then h else ult1 t

igual :: [t] -> Bool
igual [] = True
igual _ = False

--4)
type Alunos = (Integer, [Char], Double) --Nro Aluno, Nome, Nota
type Curso = [Alunos]

--a) 
maiorNota :: Curso -> String
maiorNota a = alunos a 1 (maior0 1 a)

maior0 :: Int -> Curso -> Int
maior0 a ((_,_,b):t) = maior1 a b t

maior1 :: Int -> Double -> Curso -> Int
maior1 a b [] = a
maior1 a b ((_,_,c):t) = if c>b then maior1 (a+1) c t else maior1 a b t

alunos :: Curso -> Int -> Int -> String
alunos ((_,a,_):t) b c = if b==c then a else alunos t (b+1) c