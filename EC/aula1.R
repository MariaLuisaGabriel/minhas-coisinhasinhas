attach(exemploAcademia)
names(exemploAcademia)

#-----------------REGRESSÃO LINEAR MÚLTIPLA------------------------------------------------------------
modelo = lm(G ~ Kw + H) #lm = linear multiplo; G, Kw e H são variáveis do data.frame importado
summary(modelo) #mostra a tabela coisada com o tvalor calculado -> usado para achar Fcalc na tabela

#análise de variância
anava = aov(modelo)
anava
anava[1]
summary(anava)

#valor tabelado de 5% com 2 e 12 graus de liberdade
qf(0.95,2,12) # -> nivel de significância

#valor Fcalc = 50.18, usando tvalor -> descobrir pvlor com Fcalc
1 - pf(50.18,2,12) # -> pvalor

#pvalor < nivel de significância
#rejeita-se H0 -> pelo menos uma variável seja significativa

par(mfrow=c(2,2))
plot(modelo) #tabela do modelo, para ver a distribuição dos resíduos
#OBS: quanto mais aleatório a posição dos resíduos, melhor, já que o resíduo aleatório representa erro externo ao modelo (quando é padronizado, é erro nos parâmetros)

names(modelo)

plot(Kw,modelo$residuals) # grafico do parâmetro Kw X resíduos do modelo

res_pad <- scale(modelo$residuals) # padronização dos resíduos

plot(Kw,res_pad, pch = 19)
plot(H,res_pad, pch = 19)
plot(G,res_pad, pch = 19)
plot(modelo$fitted.values,res_pad, pch = 19) #gráfico entre resíduos e x-ajustados do modelo
#deu um resultado satisfatório (não há nenhum padrão aparente entre os valores dos resíduos)

#é um teste de normalidade dos resíduos, ou seja, o quanto esses resíduos se encaixam, em conjunto, numa distribuição normal
shapiro.test(modelo$residuals)
  qqnorm(residuals(modelo), ylab = "resíduos" , xlab = "Quantis teóricos")
  qqline(residuals(modelo))
  

#------------------REGRESSAO LOGISTICA----------------------------------------------------------
attach(dadoscirurgia)
names(dadoscirurgia)

mlog <- glm(Y ~ X2 + X1, family = binomial(link = "logit"))
summary(mlog)

B1 <- 0.13891
B2 <- -2.42743
  
#Odds ratio
Or1 <- exp(B1) #variável tempo de experiência
Or2 <- exp(B2) #variável sexo

Or1
Or2

