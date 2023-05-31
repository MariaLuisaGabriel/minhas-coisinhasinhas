--tipos algébricos: não possuem um tipo dos básicos, mas elas derivam de tipos básicos, pois deve se comportar igual a algum deles
--valores para deriving tão no teams
data Sentido = Esquerda | Direita | Acima | Abaixo
               deriving(Eq)

type Pos = (Int, Int)

movimento :: Sentido -> Pos -> Pos
movimento Esquerda (x,y) = (x+1,y)
movimento Direita (x,y) = (x-1,y)
movimento Acima (x,y) = (x,y+1)
movimento Abaixo (x,y) = (x,y-1)


data Pessoa = Id Nome Sobrenome Nascimento
              deriving(Show) --quer dizer que se escrever a variavel Pessoa no ghci, ele ja imprime os dados

type Nome = String
type Sobrenome = String
type Nascimento = Int

p, p1 :: Pessoa
p = Id "Albert" "Einstein" 1800
p1 = Id "help" "me" 1234

primeiroNome :: Pessoa -> Nome
primeiroNome (Id n _ _) = n
--pode escrever primeiroNome p  no ghci, que aí ele retorna "Albert"


{- Polimorfismo -}


--algumas funcoes funcionam para mais de um tipo, então se cria uma variável de tipo indefinido
--variaveis de tipo indefinido sao escritos em letra minuscula

soma :: (Num a) => a-> a-> a -- define que a se encaixa no tipo numerico (Int, Float ou Double)
soma a b = a + b
