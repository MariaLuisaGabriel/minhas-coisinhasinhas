# use "#" para dar comentário
# rodar linha escrita: Ctrl+enter
# métodos de rodar: todos escritos no icone "Code" do Rstudio, na parte la de cima.

#operaçoes em R
3+3 # soma em R
sqrt(10)
exp(1) # exponencial na potencia 1
exp(4)

log(2) #logaritmo de 2 na base 10
log(b = 2,x = 3)#logaritmo de 3 na base 2 (botar b= e x= faz ele identificar a base e o operando)

#atribuindo valores a R
a.2<-3+2 #nome da variavel: "a.2"
a.2+3

3+2->A
A+4

b = 3+2

#a igualdade e o -> ou <- servem para guardar dados (os dois valem para o caso numeérico)
#numa variavel. para onde a seta aponta é que o dado vai ser guardado.

A+b

w <- "palavra"
print(w) #escreve no output o valor de w

class(w)
class(A)

#class exibe a classe (numeric ou character) de uma variavel

#criando vetores

a <- "banana" #"string"

a

a.1 <- c("a","b") #quando se concatena, nao gera uma string, mas um vetor de caracteres claramente separados

a.1

x <- c(2,3,4) #vetor numerico
print(x)
#funcao c(a,b,c) concatena a,b,c em um vetor

x #simplesmente a variavel rodada funciona como rodar o print dessa variavel

x[2] #exibe o valor na posicao 2 do vetor (numero da posicao começa no 1)

x[c(1,3)] #a funcao c concatena os valores da posicao 1 e 3 do vetor x e rodando esse formato, ele exibe so essas posicoes

#exibir posicoes que nao existem retornam NA (NULL)

x[0]

x*2 #operaçoes com vetor numerico resultam na mesma operaçao com todos os elementos dele

x*c(2,3) # ocorre do seguinte jeit: c(2,3) é um vetor numerico do tipo 2 3
#multiplicaçao: 2 3 4 (x)
#               2 3 2 3 (vetor concatenado)
#resultado:     4 9 8 warning(length)

c(x,2)/c(2,3) #funciona do mesmo jeito do de cima, mas agora x tem 4 elementos(temporariamente, ja que essa info nao foi guardada em lugar nenhum)
#entao o warning nao aparece!
#divisao:   2 3 4 2 (x concatenado com um 2)
#           2 3 2 3 (vetor concatenado)
#resultado: 1 1 2 0.7

sum(x) #soma de todos os elementos de x

mean(x) #media dos elementos de x

length(x) #tamanho de x

cumsum(x) #soma cumulativa de x
#exemplo: 2 3 4 -> cumsum = 2 5(=2+3) 9(=2+3+4)

sample(x = 1:6, size = 20, replace = TRUE)
#sorteio de 1 a 6, com 20 resultados, pode repetir

sample(1:29,8,replace = FALSE)
#sprteio de 1 a 29, com 8 resutados, nao pode repetir o resultado

x <- c(1:3) #x é um vetor numerico resultante da concatenacao de numeros de 1 a 3
x

sample(1:3,10,prob = c(5,2,1),TRUE) #sorteio do vetor 1 2 3, 10 vezes, com
#probabilidade de 5 para 1, 2 para 2 e 1 para 3, permitida repetiçao.

sample(10)#repete 10 vezes, de 1 a 10 de acordo com o seed(logo se rodar com o mesmo seed ele vai repetir o segmento aleatorio)
set.seed(1234) #código de aleatoriedade(numero qualquer dentro do seed)

#simular um dado
dado<- sample(1:6,20,replace=TRUE)

dado == 6 #verifica os elementos do vetor dado que batem com a verificação
#retornam TRUE pros casos em que a verificação bate, e FALSE pra quando não bate

saiu_6 <- dado == 6 #saiu_6 é um vetor que guarda resultados da verificação.
#guarda 0 para false e 1 para true
sum(saiu_6) #sai quantas vezes saiu 6 literalmente kkkk
mean(saiu_6) # média de vezes que saiu 6 (somatorio dos valores/tamanho do vetor)

dadoreal<- sample(1:6,20000,replace=TRUE)
saiu_6.1 <- dadoreal == 6
sum(saiu_6.1)
mean(saiu_6.1)
#dessa vez, saiu de média 0,16655, que é um valor próximo de 1/6, o que é previsto de probabilidade para cada elemento do dado

#qual a probabilidade de 2 dados serem jogados e cairem com o mesmo valor?
dado1<-sample(1:6,1000,TRUE)
dado2<-sample(1:6,1000,TRUE)
mean(dado1==dado2)#média de quantas vezes o dado1 e dado2 caem iguais
#rm(dados) remover da memória uma certa variável

#simular uma moeda

moeda<- sample(c("cara","coroa"),1000,TRUE)
saiu_cara <- moeda=="cara"
sum(saiu_cara) #quantas vezes saiu cara
cumsum(saiu_cara) #quantas vezes saiu cara até certa posição (soma 1 se saiu cara, soma 0 se saiu coroa)

cumsum(saiu_cara)/1:1000 #média parcial de cada acúmulo de jogadas

mp <- cumsum(saiu_cara)/1:1000

plot(x = 1:1000,y = mp,type = 'l') #type = 'l' é para descrever linha no grafico
abline(h = 1/2, col = 'blue') #desenha uma linha no grafico desenhado

#tabela para o caso dos dados:

mp_dado<-cumsum(saiu_6.1)/1:20000 #media parcial do acumulo de vezes que saiu 6 no dado
plot(1:20000,mp_dado,type = 'l')
abline(h=1/6,col='green')
#provando por tabela que quanto mais vezes vc joga o dado, mais visível fica a probabilidade de cair um certo numero