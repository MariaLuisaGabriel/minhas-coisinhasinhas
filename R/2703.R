pinguim <- read.table("pinguim.txt", header=TRUE, sep = ",")
head(pinguim)
str(pinguim)
pinguim<- na.omit(pinguim) #tira os NULL
str(pinguim)
pinguim <- pinguim[-which(pinguim$sex == "."),] #tira o .
pinguim$sex<-as.factor(pinguim$sex)
levels(pinguim$sex)

pinguim <- pinguim[sample(1:nrow(pinguim)),]
n <- round(nrow(pinguim)*0.8)
teste <- pinguim[(n+1):nrow(pinguim),]
pinguim <- pinguim[1:n,]

pinguim$species <- as.factor(pinguim$species)
levels(pinguim$species)
pinguim$island <- as.factor(pinguim$island)
levels(pinguim$island)

adelie <- pinguim[pinguim$species == "Adelie",]
chinstrap <- pinguim[pinguim$species == "Chinstrap",]
gentoo <- pinguim[pinguim$species == "Gentoo",]

boxplot(adelie$culmen_depth_mm,chinstrap$culmen_depth_mm,gentoo$culmen_depth_mm)
boxplot(adelie$flipper_length_mm,chinstrap$flipper_length_mm,gentoo$flipper_length_mm)
boxplot(adelie$body_mass_g,chinstrap$body_mass_g,gentoo$body_mass_g)

plot(pinguim$species,pinguim$island)

#gentoo = todos na ilha Biscoe
#chinstrap = todos na ilha Dream
#adelie ta em tds as ilhas

plot(pinguim$flipper_length_mm , y = pinguim$culmen_length_mm)
points(adelie$flipper_length_mm, adelie$culmen_length_mm,pch = 9, col = "blue")
points(chinstrap$flipper_length_mm, chinstrap$culmen_length_mm,pch = 9, col = "green")
points(gentoo$flipper_length_mm, gentoo$culmen_length_mm,pch = 9, col = "red")
abline(h = 44, col = "black")

#comprimento do culmen < 44 e comprimento da asa < 206 => mt provavel q seja adelie

resultado <- c()
for(j in 1:nrow(teste))
{
  if(teste$island[j] == "Biscoe")
  {
    if(teste$culmen_length_mm[j]<=44)
    {
      if(teste$flipper_length_mm[j]<=206)
      {
        resultado[j]<- "Adelie"
      } else{
        resultado[j]<- "Gentoo"
      }
    }else
    {
      resultado[j]<- "Gentoo"
    }
  }else if(teste$island[j] == "Dream")
  {
    if(teste$culmen_length_mm[j]<=44)
    {
      if(teste$flipper_length_mm[j]<=206)
      {
        resultado[j]<- "Adelie"
      } else
      {
        resultado[j]<- "Chinstrap"
      }
    }else
    {
      resultado[j]<- "Chinstrap"
    }
  } else
  {
    resultado[j]<- "Adelie"
  }
}
mean(resultado == teste$species)

#calcular a variancia do peso dos pinguins, e calcular o desvio padrao

#variancia = somatorio(elemento n - media)^2/nº de elementos  (n = 1:nº de elementos)

var(adelie$body_mass_g) #variancia do peso dos adelie
sd(adelie$body_mass_g) #desvio padrao do peso dos adelie

var(chinstrap$body_mass_g)
sd(chinstrap$body_mass_g)

var(gentoo$body_mass_g)
sd(gentoo$body_mass_g)

#calcular coeficiente de variaçao (em %):
#100*sd/mean

cvar1 <- 100*sd(adelie$body_mass_g)/mean(adelie$body_mass_g)
#adelie tem uma variabilidade de 12% em relaçao a media (+- 12% de variação maxima e minima)
cvar2<- 100*sd(gentoo$body_mass_g)/mean(gentoo$body_mass_g)
cvar3<- 100*sd(chinstrap$body_mass_g)/mean(chinstrap$body_mass_g)

# outro metodo de deduzir as especies: põe um ponto num certo espaço, e deduz que, atraves do ponto mais proximo, pontos com uma certa distancia sao do mesmo tipo (pertencem da mesma cor)
# gerar funçao das distancias de um ponto a outro (vetor)

distancia <- function(x,y){
  return(sqrt(sum(x-y)**2))
}

x <- c(1,2)
y <- c(3,4)
sum((x-y)**2)

plot(pinguim$flipper_length_mm , y = pinguim$culmen_length_mm)
points(adelie$flipper_length_mm, adelie$culmen_length_mm,pch = 9, col = "blue")
points(chinstrap$flipper_length_mm, chinstrap$culmen_length_mm,pch = 9, col = "green")
points(gentoo$flipper_length_mm, gentoo$culmen_length_mm,pch = 9, col = "red")
points(y = 46, x = 212,pch = 1,col = "black")

previsao <- c()
for(k in 1:nrow(teste))
{
  distancias <- c()
  for(j in 1:nrow(pinguim))
  {
    distancias[j] <- distancia(teste[k,3:5],pinguim[j,3:5])
  }
  previsao[k]<-as.character(pinguim$species[order(distancias)[1:5]]) # comparaçao com 5 elementos seguidos (1:5 -> 5 elementos)
}
previsao
# previsao ta em numeros pq as especies sao fatores de 3 niveis (nivel 1, 2 e 3)
mean(previsao == teste$species)

cor(pinguim[,3:6]) #correlaçao entre elementos

