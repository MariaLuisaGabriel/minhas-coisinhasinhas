import sys
import os

def msgError(msg) :
    print(msg)
    sys.exit(1)

def listData(data, path) :
    print('Dados internos a \'%s\': ' % path)
    for d in data:
        if d.is_dir() :
            print('diretorio: ',d.name)
        elif d.is_file() :
            print('arquivo: ', d.name)

#verificacao de input()
if len(sys.argv) != 2 :
    msgError('Foram fornecidos %d argumentos, sao necessarios somente 2' % (len(sys.argv) - 1))
elif not os.path.isdir(sys.argv[1]) : 
    msgError('Caminho fornecido como primeiro argumento (%s) nao identificado' % sys.argv[1])

#passado da verificacao sem problemas, vamos para a navegacao de diretorio e listagem de dados
path = sys.argv[1]

data = os.scandir(path)
listData(data,path)
data.close()