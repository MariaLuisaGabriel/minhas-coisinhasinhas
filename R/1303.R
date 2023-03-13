#!! leitura de arquivos (transforma os dados de um arquivo em um vetor)
#uso de read.sufixodoarq(file)

dado<-read.csv("1303.csv",header=TRUE)

#funçoes read.table e write.table

#dado2<-read.table(file,header=FALSE,sep=",") -> sep é pra identificar a separação entre as variáveis(pode ser um espaço, )
#arquivo .table é do tipo .txt!

#write.table(variavel,file="nome.txt", sep = "espaço ou virgula")
#cria um arquivo novo, se tiver um c mesmo nome, ele sobrescreve o antigo

#funçao round() arredonda numeros
#arredondar casas decimais: round(x,digits = 8)
#arredondar pra cima: ceiling(x)
#arredondar pra baixo: floor(x)
#truncar o numero: trunc(x, ...)