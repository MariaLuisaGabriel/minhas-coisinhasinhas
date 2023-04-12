-- 1)
module Main (main) where

-- 2)

import Data.Char
import System.IO (BufferMode (NoBuffering), IOMode (ReadWriteMode, WriteMode), hClose, hGetContents, hPutStr, hSetBuffering, openFile, stdout)

main :: IO ()
main = do
  hSetBuffering stdout NoBuffering
  putStrLn ("escreva seu nome: ")
  nome <- getLine
  menu nome

menu :: String -> IO ()
menu nome = do
  putStrLn ("\n\n===========================\n BANCO " ++ nome ++ "\n===========================\nOpcoes:\n1. Saldo\n2. Extrato\n3. Deposito\n4. Saque\n5. Fim\n->escolha uma opcao:")
  opcao <- readLn
  opt nome opcao

opt :: String -> Int -> IO ()
opt nome a
  | a == 1 = do
      saldo <- readFile "saldo.txt"
      putStrLn ("\nSaldo atual: " ++ saldo)
      menu nome
  | a == 2 = do
      extrato <- readFile "extrato.txt"
      putStrLn ("\nExtrato:\n" ++ extrato)
      menu nome
  | a == 3 = do
      putStrLn ("Digite o valor do deposito:")
      valorDeposito <- readLn
      deposito valorDeposito
      menu nome
  | a == 4 = do
      putStrLn ("Digite o valor do saque:")
      valorSaque <- readLn
      saque valorSaque
      menu nome
  | a == 5 = putStrLn ("\nMenu fechado com sucesso")
  | otherwise = do
      putStrLn ("\nErro: comando nao identificavel")
      menu nome

imprime :: String -> IO ()
imprime a = do
  conteudo <- readFile a
  putStrLn conteudo

deposito :: Float -> IO ()
deposito valorDeposito = do
  saldo <- readFile "saldo.txt"
  putStrLn ("saldo antes do deposito: " ++ saldo)
  infile <- openFile "saldo.txt" ReadWriteMode
  hPutStr infile (show ((stringtoFloat saldo) + valorDeposito))
  hClose infile
  putStrLn ("saldo apos do deposito: " ++ show ((stringtoFloat saldo) + valorDeposito))
  appendFile "extrato.txt" ("\n+" ++ show (valorDeposito))

saque :: Float -> IO ()
saque valorSaque = do
  saldo <- readFile "saldo.txt"
  putStrLn ("saldo antes do saque: " ++ saldo)
  writeFile "saldo.txt" (show ((stringtoFloat saldo) - valorSaque))
  putStrLn ("saldo apos o saque: " ++ show ((stringtoFloat saldo) - valorSaque))
  appendFile "extrato.txt" ("\n-" ++ show (valorSaque))

stringtoFloat :: String -> Float
stringtoFloat a = read a
