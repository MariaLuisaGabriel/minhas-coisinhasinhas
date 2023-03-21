#keggle: site para aprendizado de ciencias de dados
#modelo de previsão de ocorrências:
#tentar criar um padrão pra prever quem morre e quem sobrevive no titanic

titanic<-read.csv("1403.csv")
str(titanic) #ver a estrutura da variável
#retirando a primeira coluna:

titanic<-titanic[,-1] #,N = N-ésima coluna. ,-N = exceto a N-ésima coluna.
#primeira coluna, agora, é "survived"

titanic$Survived<-as.factor(titanic$Survived) #fator de 2 níveis, um representa o 0 (fracasso) e outro representa o 1 (sucesso)
table(titanic$Survived) #tabela que mostra os dois niveis do fator e quantas variáveis categóricas há em cada nível
prop.table(table(titanic$Survived)) #criar tabela de proporções, fazer a porcentagem de peso de cada nível comparado com o total
round(prop.table(table(titanic$Survived)), digits = 3) #arredondar valores da tabela de proporções

barplot(table(titanic$Survived), ylim = c(0,600), names.arg = c("morreu","sobreviveu"), col = "#756bb1") #tabela de barras de quantas variáveis categóricas há em cada nivel do fator
# ylim = c(0,600) : determinar os limites de y (força o R a mostrar no gráfico até esses valores)
# names.arg = c("morreu","sobreviveu") : substituir o nome de argumentos, em ordem, para melhor entendimento. 0 = morreu e 1 = sobreviveu

#fator é uma variável capaz de guardar variáveis categóricas ou contínuas.

#fazer a mesma coisa com o sexo dos passageiros:
titanic$Sex<-as.factor(titanic$Sex)
round(prop.table(table(titanic$Sex)), digits = 3) #tabela de proporçoes arredondada da tabela de quantidade de categorias de cada nível do fator Sex
barplot(table(titanic$Sex),ylim = c(0,600),names.arg = c("muie","home"),col = c("#feb24c","#f03b20"), main = "frequencia do sexo")
# se usar o argumento: horiz = TRUE no barplot: as barrar ficam horizontais :0
# se usar o argumento: main = "nome" : cria título pro barplot


table(titanic$Survived,titanic$Sex)
#tabela que faz fatores interagirem
#precisa usar fatores para fazer a tabela, pois a tabela será dividida baseada nos niveis do fator

barplot(table(titanic$Survived,titanic$Sex),ylim = c(0,900),xlim = c(0,3),col = c("#7570b3","#8da0cb"),legend = TRUE, legend.text = c("morreu","sobreviveu"), args.legend = list(bty = "n",x = "top",cex = 1))
#barplot com barras pintadas de uma cor onde as quantidades coincidem, e de outra cor onde uma excede a outra
#se por o argumento beside = TRUE, o barplot deixa uma dimensao do ladinho da outra. já se não a mencionar, o beside é FALSE
#se colocar o argumento: legend = TRUE, ele explica oq é cada cor

barplot(table(titanic$Survived,titanic$Pclass),ylim = c(0,700),names.arg = c("alta","media","baixa"),beside = TRUE, legend = TRUE)

home <- titanic[titanic$Sex == "male",] #separa so as linhas que tem home
muie <- titanic[!titanic$Sex == "male",] #separa so as linhas que tem muie

tabela_muie <- table(muie$Survived,muie$Pclass) #tabela so c dados de muie
tabela_home <- table(home$Survived,home$Pclass) #tabela so c dados de home

barplot(tabela_muie)
barplot(tabela_home)

par(mfrow = c(1,2)) #comparar 2 graficos (exibi-los ao mesmo tempo)
