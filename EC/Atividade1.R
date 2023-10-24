#QUESTÃO DA TAREFA
attach(dadosvendas)

X <- matrix(data = c(seq(1,1,length.out = 10),dadosvendas$X,dadosvendas$Z), ncol = 3)
Y <- matrix(data = dadosvendas$Y, ncol = 1)


#a)-------------------------------------------------------------------------------------
#transposta de X e Y...
Xt <- t(X)
Yt <- t(Y)

#calculozinhos rápidos para determinar as matrizes-objetivo...
XtX <- Xt%*%X
XtXi <- solve(XtX)
XtY <- Xt%*%Y

#X = 
X

#X'X = 
XtX

#(X'X)^-1 = 
XtXi

#X'Y = 
XtY

#b)-------------------------------------------------------------------------------------
#matriz beta com os parâmetros...
B <- XtXi%*%XtY

#equação do modelo: y^ = 1.68 + 7.66x1 + 1.51x2

#c)--------------------------------------------------------------------------------------

BtXtY <- t(B)%*%XtY

#soma de quadrados da regressão: B'X'Y - (sum(yi))².1/n

SQR <- BtXtY - (XtY[1]*XtY[1])/10

#soma de quadrados total: sum(yi²).1/n - (sum(yi))².1/n, onde sum(yi²).1/n equivale a Y'Y

SQT <-  t(Y)%*%Y - (XtY[1]*XtY[1])/10

#soma de quadrados do erro: total - regressão

SQE <- SQT - SQR

#quadrado medio da regressão: SQReg/(p-1), onde p é o número de parâmetros

QMR <- SQR/(3-1)

#quadrado medio do erro: SQErr/(n-p), onde n é o número de elementos da amostra

QME <- SQE/(10-3)

#Fcalculado: QMReg/QMErr

Fcalc <- QMR/QME

#tabela completa:
cat(" fatores    GL    SQ    QM    Fcalc","\n","regressão   2   1237  618   20.3","\n","Erro        7   213   30.5","\n","Total       9   1450","\n")

#Hipóteses do teste F:
#H0: nenhum parâmetro é significativo na determinação das vendas (modelo não significativo)
#H1: pelo menos um parâmetro é significativo na determinação das vendas (modelo significativo)

#d)--------------------------------------------------------------------------------------
#F tabelado do teste F:
qf(c(1-0.05),2,7)

#Ftabelado < Fcalc (4.74 < 20.3), logo o Fcalc está na região crítica, concluindo que se deve rejeitar a hipótese H0.

#pValor de Fcalc:

1-pf(Fcalc,2,7)

#alfa > P-valor de Fcalc, logo o Fcalc está na região crítica, concluindo que se deve rejeitar a hipótese H0.
#por fim, pode-se concluir que o modelo é significativo, com pelo menos um dos 3 parâmetros com relevância na determinação das vendas.

#e)-------------------------------------------------------------------------------------
#T tabelado do teste T:

qt(c(1-0.025),7)

#lembrando que Tcalc = ^Bi/sqrt(QMErr.Cii), tal que C é um elemento de (X'X)^-1

Tco <- (B[1]/sqrt(QME*XtXi[1,1]))[1]

#Tc0<Tcalc, logo B0 não é um parâmetro significativo

Tc1 <- (B[2]/sqrt(QME*XtXi[2,2]))[1]

#Tc1>Tcalc, logo B1 é um parâmetro significativo

Tc2 <- (B[3]/sqrt(QME*XtXi[3,3]))[1]

#Tc2<Tcalc, logo B0 não é um parâmetro significativo

#f)-------------------------------------------------------------------------------------
modelo = lm(Y ~ X + Z)
summary(modelo)

anava <- aov(modelo)
summary(anava)

#QUESTÃO DA LISTA DE REGRESSÃO LOGÍSTICA

attach(dadosSinistro)

modelo_log <- glm(Sinistro ~ Idade + ECivil + Sexo, family = binomial(link = 'logit'))
summary(modelo_log)

#com os estimadores para cada variável independente foi calculada pelo R via função de modelo linear generalizado, onde:
#estimador B1 de Idade =  -0.18957
B1<- -0.18957
#estimador B2 de Estado Civil = -3.62511
B2<- -3.62511
#estimador B3 de Sexo = 3.70268
B3<- 3.70268
#podemos calcular as odds ratio de cada variável

Odd1 <- exp(40*B1)
Odd2 <- exp(B2)
Odd3 <- exp(B3)
Odd1 # = 0.0005091337, concluindo que a chance de ocorrer sinistro com pessoas mais velhas (pensando em como os dados da idade se comportam na regressão com seu coeficiente negativo (B1 = -0.18)) é 0.026 vezes menor que com mais novos (99,94% menos) (comparando pessoas com 40 anos de diferença entre si (18 e 58 anos))
Odd2 # = 0.02664617, concluindo que a chance de ocorrer sinistro com pessoas solteiras é 0.02 vezes menor que de ocorrer com casados (98% menos)
Odd3 # = 40.55585, concluindo que a chance de ocorrer sinistro com mulheres é 40.5 vezes maor que com homens

#teste:

Ey <- 1/(1+exp(-3.78103+B2+B1*(-25)))
Ey
