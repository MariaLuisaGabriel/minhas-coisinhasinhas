# boxplot() => grafico-caixa, mostra o valor minimo e maximo que a variavel pode alcançar (por linhas horizontais), e alem disso, a caixa em si representa 50% dos valores que a variável pode ter
# linha preta: mediana
# linha mais baixa da caixa: primeiro quartio
# linha mais alta da caixa: terceiro quartio

iris # tabela ja embutida no programa

indices <- sample(1:nrow(iris),size = (nrow(iris)),replace = FALSE)
sample(150)
iris<-iris[indices,] #embaralhar as linhas da tabela

n<-round(nrow(iris)*0.8) #pega 80% das iris
n
treinamento<-iris[1:n,] #separa 80% das iris
teste<-iris[(n+1):nrow(iris),] #deixa os 20% em outra variavel

a<-boxplot(treinamento$Petal.Length)
a$stats

order(treinamento$Petal.Length) #poderia ter usado o sort (ordena o vetor e muda a posiçao dos valores, enquanto o order so mostra as posiçoes dos elementos), mas esqueci KKKKKKKK
b<-length(treinamento$Petal.Length)

#n/2 - ésimo elemento + n/2+1 - ésimo elemento (pensando que eu não conheço o tamanho, mas sei que é par) 
mediana<-((treinamento$Petal.Length[order(treinamento$Petal.Length)[b/2]]+treinamento$Petal.Length[order(treinamento$Petal.Length)[b/2+1]]))/2

#n/4 - ésimo elemento + n/4+1 - ésimo elemento (pensando que eu não conheço o tamanho, mas sei que é par)
prim_quartio<-((treinamento$Petal.Length[order(treinamento$Petal.Length)[b/4]]+treinamento$Petal.Length[order(treinamento$Petal.Length)[b/4+1]]))/2

#3*n/4 - ésimo elemento + 3*n/4+1 - ésimo elemento (pensando que eu não conheço o tamanho, mas sei que é par)
terc_quartio<-((treinamento$Petal.Length[order(treinamento$Petal.Length)[3*b/4]]+treinamento$Petal.Length[order(treinamento$Petal.Length)[3*b/4+1]]))/2

#usando sort:
c<-sort(treinamento$Petal.Length)
mediana<-(c[b/2]+c[b/2+1])/2

prim_quartio<-(c[b/4]+c[b/4+1])/2

terc_quartio<-(c[3*b/4]+c[3*b/4+1])/2

setosa<-treinamento[treinamento$Species == "setosa",] # so as setosa
virginica<-treinamento[treinamento$Species == "virginica",] # so as virginica
versicolor<-treinamento[treinamento$Species == "versicolor",] # so as versicolor

par(mfrow = c(1,2))
boxplot(setosa$Petal.Length, versicolor$Petal.Length, virginica$Petal.Length, names = c("setosa","versicolor","virginica"))
boxplot(setosa$Sepal.Width, versicolor$Sepal.Width, virginica$Sepal.Width, names = c("setosa","versicolor","virginica"))

iris.arvore<-rpart()