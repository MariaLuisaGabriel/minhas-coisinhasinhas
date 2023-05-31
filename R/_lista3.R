#questão 05

medias<-c()
jogada <- c()
for(j in 1:10000)
{
  vm<-0
  a<-0
  c<-c(12,18,16)
  urna[1] <- sample(1:3, 1, prob = c(c[1]/46,c[2]/46,c[3]/46))
  c[urna[1]] <- c[urna[1]] - 1
  if(urna[1]==1) vm<- vm+1
  if(urna[1]==3) a<-a+1
  urna[2] <- sample(1:3, 1, prob = c(c[1]/45,c[2]/45,c[3]/45))
  c[urna[2]] <- c[urna[2]] - 1
  if(urna[2]==1) vm<- vm+1
  if(urna[2]==3) a<-a+1
  urna[3] <- sample(1:3, 1, prob = c(c[1]/44,c[2]/44,c[3]/44))
  c[urna[3]] <- c[urna[3]] - 1
  if(urna[3]==1) vm<- vm+1
  if(urna[3]==3) a<-a+1
  urna[4] <- sample(1:3, 1, prob = c(c[1]/43,c[2]/43,c[3]/43))
  c[urna[4]] <- c[urna[4]] - 1
  if(urna[4]==1) vm<- vm+1
  if(urna[4]==3) a<-a+1
  urna[5] <- sample(1:3, 1, prob = c(c[1]/42,c[2]/42,c[3]/42))
  c[urna[5]] <- c[urna[5]] - 1
  if(urna[5]==1) {vm<- vm+1}
  if(urna[5]==3) {a<-a+1}
  urna[6] <- sample(1:3, 1, prob = c(c[1]/41,c[2]/41,c[3]/41))
  c[urna[6]] <- c[urna[6]] - 1
  if(urna[6]==1) {vm<- vm+1}
  if(urna[6]==3) {a<-a+1}
  urna[7] <- sample(1:3, 1, prob = c(c[1]/40,c[2]/40,c[3]/40))
  c[urna[7]] <- c[urna[7]] - 1
  if(urna[7]==1) {vm<- vm+1}
  if(urna[7]==3) {a<-a+1}
  if(vm==3 | a==3 )
  {
    jogada[j] <- TRUE
  }else{
    jogada[j] <- FALSE
  }
  medias <- c(medias,mean(jogada)) 
}
plot(x = 1:10000, y = medias, type = 'l')
medias[10000]
jogada[10000]

