#prova de estatística
#03 de abril de 2023
#Maria Luisa Gabriel Domingues - 12121BCC010

#questao 1)
treino <- read.table("treino_baleias.txt", header = TRUE, sep = ",")
teste <- read.table("teste_baleias.txt", header = TRUE, sep = ",")

#a)
treino$especie <- as.factor(treino$especie)
azul <- treino[treino$especie == "Baleia Azul",]
cachalote <- treino[treino$especie == "Cachalote",]
jubarte <- treino[treino$especie == "Jubarte",]
fin <- treino[treino$especie == "Baleia Fin",]

#b)

#média do peso de cada baleia:
mean(azul$peso) # = 20284.62 para baleia azul
mean(cachalote$peso) # = 5856.844 para cachalote
mean(jubarte$peso) # = 4089.64 para jubarte
mean(fin$peso) # = 10901.33 para baleia fin

#variância do peso de cada baleia:
var(azul$peso) # = 2144864 para baleia azul
var(cachalote$peso) # = 707890.4 para cachalote
var(jubarte$peso) # = 247704.4 para jubarte
var(fin$peso) # = 1023420 para baleia fin

#desvio padrão do peso de cada baleia:
sd(azul$peso) # = 1464.535 para baleia azul
sd(cachalote$peso) # = 841.3622 para cachalote
sd(jubarte$peso) # = 497.6991 para jubarte
sd(fin$peso) # = 1011.642 para baleia fin

#coeficiente de variância do peso de cada baleia:
100*sd(azul$peso)/mean(azul$peso) # = 7.219931 para baleia azul
100*sd(cachalote$peso)/mean(cachalote$peso) # = 14.36545 para cachalote
100*sd(jubarte$peso)/mean(jubarte$peso) # = 12.16975 para jubarte
100*sd(fin$peso)/mean(fin$peso) # = 9.279985 para baleia fin

#c)

#escolhi calcular a mediana do volume do crânio das baleias fin:
mediana_fin <- sort(fin$volume_cranio)[length(fin$volume_cranio)/2 + 1] # 9405 para baleia fin
#interpretação: entre as baleias fin, as que possuem 9405 de volume de crânio se encontram no meio do intervalo de variação desse volume

#d)

hist(azul$peso)
#conclusão sobre o histograma: é mais frequente achar baleias azuis com o peso entre 20.000 e 21.000 quilogramas, e menos frequente achar baleias com peso menor que 17.000 kg ou maior que 23.000 kg

#e)

boxplot(azul$peso, cachalote$peso, jubarte$peso, fin$peso, names = c("baleia azul","cachalote","jubarte","baleia fin"))
#pode-se inferir que, pelo boxplot conjunto dos pesos de cada espécie, o peso, tanto de baleias azuis quanto as baleias fin possuem valor discrepante quanto as demais (não possuem intercessão no valor do peso, nem entre si, nem com as outras duas espécies), enquanto baleias como jubarte e cachalote possuem indivíduos em suas espécies com o mesmo peso.
# a baleia com o maior peso é uma baleia azul, e com o menor peso é uma jubarte

#f)

boxplot(azul$comprimento, cachalote$comprimento, jubarte$comprimento, fin$comprimento, names = c("baleia azul","cachalote","jubarte","baleia fin"))
#pode-se inferir que existem valores de comprimento que se encontram em mais de uma espécie.
# a baleia mais comprida é baleia azul, e a mais curta é uma jubarte

boxplot(azul$profundidade_maxima, cachalote$profundidade_maxima, jubarte$profundidade_maxima, fin$profundidade_maxima, names = c("baleia azul","cachalote","jubarte","baleia fin"))
#pode-se inferir que baleias cachalote, em sua maioria, se encontram em comprimentos menos fundos do oceano, quando comparado com as outras espécies
#enquanto isso, as baleias azuis são as que tem capacidade de mergulhar mais fundo, contendo a baleia que mergulha mais fundo entre todos os indivíduos da sua e das outras espécies

boxplot(azul$volume_cranio, cachalote$volume_cranio, jubarte$volume_cranio, fin$volume_cranio, names = c("baleia azul","cachalote","jubarte","baleia fin"))
#pode-se inferir que baleias azuis possuem os individuos com os maiores cranios, enquanto as jubarte possuem individuos com os menores cranios

#g)

plot(treino$comprimento,treino$profundidade_maxima)
points(azul$comprimento,azul$profundidade_maxima,col = "blue")
points(cachalote$comprimento,cachalote$profundidade_maxima, col = "yellow")
points(jubarte$comprimento,jubarte$profundidade_maxima, col = "green")
points(fin$comprimento, fin$profundidade_maxima, col = "red")

#h)
resultado <- c()
for(j in 1:nrow(teste))
{
  if(teste$peso[j]>16000)
  {
    resultado <- c(resultado, "Baleia Azul")
  } else {
    if(teste$profundidade_maxima[j]<=170)
    {
      resultado <- c(resultado, "Cachalote")
    } else {
      if(teste$comprimento[j]>=22)
        {
          resultado <- c(resultado, "Baleia Fin")
      } else {
        resultado <- c(resultado, "Jubarte")
        }
    }
  }
}
mean(teste$especie == resultado)
#taxa de acerto: 98%

#i)

plot(treino$comprimento,treino$profundidade_maxima)
points(azul$comprimento,azul$profundidade_maxima,col = "blue")
points(cachalote$comprimento,cachalote$profundidade_maxima, col = "yellow")
points(jubarte$comprimento,jubarte$profundidade_maxima, col = "green")
points(fin$comprimento, fin$profundidade_maxima, col = "red")
abline(h = 170) #decisão para determinar se era cachalote
abline(v = 22) #decisão para determinar se era jubarte ou fin
#OBS: usei do comprimento para determinar baleias azuis, então o comprimento virou fator eliminatório das baleias azuis para a análise do gráfico de pontos

#questao 2)

res_garnit <- c()
res_steven <- c()
for(j in 1:10000){
garnit <- sample(0:1,3,replace = TRUE)
steven <- sample(0:1,3, replace = TRUE)
moeda <- sample(0:1,3, replace = TRUE)
i <- 0
deu <- 0
while(deu == 0){
    comparaS <- 0
    comparaG <- 0
    if(i>0){
      moeda <- c(moeda,sample(0:1,1))
    }
    for(k in 1:3){
      if(moeda[k+i] == garnit[k]) comparaG <- comparaG + 1
      if(moeda[k+i] == steven[k]) comparaS <- comparaS + 1
    }
    if(comparaG == 3 && comparaS == 3)
    {
      res_garnit <- c(res_garnit,1)
      res_steven <- c(res_steven,0)
      deu <- 1
    }else if(comparaG == 3){
      res_garnit <- c(res_garnit,1)
      res_steven <- c(res_steven,0)
      deu <- 1
    } else if(comparaS == 3){
      res_garnit <- c(res_garnit,0)
      res_steven <- c(res_steven,1)
      deu <- 1
    } else {
      i <- i + 1
    }
  }
}
mean(res_garnit)
# garnit ganhou 56,18% das vezes

# questao extra)

vitimas = read.table("dados.txt",header = TRUE ,sep = ";")

#a)
vitimas$sexo = as.factor(vitimas$sexo) 
barplot(table(vitimas$sexo))
#existem 231 vitimas mulheres e 29 vitimas homens

#b)
hist(vitimas$idade, breaks = 6)
#há mais vítimas com idade entre 60 e 70 anos

#c)
boxplot(vitimas$idade)
# a maioria das vitimas possui entre 50 e 70 anos

#d)
boxplot(vitimas$hora)
# a maioria das vitimas morreu entre 14h e 16h

#e)
#o padrão e o perfil das vítimas de Benjamin Hartley são, em maioria, mulheres entre 50 e 70 anos, mortas entre 14h e 16h