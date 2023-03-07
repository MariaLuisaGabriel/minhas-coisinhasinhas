#Matrizes
#matrix(data = elementos da matriz, nrow = numero de linhas, ncol = numero de colunas(pode ser omitido se o numero de linhas tiver a mostra, e o oposto tb funciona), byrow = ordem de preenchimento das linhas/ colunas (TRUE = preenche pelas linhas, FALSE =  preenche pelas colunas))

#ex:
A = matrix( c(1,2,3,4,5,6),ncol = 3, byrow = FALSE) # matriz 2x3, preenchida no sentido das colunas
A

B = matrix(c(1,2,3,4,5,6,7,8),nrow = 4, byrow = TRUE) # matriz 4x2, preenchida no sentido das linhas
B

#data frames: matrizes genéricas, muito usadas em R para estudos estatísticos
#data.frame(tipo_1 = c(dados do tipo 1),tipo_2 = c(dados do tipo 2), tipo_n = c(dados do tipo n))
#nas colunas aparecem os conjuntos dos tipos.

dataframe <- data.frame(alunos= c("Amanda","Breno","Caio","Divalino","Eduardo"),idade= c(13,14,13,12,14),altura= c(1.70,1.60,1.80,1.59,1.80))
dataframe
dataframe$idade #aparece so os dados da idade (vetor lógico)

#desafio da nota de aula
install.packages('dslabs')
library(dslabs)

head(murders)
str(murders)
summary(murders)

#qual a populaçao dos EUA em 2010?
sum(murders$population)

#quantas mortes por armas de fogo tiveram em 2010?
sum(murders$total)

#qual o estado mais/menos violento?
#1º:criar uma nova coluna so com medias de mortes por habitante

murders$rate <- murders$total*100000/murders$population

#2º:ordenar a coluna de mortes por habitante com a função order, que ordena os valores numericos em ordem crescente (menor na primeira pociçao e maior na ultima), e retorna a posiçao original do valor que voce apontar na nova lista ordenada
#ex:7 8 9 4 3
#   1 2 3 4 5 : posiçao
#order(7 8 9 4 3): resulta em: 3 4 7 8 9 , logo order(7 8 9 4 3)[3] = 1 (posiçao original do elemento 7)
#                              5 4 1 2 3 : posiçao original
#                              1 2 3 4 5 : posiçao do vetor ordenado

#estado com a menor taxa de mortes:
murders$state[order(murders$rate)[1]]

#estado
murders$state[order(murders$rate)[length(murders$rate)]]