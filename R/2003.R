iris # tabela ja embutida no programa

indices <- sample(1:nrow(iris),size = (nrow(iris)),replace = FALSE)
sample(150)
iris<-iris[indices,] #embaralhar as linhas da tabela
head(iris)
tail(iris)

n<-round(nrow(iris)*0.8) #pega 80% das iris
n
treinamento<-iris[1:n,] #separa 80% das iris
teste<-iris[(n+1):nrow(iris),] #deixa os 20% em outra variavel

summary(treinamento) #função ótima pra resumir todos os dados geráveis pela tabela treinamento

x<-(c(5,2,10,7,3))
sort(x)
summary(x) #demonstrando uso do summary

table(treinamento$Species) #tabela com quantidade de elementos que se encaixam em cada nivel de especie (lembrando que Species é fator)

hist(treinamento$Petal.Length,breaks = 10)

#grafico para setosa, virginica e versicolor

setosa<-treinamento[treinamento$Species == "setosa",] # so as setosa
virginica<-treinamento[treinamento$Species == "virginica",] # so as virginica
versicolor<-treinamento[treinamento$Species == "versicolor",] # so as versicolor

par(mfrow = c(1,3)) #compara 3 histograma (1 linha, 3 colunas)
hist(setosa$Petal.Length, xlab = "tamanho da petala", main = "setosa",xlim = c(0,7), col = "purple") #xlim = c(0,7) serve pra dizer o inicio (0) e o fim (7)
hist(virginica$Petal.Length, xlab = "tamanho da petala", main = "virginica",xlim = c(0,7), col = "blue")
hist(versicolor$Petal.Length, xlab = "tamanho da petala", main = "versicolor",xlim = c(0,7), col = "green")

#grafico para largura da petala

par(mfrow = c(1,3)) #compara 3 histograma (1 linha, 3 colunas)
hist(setosa$Petal.Width, xlab = "largura da petala", main = "setosa",xlim = c(0,3), ylim = c(0,15), col = "purple", border = "pink") #xlim = c(0,7) serve pra dizer o inicio (0) e o fim (7)
hist(virginica$Petal.Width, xlab = "largura da petala", main = "virginica",xlim = c(0,3), ylim = c(0,15), col = "blue", border = "white")
hist(versicolor$Petal.Width, xlab = "largura da petala", main = "versicolor",xlim = c(0,3), ylim = c(0,15), col = "green", border = "yellow")

#grafico de boia

par(mfrow = c(1,1))
plot(treinamento$Petal.Length, y = treinamento$Petal.Width, pch = 8, cex = 0.5,type = 'n') # o 'n' permite a utilização do points()
points(setosa$Petal.Length,setosa$Petal.Width,col="green",pch=16)
points(virginica$Petal.Length,virginica$Petal.Width,col="purple",pch=16)
points(versicolor$Petal.Length,versicolor$Petal.Width,col="blue",pch=16)

abline(h=1.6)

previsao <- c()
for(j in 1:30)#arvore de decisao em miniatura :)
{
  if(teste$Petal.Length[j]<2.5) #na linha j .
  {
    previsao[j] <- "setosa" # x<2.5
  }else{
    if(teste$Petal.Width[j]>1.6)
    {
      previsao[j] <- "virginica" # x>2.5 , y>1.6
    }else{
      previsao[j]<- "versicolor" # x>2.5 , y<1.6
    }
  }
}
previsao
mean(previsao == teste$Species) #usa do teste pra provar que a analise feita em treinamento é valida em outros universos de analise.
