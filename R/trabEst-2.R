#2A)
papagaios<-read.table(file="papagaio.txt",header = T, sep=",")

head(papagaios)
tail(papagaios)
str(papagaios)
summary(papagaios)

#2B)
hist(papagaios$tamanho)
hist(papagaios$peso)
hist(papagaios$envergadura)

#2C e 2F)
corniculata<-papagaios[papagaios$especie=="corniculata",]
cirrhata<-papagaios[papagaios$especie=="cirrhata",]
arctica<-papagaios[papagaios$especie=="arctica",]

mean(corniculata$tamanho)
mean(corniculata$peso)
mean(corniculata$envergadura)
sd(corniculata$tamanho)
sd(corniculata$peso)
sd(corniculata$envergadura)

mean(cirrhata$tamanho)
mean(cirrhata$peso)
mean(cirrhata$envergadura)
sd(cirrhata$tamanho)
sd(cirrhata$peso)
sd(cirrhata$envergadura)

mean(arctica$tamanho)
mean(arctica$peso)
mean(arctica$envergadura)
sd(arctica$tamanho)
sd(arctica$peso)
sd(arctica$envergadura)

#2D)
boxplot(corniculata$peso, cirrhata$peso, arctica$peso)
#os papagaios da especie actica sao os que possuem o menor peso, enquanto os papagaios da especie cirrhata e corniculata tem maior peso, dado destaque
#para os papagaios da epecie cirrhata.

#2E)
plot(type="n",x=papagaios$peso,y=papagaios$tamanho,xlab = "Peso",ylab="Tamanho")
points(x=corniculata$peso,y=corniculata$tamanho,col="red",pch=16)
points(x=cirrhata$peso,y=cirrhata$tamanho,col="blue",pch=16)
points(x=arctica$peso,y=arctica$tamanho, col="green",pch=16)
#podemos ver que quanto ao peso, vemos que ha grande intersecao dessa especie com com as outras duas,
#enquanto as outras duas possuem uma menor intersecao entre si, quanto ao tamanho das especies
#vemos que a especie arctica eh a menor, e ha uma grande intersecao entre as especies cirrhata e corniculata.

#2G)
correlacao<-function(x,y){
  somaxy<-sum(x*y)
  somaxq<-sum(x^2)
  somayq<-sum(y^2)
  mediax<-mean(x)
  mediay<-mean(y)
  mediaxq<-mean(x)^2
  mediayq<-mean(y)^2
  n<-length(x)
  numerador<-somaxy-n*mediax*mediay
  denominador<-sqrt(somaxq-n*mediaxq)*sqrt(somayq-n*mediayq)
  resultado<-numerador/denominador
  return(resultado)
}
correlacao(corniculata$tamanho,corniculata$peso)
correlacao(cirrhata$tamanho,cirrhata$peso)
correlacao(arctica$tamanho,arctica$peso)
#para a especie corniculata as variaveis estao mais correlacionadas linearmente.

#2H)
regressao<-function(x,y){
  n<-length(x)
  somaxy<-sum(x*y)
  somax<-sum(x)
  somay<-sum(y)
  somaxq<-sum(x^2)
  m<-(n*somaxy-somax*somay)/(n*somaxq-somax^2)
  b<-mean(y)-m*mean(x)
  return(c(m,b))
}
retaCorniculata<-regressao(corniculata$peso,corniculata$tamanho)
retaCirrhata<-regressao(cirrhata$peso,cirrhata$tamanho)
retaArctica<-regressao(arctica$peso,arctica$tamanho)
lm(tamanho~peso,data=cirrhata)

#2I):
xgraph<-min(papagaios$peso):max(papagaios$peso)
plot(x=c(min(papagaios$peso),max(papagaios$peso)),y=c(min(papagaios$tamanho),max(papagaios$tamanho)),type="n",xlab = "Peso",ylab = "Tamanho")
points(x=corniculata$peso,y=corniculata$tamanho,col="red",pch=20)
lines(x=xgraph,y=retaCorniculata[1]*xgraph+retaCorniculata[2],col="black",lwd=2)

#caso queira ver para as outras especies, so descomentar as linhas a baixo:
#para cirrhata:
#points(x=cirrhata$peso,y=cirrhata$tamanho,col="green",pch=20)
#lines(x=xgraph,y=retaCirrhata[1]*xgraph+retaCirrhata[2],col="green",lwd=2)
#para arctica:
#points(x=arctica$peso,y=arctica$tamanho,col="blue",pch=20)
#lines(x=xgraph,y=retaArctica[1]*xgraph+retaArctica[2],col="blue")

#2J)
determinaTamanho<-function(peso){
  coeficientes<-regressao(papagaios$peso,papagaios$tamanho)
  tamanho<-coeficientes[1]*peso + coeficientes[2]
  return(tamanho)
}
determinaTamanho(500)
determinaTamanho(1300)
