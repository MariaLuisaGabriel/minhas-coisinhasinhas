#PRIMEIRA LISTA DE ESTATÍSTICA: FUNDAMENTOS DE R

#1
#a
a<- c(1:20)

#b
b<- c(20:1)

#c
c<- c(1:20,19:1)

#funcionamento de rep: rep(valor, times = nº de vezes), cria um vetor com um certo valor a ser repetido n vezes
#funcionamento de seq: seq(inicio,fim,saltos), cria um vetor com valor que vai do 'inicio' ao 'fim', andando de n em n valores, de acordo com 'saltos' (saltos = n)

#d
aux<- c(4,6,3)
d<- rep(aux,times = 12)

#e
e<- c(rep(aux,times = 12),4)

#f
aux1<-seq(3,6,0.1)
f<-exp(aux1)*cos(aux1)

#2
#a
a2<-c(10:100)
resposta_a<-sum((a2)^3+4*(a2)^2)

#b
b2<-c(10:25)
resposta_b<-sum(2+3/b2)

#3
xVec <- sample(x = 0:999, size = 250, replace=T)
yVec <- sample(x = 0:999, size = 250, replace=T)

#a
k<-seq(1,250,2)
imparxVec <- xVec #resposta

#b
sem_o_primeiro_yVec<-yVec[c(2:250)]
sem_o_ultimo_xVec<-xVec[c(1:249)]
result<-sem_o_primeiro_yVec - sem_o_ultimo_xVec

#c
sem_o_primeiro_xVec<-xVec[c(2:250)]
sem_o_prim_e_seg_xVec<-xVec[c(3:250)]
sem_o_primsegterc_xVec<-xVec[c(4:250)]

result_c<- sem_o_primeiro_xVec + 2*(sem_o_prim_e_seg_xVec)- sem_o_primsegterc_xVec

#4
#a
r<-which(yVec>600) #resposta
#Obs: which retorna a posição em que se encontra o elemento que satisfaz a sua análise

#b
r2<-yVec[r]

#c
socorro<-sqrt(abs(xVec - mean(xVec)))

#d
a_direita<-250 - order(yVec)[1]
if(a_direita>200) a_direita<-200
a_esquerda<-order(yVec)[1]-1
if(a_esquerda>200) a_esquerda<-200
r_d<- a_direita + a_esquerda

#e
resposta_e<-length(which(xVec%%2==0))

#f
pedaco_yVec<-yVec[seq(1,250,3)]

#5