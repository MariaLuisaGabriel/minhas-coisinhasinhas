olive <- read.table("olive.txt",sep = ",")

embaraia <- sample(1:nrow(olive),length(olive[,1]),replace = FALSE)
olive<-olive[embaraia,]

n<-round(nrow(olive)*0.8)
treino<-olive[1:n,]
treino2<-olive[(n+1):nrow(olive),]

treino$palmitic = as.factor(treino$palmitic)
treino$linoleic = as.factor(treino$linoleic)

sardinia<-olive[olive$region == "Sardinia",]
south<-olive[olive$region == "Southern Italy",]
north<-olive[olive$region == "Northern Italy",]

boxplot(sardinia$oleic,south$oleic,north$oleic)
#azeite > 0.1 de acido eicosenoico = South Italy

par(mfrow = c(1,2))
hist(sardinia$oleic)
hist(north$oleic)

#azeite < 74 de acido oleico = north Italy
#else dos dois  = sardinia

previsao<-c()
for(j in 1:nrow(treino2))
{
  if(treino2$eicosenoic[j]>0.1)
  {
    previsao[j] <- "Southern Italy"
  }else
  {
    if(treino2$oleic[j]<74)
    {
      previsao[j]<- "North Italy"
    }else
    {
      previsao[j]<- "Sardinia"
    }
  }
}

mean(previsao == treino2$region)
