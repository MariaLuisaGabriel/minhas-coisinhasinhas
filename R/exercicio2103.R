olive <- read.table("olive.txt",sep = ",")

embaraia <- sample(1:nrow(olive),length(olive[,1]),replace = FALSE)
olive<-olive[embaraia,]

n<-round(nrow(olive)*0.8)
treino<-olive[1:n,]
treino2<-olive[(n+1):nrow(olive),]

sardinia<-olive[olive$region == "Sardinia",]
south<-olive[olive$region == "Southern Italy",]
north<-olive[olive$region == "Northern Italy",]

boxplot(sardinia$linoleic,south$linoleic,north$linoleic)$stats
boxplot(sardinia$eicosenoic,south$eicosenoic,north$eicosenoic)
#azeite > 0.1 de acido eicosenoico = South Italy

par(mfrow = c(1,2))
hist(sardinia$linoleic)
hist(north$linoleic)

#azeite > 10.5 de acido linoleico = sardinia
#else tudo = north Italy

previsao<-c()
for(j in 1:nrow(treino2))
{
  if(treino2$eicosenoic[j]>0.1)
  {
    previsao[j] <- "Southern Italy"
  }else
  {
    if(treino2$linoleic[j]>10.5)
    {
      previsao[j] <- "Sardinia"
    }else
    {
      previsao[j] <- "Northern Italy"
    }
  }
}

mean(previsao == treino2$region)
#100% de previsão certa
