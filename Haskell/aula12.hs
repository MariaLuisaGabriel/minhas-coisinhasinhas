{-PRATICA 8-}
import Data.Char (toUpper,isAlpha)

--1.a

type Tupla = (Int,Int)

primeiros :: [Tupla] -> [Int]
primeiros a = map fst a

--1.b

maiusculas :: String -> String
maiusculas a = map toUpper a

--1.c

dobros :: [Int] -> [Int]
dobros a = map (*2) a

--2.a

pares :: [Int] -> [Int]
pares a = filter even a

--2.b

alfa :: String -> String
alfa a = filter isAlpha a

--2.c

rmChar :: Char -> String -> String
rmChar a b = filter (/= a) b

--3.a

prod :: Num a => [a] -> a
prod a = foldr (*) 1 a 

--3.b

e :: [Bool] -> Bool
e a = foldr (&&) True a

--3.c

concatena :: [String] -> String
concatena a = foldr (++) [] a