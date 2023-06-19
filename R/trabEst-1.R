#Tabela com os datos sobre a roleta
CaçaNíquel<-data.frame(Símbolos= c("BAR", "7", "Cereja", "Banana", "Limão", "Laranja", "Totais"), Roda1=c("1","3","4","5","5","5","23"), Roda2=c("1","1","3","6","6","6","23"), Roda3=c("1","1","3","6","6","6","23"))

#Vetores que representam as rodas da máquina caça níquel
roda1<-c("BAR","7","7","7", "Cereja", "Cereja", "Cereja", "Cereja","Banana","Banana","Banana","Banana","Banana","Limão","Limão","Limão","Limão","Limão","Laranja","Laranja","Laranja","Laranja","Laranja")
roda2<-c("BAR","7", "Cereja", "Cereja", "Cereja","Banana","Banana","Banana","Banana","Banana","Banana","Limão","Limão","Limão","Limão","Limão","Limão","Laranja","Laranja","Laranja","Laranja","Laranja","Laranja")
roda3<-c("BAR","7", "Cereja", "Cereja", "Cereja","Banana","Banana","Banana","Banana","Banana","Banana","Limão","Limão","Limão","Limão","Limão","Limão","Laranja","Laranja","Laranja","Laranja","Laranja","Laranja")

#O tamanho dos vetores rodai(i=1:3) é exatamente 23, 
#que é o número de símbolos de cada roda como mostra o data.frame CaçaNíquel

length(roda1)
length(roda2)
length(roda3)

#A função Apostar() mostra os resultados de uma partida na máquina caça níquel

Apostar<-function(){
  writeLines("Seus resultados foram...")
  resultados<-str_c(sample(roda1, 1),sample(roda2, 1),sample(roda3, 1), sep = " ")
  writeLines(resultados)
}

#A função ApostarDinheiro() mostra, além dos resultados obtidos durante a aposta, 
#o retorno em dinheiro que o apostador obteve 
ApostarDinheiro<-function(){
  resultados<-c(sample(roda1, 1),sample(roda2, 1),sample(roda3, 1))
  
  BARCount<-which(resultados=="BAR") 
  BARCount<-length(BARCount)
  
  SevenCount<-which(resultados=="7") 
  SevenCount<-length(SevenCount)
  
  CerejaCount<-which(resultados=="Cereja") 
  CerejaCount<-length(CerejaCount)
  
  BananaCount<-which(resultados=="Banana") 
  BananaCount<-length(BananaCount)
  
  LimaoCount<-which(resultados=="Limão") 
  LimaoCount<-length(LimaoCount)
  
  LaranjaCount<-which(resultados=="Laranja") 
  LaranjaCount<-length(LaranjaCount)
  
  if(BARCount==3){
    X<-52-2
  }else{
    if(SevenCount==3){
      X<-32-2
    }else{
      if(CerejaCount==3){
        X<-17-2
      }else{
        if(CerejaCount==2){
          X<-12-2
        }else{
          if(CerejaCount==1){
            X<-5-2
          }else{
            if((BananaCount==3)|(LimaoCount==3)|(LaranjaCount==3)){
              X<-3-2
            }else{
              X<-0-2
            }
          }
        }
      }
    }
  }
  writeLines("Seus resultados foram...")
  resultados<-str_c(resultados[1],resultados[2],resultados[3], sep = " ")
  writeLines(resultados)
  X<-str_c(toString(X),",00", sep = "")
  X<-str_c("R$",X, sep= " ")
  X<-str_c("Retorno em dinheiro:", X, sep = " ")
  writeLines(X)
}

#A função Simulacao() simula multiplas vezes o experimento feito na função ApostarDinheiro()
#guardando em um vetor todos os retornos de dinheiro
Simulacao<-function(){
  retornos<-0
  for(j in 1:100000){
    resultados<-c(sample(roda1, 1),sample(roda2, 1),sample(roda3, 1))
    
    BARCount<-which(resultados=="BAR") 
    BARCount<-length(BARCount)
    
    SevenCount<-which(resultados=="7") 
    SevenCount<-length(SevenCount)
    
    CerejaCount<-which(resultados=="Cereja") 
    CerejaCount<-length(CerejaCount)
    
    BananaCount<-which(resultados=="Banana") 
    BananaCount<-length(BananaCount)
    
    LimaoCount<-which(resultados=="Limão") 
    LimaoCount<-length(LimaoCount)
    
    LaranjaCount<-which(resultados=="Laranja") 
    LaranjaCount<-length(LaranjaCount)
    
    if(BARCount==3){
      X<-52-2
    }else{
      if(SevenCount==3){
        X<-32-2
      }else{
        if(CerejaCount==3){
          X<-17-2
        }else{
          if(CerejaCount==2){
            X<-12-2
          }else{
            if(CerejaCount==1){
              X<-5-2
            }else{
              if((BananaCount==3)|(LimaoCount==3)|(LaranjaCount==3)){
                X<-3-2
              }else{
                X<-0-2
              }
            }
          }
        }
      }
    }
    retornos[j]<-X
  }
  retornos<-mean(retornos)
  retornos<-toString(retornos)
  str_c("O valor obtido é a esperança, E(X), que é aproximadamente", retornos, sep = " ")
}

#--------------------------------------------------------------------------------------
QuantoTemNaCarteira<-function(){
  carteira<-1000
  retornos<-0
  for(i in 1:500){
    resultados<-c(sample(roda1, 1),sample(roda2, 1),sample(roda3, 1))
    
    BARCount<-which(resultados=="BAR") 
    BARCount<-length(BARCount)
    
    SevenCount<-which(resultados=="7") 
    SevenCount<-length(SevenCount)
    
    CerejaCount<-which(resultados=="Cereja") 
    CerejaCount<-length(CerejaCount)
    
    BananaCount<-which(resultados=="Banana") 
    BananaCount<-length(BananaCount)
    
    LimaoCount<-which(resultados=="Limão") 
    LimaoCount<-length(LimaoCount)
    
    LaranjaCount<-which(resultados=="Laranja") 
    LaranjaCount<-length(LaranjaCount)
    
    if(BARCount==3){
      X<-52-2
      carteira<-carteira+X
    }else{
      if(SevenCount==3){
        X<-32-2
        carteira<-carteira+X
      }else{
        if(CerejaCount==3){
          X<-17-2
          carteira<-carteira+X
        }else{
          if(CerejaCount==2){
            X<-5-2
            carteira<-carteira+X
          }else{
            if(CerejaCount==1){
              X<-3-2
              carteira<-carteira+X
            }else{
              if((BananaCount==3)|(LimaoCount==3)|(LaranjaCount==3)){
                X<-12-2
                carteira<-carteira+X
              }else{
                X<-0-2
                carteira<-carteira+X
              }
            }
          }
        }
      }
    }
    retornos[i]<-carteira
  }
  return(retornos)
}
retornos2<-QuantoTemNaCarteira()
results<-data.frame(Partidas=1:500, Retornos=retornos2)
plot(results$Partidas,results$Retornos,type="l")

#-------------------------------------------------------------------------------
flutuacoes<-c()
for(k in 1:300){
  flutuacoes[k]<-list(QuantoTemNaCarteira())
}

plot(type="n",x=1:500,y=(1:500)+700,xlab="partidas",ylab="retornos")

for (l in 1:300){
  lines(results$Partidas,flutuacoes[[l]],col=sample(colors(),1))
}
#abline
#-------------------------------------------------------------------------------
leiDosGrandesNumeros<-function(){
  carteira<-1000
  retornos<-0
  for(i in 1:500){
    resultados<-c(sample(roda1, 1),sample(roda2, 1),sample(roda3, 1))
    
    BARCount<-which(resultados=="BAR") 
    BARCount<-length(BARCount)
    
    SevenCount<-which(resultados=="7") 
    SevenCount<-length(SevenCount)
    
    CerejaCount<-which(resultados=="Cereja") 
    CerejaCount<-length(CerejaCount)
    
    BananaCount<-which(resultados=="Banana") 
    BananaCount<-length(BananaCount)
    
    LimaoCount<-which(resultados=="Limão") 
    LimaoCount<-length(LimaoCount)
    
    LaranjaCount<-which(resultados=="Laranja") 
    LaranjaCount<-length(LaranjaCount)
    
    if(BARCount==3){
      X<-52-2
      carteira<-carteira+X
    }else{
      if(SevenCount==3){
        X<-32-2
        carteira<-carteira+X
      }else{
        if(CerejaCount==3){
          X<-17-2
          carteira<-carteira+X
        }else{
          if(CerejaCount==2){
            X<-5-2
            carteira<-carteira+X
          }else{
            if(CerejaCount==1){
              X<-3-2
              carteira<-carteira+X
            }else{
              if((BananaCount==3)|(LimaoCount==3)|(LaranjaCount==3)){
                X<-12-2
                carteira<-carteira+X
              }else{
                X<-0-2
                carteira<-carteira+X
              }
            }
          }
        }
      }
    }
    retornos[i]<-carteira
  }
  return(retornos)
}

grandesNumeros<-c()
retornoGrandesNumeros<-c()
for(k in 1:300){
  grandesNumeros[k]<-list(leiDosGrandesNumeros())
  retornoGrandesNumeros<-c(retornoGrandesNumeros,grandesNumeros[[k]][300])
}

flutuacoes<-c()
retornoFlutuacoes<-c()
for(k in 1:300){
  flutuacoes[k]<-list(QuantoTemNaCarteira())
  retornoFlutuacoes<-c(retornoFlutuacoes,flutuacoes[[k]][500])
}

mean(retornoGrandesNumeros)
mean(retornoFlutuacoes)
  