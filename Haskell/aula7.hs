--listas e strings

--1) função compr, que retorne quantos elementos há na lista

compr :: [Int] -> Int
compr [] = 0
compr (cabeca:cauda) = 1 + compr cauda

--2) criar função pertence, pra saber se o elemento analisado está ou não no array

pertence :: [Int] ->Int -> Bool
pertence [] a = False
pertence (cabeca:cauda) a = if a /= cabeca then pertence cauda a else True