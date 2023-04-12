chicago <- read.csv("chicago.csv",header = TRUE)
#a)Quantas mortes provocadas por doenças cardiovasculares ocorreram no perıodo do estudo?
total_mortes_cvd<- sum(chicago$cvd)

#b)Em qual estaçao de 1997 ocorreram mais mortes provocadas por doenças cardiovasculares e em qual estação ocorreram menos mortes provocadas por doenças  cardiovasculares? refaça a questão para os outros anos.
#mortes por cvd no inverno
winter <- chicago[chicago$season == "Winter",]

winter_1997 <- winter[winter$year==1997,]
mortes_cvd_winter_1997 <- sum(winter_1997$cvd)

winter_1998 <- winter[winter$year==1998,]
mortes_cvd_winter_1998 <- sum(winter_1998$cvd)

winter_1999 <- winter[winter$year==1999,]
mortes_cvd_winter_1999 <- sum(winter_1999$cvd)

winter_2000 <- winter[winter$year==2000,]
mortes_cvd_winter_2000 <- sum(winter_2000$cvd)

#mortes por cvd no verao
summer <- chicago[chicago$season == "Summer",]

summer_1997 <- summer[summer$year==1997,]
mortes_cvd_summer_1997 <- sum(summer_1997$cvd)

summer_1998 <- summer[summer$year==1998,]
mortes_cvd_summer_1998 <- sum(summer_1998$cvd)

summer_1999 <- summer[summer$year==1999,]
mortes_cvd_summer_1999 <- sum(summer_1999$cvd)

summer_2000 <- summer[summer$year==2000,]
mortes_cvd_summer_2000 <- sum(summer_2000$cvd)

#mortes por cvd no outono
autumn <- chicago[chicago$season == "Autumn",]

autumn_1997 <- autumn[autumn$year==1997,]
mortes_cvd_autumn_1997 <- sum(autumn_1997$cvd)

autumn_1998 <- autumn[autumn$year==1998,]
mortes_cvd_autumn_1998 <- sum(autumn_1998$cvd)

autumn_1999 <- autumn[autumn$year==1999,]
mortes_cvd_autumn_1999 <- sum(autumn_1999$cvd)

autumn_2000 <- autumn[autumn$year==2000,]
mortes_cvd_autumn_2000 <- sum(autumn_2000$cvd)

#mortes por cvd na primavera
spring <- chicago[chicago$season == "Spring",]

spring_1997 <- spring[spring$year==1997,]
mortes_cvd_spring_1997 <- sum(spring_1997$cvd)

spring_1998 <- spring[spring$year==1998,]
mortes_cvd_spring_1998 <- sum(spring_1998$cvd)

spring_1999 <- spring[spring$year==1999,]
mortes_cvd_spring_1999 <- sum(spring_1999$cvd)

spring_2000 <- spring[spring$year==2000,]
mortes_cvd_spring_2000 <- sum(spring_2000$cvd)

#mais mortes em 1997: winter
#menos mortes em 1997: summer

#mais mortes em 1998: winter
#menos mortes em 1998: summer

#mais mortes em 1999: winter
#menos mortes em 1999: summer

#mais mortes em 2000: autumn
#menos mortes em 2000: summer

#c) preguiça

#d)
resp.winter <- sum(winter$resp)
resp.summer <- sum(summer$resp)
resp.spring <- sum(spring$resp)
resp.autumn <- sum(autumn$resp)
mortes.resp <- c(resp.autumn,resp.winter,resp.spring,resp.summer)
barplot(mortes.resp, ylim = c(1,4200), xlab = "estações", ylab = "mortes por doença respiratoria", names.arg = c("outono","inverno","primavera","verão"))

#e) 

y1997r <- sum(chicago[chicago$year == 1997,]$resp)
y1998r <- sum(chicago[chicago$year == 1998,]$resp)
y1999r <- sum(chicago[chicago$year == 1999,]$resp)
y2000r <- sum(chicago[chicago$year == 2000,]$resp)
#ano com mais mortes com doenças respiratorias: 1999
#ano com menos mortes com doenças respiratorias: 2000

#f)

medtempsp <- mean(spring$temp)
medtempsu <- mean(summer$temp)
medtempau <- mean(autumn$temp)
medtempwi <- mean(winter$temp)

spring <- na.omit(spring)
summer <- na.omit(summer)
autumn <- na.omit(autumn)
winter <- na.omit(winter)
medumsp <- mean(spring$rhum)
medumsu <- mean(summer$rhum)
medumau <- mean(autumn$rhum)
medumwi <- mean(winter$rhum)

boxplot(spring$temp,summer$temp,autumn$temp,winter$temp)

#g)

plot(chicago$time, chicago$temp)
points(summer$time, summer$temp, col = "green")
points(spring$time, spring$temp, col = "pink")
points(winter$time, winter$temp, col = "blue")
points(autumn$time, autumn$temp, col = "red")
#pode-se deduzir que as temperaturas mais quentes ocorrem entre primavera e verão em chicago, e que as temperaturas mais frias ocorrem entre o outono e inverno em chicago.
#além de poder-se inferir que o período de um ano , no gráfico, simboliza 365 unidades de "time", sendo time, então, a contagem de 1 dia

