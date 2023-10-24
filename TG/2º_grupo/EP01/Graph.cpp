#include "Graph.hpp"
#include <queue>
using namespace std;

//Construtores:
Graph::Graph() {
    this->size = 0;
}

Graph::Graph(int size) {
    this->size = size;
}

int Graph::getSize() { return size; }
void Graph::setSize(int size) { this->size = size; }

//Adiciona novo vertice na lista de vertices:
void Graph::addVertex(char valor)
{
    Vertex* v = new Vertex();
    v->setValue(valor);
    vertices.push_back(v);
}

//Dado um id retorna o vertice naquela posi��o:
Vertex* Graph::getVertex(int id)
{
    return vertices.at(id);
}

//Faz toda a leitura de entrada e cria o grafo:
Graph* Graph::readGraph()
{
    int i=0; //nro de palavras
    string aux = "a";
    Graph *g = new Graph();
    queue<string> q;

    //captura todas as palavras do input, parando no #
    while(1)
    {
        cin >> aux;
        if(aux.compare("#")==0) break;
        q.push(aux);
        i++;
    }

    //guarda todas as palavras numa matrizona, no qual se insere string por string com a fila criada
    vector <string> matriz;
    while(q.size()>0)
    {
        matriz.push_back(q.front());
        q.pop();
    }

    aux = g->captureVertices(matriz, i);
    g->setSize(aux.length());

    for(int i = 0; i<aux.length(); i++)
    {
        g->addVertex(aux[i]);
    }
    g->printVertices();

    cout << "\n\n";

    g->hierarquia(matriz);

    return g;
}

//Imprime todo o grafo:
void Graph::print()
{
    for (auto i : vertices)
    {
        i->printAdjacency();
    }
}

//Busca em profundidade, para an�lise de transfer�ncia de dinheiro
/*int Graph::dfs(Vertex* v, bool* cor)
{
    cor[v->getId()] = true;
    std::vector<Vertex*> adj = v->getAdjacency();
    for (auto i : adj)
    {
        if (!cor[i->getId()])
        {
            return (Graph::dfs(i, cor) + v->getValue());
        }
    }

    return v->getValue();
}*/

string Graph::captureVertices(vector <string> matriz, int linhas)
{
    string res = "";

    for(int i = 0; i<linhas; i++)
    {
        for(int j = 0; j<matriz.at(i).length(); j++)
        {
            //se for o primeiro loop ou não achou o caractere na string, ele insere nela
            if((i==0 && j==0) || res.find(matriz.at(i)[j])==-1)
            {
                res = res + matriz.at(i)[j];
            }
        }
    }
    return res;
}

void Graph::hierarquia(vector <string> matriz)
{
    //loop de andar nas colunas, comparando par a par os caracteres
    //andando na coluna 0
    //1º: caso o par seja de letras diferentes, bota hierarquia (primeira>segunda) e zera a coluna olhada
    //2º: caso o par seja da mesma letra, avança pra proxima coluna, e refaz as comparaçoes
    //3º: caso o par de letras esteja acessando um local que excede uma das palavras da linha, já avança para o próximo par e zera a coluna olhada
    //!!o 3º é um caso mais externo a 1º e 2º!!

    //this->printVertices();
    int coluna = 0;
    bool connected;
    for(int i = 0; i<matriz.size()-1; i++)
    {
        connected = false;
        while(not connected)
        {
            if(coluna<matriz.at(i).length() && coluna<matriz.at(i+1).length())
            {
                if(matriz.at(i)[coluna]==matriz.at(i+1)[coluna]) {coluna++;}
                else
                {
                    this->getVertex(matriz.at(i)[coluna])->addToAdjacency(matriz.at(i+1)[coluna]);
                    coluna = 0;
                    connected = true;
                }
            }
            else {coluna = 0;connected = false;}
        }
    }
    //this->print();
}


void Graph::printVertices()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << vertices.at(i)->getValue() << "; ";
    }
}