--1)
module Main(main) where

--2)
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering), hGetContents, hPutStr, openFile, hClose, IOMode(WriteMode), IOMode(ReadWriteMode))
import Data.Char

main :: IO()
main = do hSetBuffering stdout NoBuffering
          menu

menu :: IO()
menu = do putStrLn("escreva seu nome: ")
          a<-getLine
          putStrLn("\n\n===========================\n BANCO "++a++"\n===========================\nOpcoes:\n1. Saldo\n2. Extrato\n3. Deposito\n4. Saque\n5. Fim\n->escolha uma opcao:")
          opcao<-readLn
          opt opcao

opt :: Int -> IO()
opt a | a==1 = do putStrLn("\nOperacao ainda nao implementada") 
                  menu
      | a==2 = do putStrLn("\nOperacao ainda nao implementada") 
                  menu
      | a==3 = do putStrLn("\nOperacao ainda nao implementada") 
                  menu
      | a==4 = do putStrLn("\nAgradecemos por usar nosso Banco!") 
                  menu
      | a==5 = putStrLn("\nmenu fechado com sucesso") 
      |otherwise = do putStrLn("\nErro: comando nao identificavel")
                      menu 

imprime :: String -> IO()
imprime a = do conteudo <- readFile a
               putStrLn conteudo

deposito :: Float -> IO()
deposito valorDeposito = do infile <- openFile "saldo.txt" ReadWriteMode
                            saldo <- hGetContents infile
                            hClose infile
                            infile <- openFile "saldo.txt" ReadWriteMode
                            hPutStr infile (show((stringtoFloat saldo)+valorDeposito))
                            hClose infile
                            infile <- openFile "extrato.txt" WriteMode
                            writeFile "extrato.txt" ("+"++show(valorDeposito))

saque :: Float -> IO()
saque valorSaque = do saldo <- readFile "saldo.txt"
                      writeFile "saldo.txt" (show((stringtoFloat saldo)-valorSaque))
                      writeFile "extrato.txt" ("-"++show(valorSaque))

stringtoFloat :: String -> Float
stringtoFloat a = read a