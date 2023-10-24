import sys
import os
import glob

def msgError(msg) :
    print(msg)
    sys.exit(1)

def searchFiles(data, pattern) :
    print('Arquivos que se encaixam no padrao desejado: ')
    for d in data:
        if glob.fnmatch.fnmatch(d.name,pattern) :
            print(d.name)

#verificacao de input()
if len(sys.argv) != 3 :
    msgError('Foram fornecidos %d argumentos, sao necessarios somente 3' % len(sys.argv)-1)
elif not os.path.isdir(sys.argv[1]) : 
    msgError('Caminho fornecido como primeiro argumento (%s) nao identificado' % sys.argv[1])
elif os.path.isdir(sys.argv[2]) : 
    msgError('Caminho fornecido como segundo argumento (%s) nao identificado' % sys.argv[2])

#passado da verificacao sem problemas, vamos para a listagem dos arquvios que batem com a expressao regular,
#a partir do caminho dado em argv[1]

data = os.scandir(sys.argv[1])
searchFiles(data,sys.argv[2])
data.close()