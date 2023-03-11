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
fibs <- c(1,1)
fibonacci = function(x){
  for(j in 3:x)
  {
    fibs<-c(fibs,(fibs[j-1]+fibs[j-2]))
  }
  return(fibs)
}

#6
#coelhos gerando filhotes, com cada um gerando k pares:
#(1)par1 - filhotes
#(1)par1 - adulto
#(1 + k)[k pares de filhotes],[1 par adulto]
#(k+1 + 1*k)[k+1 pares de adultos],[k pares de filhotes]
#(2k+1 + (k+1)*k)[2k+1 pares de adultos],[(k+1)*k pares de filhotes]
#(2k+1+(k+1)*k + (2k+1)*k)[2k+1+(k+1*k) pares de adultos],[(2k+1)*k pares de filhotes]
#
#F(n) = F(n-1)+F(n-2)*k => FÓRMULA GERAL!!!!

fibs_geral<-c(1,1)
fibonacci_geral = function(n,k){
  for(j in 3:n)
  {
    fibs<-c(fibs,(fibs[j-1]+(fibs[j-2])*k))
  }
  return(fibs[n])
}

#7
pessoas<-c(1,2,3,4)
resultado<-c()
for(j in 1:100000){
  i<-1
  sorteio<-sample(1:4,4)
  while(i<4){
    if(pessoas[i]==sorteio[i]){
      resultado<-c(resultado,0)
      break
    }
    i<-i+1
  }
  if(length(resultado)<j){
    resultado<-c(resultado,1)
  }
}
mean(resultado)
#45% das vezes o jogo dá certo, e 55% das vezes dá errado;
#proporção 9:11 (de 20 vezes, 11 dão errado e 9 dão certo)

#8
v <- c()
num.impar = function(v) {
  v<-scan()
  x<-length(v)
  contador<-0
  for(j in 1:x){
    if(v[j]%%2==1){
      contador<-contador+1
    }
  }
  return(contador)
}

#9
dado1 <- 0
dado1 <- 0
s2<-0
resultados<-c()
for(j in 1:1000)
{
  dado1 <- sample(1:6,1)
  dado2 <- sample(1:6,1)
  s<-dado1+dado2
  s2<-s
  if(s==7 | s==11) 
  {
    resultados <- c(resultados,1)
  }else{
  if(s==2 | s==3 | s==12)
  {
    resultados <- c(resultados,0)
  }else
  {
    dado1 <- sample(1:6,1)
    dado2 <- sample(1:6,1)
    s<-dado1+dado2
    while(s!=7 && s!=s2)
    {
      dado1 <- sample(1:6,1)
      dado2 <- sample(1:6,1)
      s<-dado1+dado2
    }
    if(s==7) c(resultados,0)
    if(s==s2) c(resultados,1)
  }
  }
}
mean(resultados)

#10