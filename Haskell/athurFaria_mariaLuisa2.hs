{-TRABALHO FINAL-}
import System.IO (BufferMode (NoBuffering), IOMode (ReadWriteMode, WriteMode), hClose, hGetContents, hPutStr, hSetBuffering, openFile, stdout)

type Codigo = Int
type Nome = String
type Preco = Double

type Produto = (Codigo, Nome, Preco)

tabelaProdutos :: [Produto]
tabelaProdutos = [  (001, "Chocolate", 5.25)
                  , (002, "Biscoito", 8.50)
                  , (003, "Laranja", 4.60)
                  , (004, "Sabonete", 9.00)
                  , (005, "Batata", 6.50)
                  , (006, "Doritasso", 8.50)]
{-le lista de codigos e retorna lista de produtos-}

geraListadeCompras :: Int -> [Int] -> [Int]
geraListadeCompras 0 x = x
geraListadeCompras a x = geraListadeCompras (a-1) (concat[x,[mod (a*3 + 11) 100]])

printArq :: [Produto] -> Double -> IO ()
printArq [] p = adicionaTXT (10000, "", p)
printArq (x:xs) p = do adicionaTXT x
                       printArq xs p

adicionaTXT :: Produto -> IO ()
adicionaTXT (10000, "", p) = do appendFile "produto.txt" ("\n\nTotal" ++ numeroPontos (25 - (algarismos (real p 10) 1)) "" ++ show(p))
                                putStr(".\n")
adicionaTXT (c,n,p) = do appendFile "produto.txt" ("\n" ++ formata (c,n,p))
                         putStr(".")

algarismos :: Double -> Int -> Int
algarismos a b = if a<10 then b else algarismos (real a 10) (b+1)

numeroPontos :: Int -> String -> String
numeroPontos a x = if a==0 then x else numeroPontos (a-1) (x++".")

formata :: Produto -> String
formata (c,n,p) = n++(numeroPontos (27 - (tam n) - (algarismos (real p 10) 1)) "")++show(p)

tam :: [a] -> Int
tam [] = 0
tam ( x:xs ) = 1 + tam xs

real :: Double -> Double -> Double
real a b = a/b