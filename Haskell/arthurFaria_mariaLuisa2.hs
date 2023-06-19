
module Main (main) where

import System.IO (BufferMode (NoBuffering), IOMode (ReadWriteMode, WriteMode), hClose, hGetContents, hPutStr, hSetBuffering, openFile, stdout)
import System.Posix.Internals (puts)
import Numeric (showFFloat)

type Codigo = Int

type Nome = String

type Preco = Double

type Produto = (Codigo, Nome, Preco)


tabelaProdutos :: [Produto]
tabelaProdutos =
  [ (001, "Chocolate", 5.25),
    (002, "Biscoito", 9.50),
    (003, "Laranja", 4.60),
    (004, "Sabonete", 9.00),
    (005, "Batata", 6.50),
    (006, "Doritasso", 8.50),
    (007, "Biscoito", 8.50),
    (008, "Laranja", 4.60),
    (009, "Sabonete", 9.00),
    (010, "Batata", 6.50),
    (011, "Doritasso", 8.50),
    (012, "Biscoito", 8.50),
    (013, "Laranja", 4.60),
    (014, "Sabonete", 9.00),
    (015, "Batata", 6.50),
    (016, "Doritasso", 8.50),
    (017, "Biscoito", 8.50),
    (018, "Laranja", 4.60),
    (019, "Sabonete", 9.00),
    (020, "Batata", 6.50),
    (021, "Doritasso", 8.50)
  ]

main :: IO ()
main = do
  hSetBuffering stdout NoBuffering
  menu tabelaProdutos

menu :: [Produto] -> IO ()
menu listaProdutos = do
  putStrLn "------- Menu -------"
  putStrLn "1 - Adicionar produto"
  putStrLn "2 - Remover produto"
  putStrLn "3 - Atualizar preço do produto"
  putStrLn "4 - Escrever a lista de compras no arquivo"
  putStr "Escolha uma opção: "
  opcao <- getLine
  case opcao of
    "1" -> do
      putStrLn "\n--- Adicionar Produto ---"
      putStr "Digite o código do produto: "
      codigoStr <- getLine
      let codigo = read codigoStr :: Codigo
      putStr "Digite o nome do produto: "
      nome <- getLine
      putStr "Digite o preço do produto: "
      precoStr <- getLine
      let preco = read precoStr :: Preco
      let novoProduto = (codigo, nome, preco)
      let novaListaProdutos = adicionarProduto novoProduto listaProdutos
      putStrLn "Produto adicionado"
      menu novaListaProdutos
    "2" -> do
      putStrLn "\n--- Remover Produto ---"
      putStr "Digite o código do produto a ser removido: "
      codigoStr <- getLine
      let codigo = read codigoStr :: Codigo
      let novaListaProdutos = removerProduto codigo listaProdutos
      putStrLn "Produto removido\n"
      menu novaListaProdutos
    "3" -> do
      putStrLn "\n--- Atualizar Preço do Produto ---"
      putStr "Digite o código do produto a ser atualizado: "
      codigoStr <- getLine
      let codigo = read codigoStr :: Codigo
      putStr "Digite o novo preço do produto: "
      novoPrecoStr <- getLine
      let novoPreco = read novoPrecoStr :: Preco
      let novaListaProdutos = atualizarPrecoProduto codigo novoPreco listaProdutos
      putStrLn "Preço do produto atualizado\n"
      menu novaListaProdutos
    "4" -> do       
      putStrLn "\n--- Lista de Produtos Atualizada ---"
      let listaCompras = geraListadeCompras 10 []
      let listaFinal = lista listaCompras listaProdutos
      adicionaTXT listaFinal 0.00
      menu listaProdutos
    _ -> do
      putStrLn "Falha"
      menu listaProdutos

-- fazer tabela de produtos só que mutavel


      
geraListadeCompras :: Int -> [Int] -> [Int]
geraListadeCompras 0 x = x
geraListadeCompras a x = geraListadeCompras (a - 1) (concat [x, [mod (a * 3 + 11) 30]])

encontraProd :: Int -> [Produto] -> Produto
encontraProd p [] = (10000, "flag", 0.0)
encontraProd p ((c, n, i) : xs) = if (c == p) then (c, n, i) else encontraProd p xs

temFlag :: [Produto] -> Int
temFlag [] = 0
temFlag ((c, _, _) : xs) = if (c == 10000) then 1 else temFlag xs

-- loop : lista de compras + lista a se inserir
loop :: [Int] -> [Produto] -> [Produto]
loop [] y = y
loop (x : xs) y = loop xs (concat [[(encontraProd x tabelaProdutos)], y])

-- lista : lista de compras + lista a se inserir
lista :: [Int] -> [Produto] -> [Produto]
lista [] [] = []
lista x z = if ((temFlag (loop x [])) == 1) then inverte (removeFlag (loop x z)) [] else loop x z

removeFlag :: [Produto] -> [Produto]
removeFlag [] = []
removeFlag ((10000, _, _) : x) = removeFlag x -- necessário para remover mais de uma flag de dentro da lista de produtos
removeFlag (a : x) = a : removeFlag x

inverte :: [Produto] -> [Produto] -> [Produto]
inverte [] [] = []
inverte [] y = y
inverte (x : xs) y = inverte xs (concat [[x], y])

adicionaTXT :: [Produto] -> Double -> IO ()
adicionaTXT [] i = do
  appendFile "produto.txt" ("\n\nTotal" ++ numeroPontos (25 - (algarismos i 4)) "" ++ (showFFloat (Just 2) i ""))
  putStr ("\n")
adicionaTXT ((c, n, p) : xs) 0.00 = do
  writeFile "produto.txt" ("**********Nota Fiscal*********\n\n" ++ formata (c, n, p))
  adicionaTXT xs p
adicionaTXT ((c, n, p) : xs) i = do
  appendFile "produto.txt" ("\n" ++ formata (c, n, p))
  adicionaTXT xs (i + p)

algarismos :: Double -> Int -> Int
algarismos a b = if a < 10 then b else algarismos (real a 10) (b + 1)

numeroPontos :: Int -> String -> String
numeroPontos a x = if a == 0 then x else numeroPontos (a - 1) (x ++ ".")

formata :: Produto -> String
formata (c, n, p) = n ++ (numeroPontos (27 - (tam n) - (algarismos (real p 10) 1)) "") ++ (showFFloat (Just 2) p "")

tam :: [a] -> Int
tam [] = 0
tam (x : xs) = 1 + tam xs

real :: Double -> Double -> Double
real a b = a / b

insereFinal a [] = [a]
insereFinal a (x : xs) = x : insereFinal a xs

adicionarProduto :: Produto -> [Produto] -> [Produto]
adicionarProduto produto lista = produto : lista

removerProduto :: Codigo -> [Produto] -> [Produto]
removerProduto codigo lista = filter (\(cod, _, _) -> cod /= codigo) lista

atualizarPrecoProduto :: Codigo -> Preco -> [Produto] -> [Produto]
atualizarPrecoProduto codigo novoPreco lista = map (\(cod, nome, preco) -> if cod == codigo then (cod, nome, novoPreco) else (cod, nome, preco)) lista