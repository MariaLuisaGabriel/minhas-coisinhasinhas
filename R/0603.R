#funçoes massa que achei no THE BOOK OF R
#funçao seq: cria uma sequencia de numeros, com valor inicial a final, com especificaçao para tamanho dos intervalos numericos
#ex:
x <- seq(3,39,3)
#sequencia em x que vai de 3 a 39, de 3 em 3

#AULA:

#em media, quantas vezes deveremos lan?ar um dado de seis faces ate que o numero 5 seja obtido duas vezes?
resultados2 <- c()
vezes2 <- 0
acumulado <- c()
for(j in 1:10000){
  dado<-0
  dois<-0
  lancamentos2 <- 0
  while(dois!=2){ #loop para lan?ar tantas vezes um dado ate que saiam 5 duas vezes
    dado <- sample(1:6,1)
    lancamentos2 <- lancamentos2 + 1
    filtro <- dado == 5
    dois <- dois + sum(filtro)
  }
  resultados2 <- c(resultados2,lancamentos2)
  acumulado <- c(acumulado,mean(resultados2))
  vezes2 <- vezes2 + 1
}
mean(resultados2)
plot(x = 1:10000,y = acumulado,type='l')
abline(h = 12,col = 'yellow')

#sao necessarias 30 figurinhas para completar um album, cada pacote vem com uma figurinha e todas tem a mesma probabilidade de serem obtidas. quantos pacotes de figurinhas devemos comprar para completar o album?
grupinho <- c()
acumulado2 <-c()
for(j in 1:1000){
  album <- c()
  pacotes <- 0
  while(length(unique(album))!=30){
    figurinha <- sample(1:30,1)
    album <- c(album,figurinha)
    pacotes <- pacotes + 1
  }
  grupinho<- c(grupinho,pacotes)
  acumulado2<- c(acumulado2,mean(grupinho))
}
mean(grupinho)
plot(x = 1:1000,y = acumulado2,type='l')
abline(h = 120,col = 'pink')

#calculo para pacotes em album da copa
grupinho <- c()
a<-c()
for(j in 1:1000){
  album <- c()
  pacotes <- 0
  while(length(album)!=702){
    figurinha <- sample(1:702,5,TRUE)
    album <- unique(c(album,figurinha))
    pacotes <- pacotes + 1
  }
  grupinho<- c(grupinho,pacotes)
  a<-c(a,mean(grupinho))
}
mean(grupinho)
plot(x = 1:1000,y = a,type='l')
abline(h = 1011,col = 'green')

#calculo do album da copa com 20 figurinhas mais raras

grupinho <- c()
a<-c()
for(j in 1:300){
  album <- c()
  pacotes <- 0
  while(length(album)!=702){
    figurinha <- sample(1:702,5,TRUE,prob = c(rep(1,times = 20),rep(5,times = 682)))
    album <- unique(c(album,figurinha))
    pacotes <- pacotes + 1
  }
  grupinho<- c(grupinho,pacotes)
  a<-c(a,mean(grupinho))
}
mean(grupinho)
plot(x = 1:300,y = a,type='l')
abline(h = 2500,col = 'purple')

#calculo para albuns com 1 figurinha mais rara
grupinho <- c()
acumulado2 <-c()
for(j in 1:1000){
  album <- c()
  pacotes <- 0
  while(length(unique(album))!=30){
    figurinha <- sample(1:30,1,TRUE,prob = c(1,rep(5,times = 29)))
    album <- c(album,figurinha)
    pacotes <- pacotes + 1
  }
  grupinho<- c(grupinho,pacotes)
  acumulado2<- c(acumulado2,mean(grupinho))
}
mean(grupinho)
plot(x = 1:1000,y = acumulado2,type='l')
abline(h = 190,col = 'orange')

#vov? juju(18 reais) e jorel(7 reais) jogam um jogo com moeda, cara: vov? juju da 1 real pro jorel, coroa: joel da 1 real pra vovo juju. o jogo acaba at? que um deles nao tenha mais dinheiro. simule 1 partida, e depois 10000.
#fa?a a m?dia de vit?rias da vovo juju.
vencedor<-c()
acumulado3<-c()
for(j in 1:1000)
{
juju<-18
jorel<-7
moeda<-0
while(juju!=0 & jorel!=0)
{
  moeda<-sample(0:1,1) #ou sample(c("cara","coroa"),1)
  if(moeda==0) #cara
  {
    juju<-juju-1
    jorel<-jorel+1
  }
  if(moeda==1) #coroa
  {
    jorel<-jorel-1
    juju<-juju+1
  }
}
if(jorel==0)
{
  vencedor<-c(vencedor,1) #juju = 1
}else
{
  vencedor<-c(vencedor,0) #joel = 0
}
acumulado3<-c(acumulado3,mean(vencedor))
}
mean(vencedor)
plot(x = 1:1000,y = acumulado3,type='l')
abline(h = 0.70,col = 'brown')

#estruturas de repeti??o:
#for
#for(variable in vector) {
#	
#}
#ex

soma<-0
for(j in 1:20){
  soma<- soma+j
}
#j vai mudar na ordem que o vetor ta escrito: j=1, j=2, j-3...., j=20

#exemplo mais profundo: preencher um vetor de medias de jogos de dado

medias<-c()
for(k in 1:10000){
	dado<- sample(1:6,100,TRUE) #jogadas com o dado
	medias[k] <- mean(dado) #uma posi?ao do vetor medias ? a media do resultado de 100 jogadas de dado
}

hist(medias) #curva gaussiana de frequencia de vezes que ocorre tal media

#uso do while

resultados <- c() #lista vazia
vezes <- 0

while(vezes != 10000){
dado <- 0
lancamentos <- 0
while(dado != 5) {
	dado <- sample(1:6,1)
	lancamentos <- lancamentos + 1
}
resultados <- c(resultados,lancamentos)
vezes <- vezes + 1
}

#estruturas condicionais
#poderia ter sido usado a fun?ao unique(vetor) : ela retira repeti??es de elementos do vetor, fazendo com que um vetor com 1 elemento tenha na vdd varios elementos com mesmo valor, etc.

dado3<-sample(1:6,3,TRUE)
ingual <- c(sum(dado3[c(2,3)] == dado3[1]),sum(dado3[c(1,3)] == dado3[2]),sum(dado3[c(1,2)] == dado3[3]))
a <- sum(ingual)

if(a == 0){
  print("nao ha numeros lan?ados enguais")
}else if(a == 6){
  print("todos os numeros sao enguais")
}else print("ha dois numeros enguais")

#sorteio com parcialidade (probabilidade nao é perfeitamente igual)
#sample(1:3,20,TRUE,prob = c(1,5,5)) - numero 1 é mais dificil de conseguir que as outras
