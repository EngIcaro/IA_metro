#include <QCoreApplication>
#include <QList>
#include <QDebug>
class NodeGraph{
public:
    //int line;
    int me;
    NodeGraph *father;
    int children[14];
    double hfunc;
    double gfunc;
    double ffunc;
    int size;
    NodeGraph(int mee, int *son, int sizee){
        me = mee;
        size = sizee;
        father = 0;
      //line = linee;
        ffunc = 0, gfunc = 0, hfunc = 0;
        for(int i =0; i<= size; i++){
            if(i == size){
                children[i] = 0;
            }
            else{
                children[i] = son[i];
            }
        }
    }
};
// azul=1, amarelo=2, vermelho=3, verde=4
// linha, pai, filhos,
class Graph{
public:

    int distance[14][14] = {{ 0 , 11 , 20 , 27 , 40 , 43 , 39 , 28 , 18 , 10 , 18 , 30 , 30 , 32 },
                            {11 ,  0 ,  9 , 16 , 29 , 32 , 28 , 19 , 11 , 4  , 17 , 23 , 21 , 24 },
                            {20 ,  9 ,  0 , 7  , 20 , 22 , 19 , 15 , 10 , 11 , 21 , 21 , 13 , 18 },
                            {27 , 16 ,  7 , 0  , 13 , 16 , 12 , 13 , 13 , 18 , 26 , 21 , 11 , 17 },
                            {40 , 29 , 20 , 13 , 0  , 3  , 2  , 21 , 25 , 31 , 38 , 27 , 16 , 20 },
                            {43 , 32 , 22 , 16 , 3  , 0  , 4  , 23 , 28 , 33 , 41 , 30 , 17 , 20 },
                            {39 , 28 , 19 , 12 , 2  , 4  , 0  , 22 , 25 , 29 , 38 , 28 , 13 , 17 },
                            {28 , 19 , 15 , 13 , 21 , 23 , 22 , 0  , 9  , 22 , 18 , 7  , 25 , 30 },
                            {18 , 11 , 10 , 13 , 25 , 28 , 25 , 9  , 0  , 13 , 12 , 12 , 23 , 28 },
                            {10 ,  4 , 11 , 18 , 31 , 33 , 29 , 22 , 13 , 0  , 20 , 27 , 20 , 23 },
                            {18 , 17 , 21 , 26 , 38 , 41 , 38 , 18 , 12 , 20 , 0  , 15 , 35 , 39 },
                            {30 , 23 , 21 , 21 , 27 , 30 , 28 , 7  , 12 , 27 , 15 , 0  , 31 , 37 },
                            {30 , 21 , 13 , 11 , 16 , 17 , 13 , 25 , 23 , 20 , 35 , 31 , 0  , 5  },
                            {32 , 24 , 18 , 17 , 20 , 20 , 17 , 30 , 28 , 23 , 39 , 37 , 5  , 0  }
                            };
    int color[4][6]     =  {{1 , 2 ,  3 ,  4 ,  5 ,  6 },
                            {2 , 5 ,  7 ,  8 ,  9 , 10 },
                            {3 , 9 , 11 , 14 ,  0 ,  0 },
                            {4 , 8 , 12 , 13 , 14 ,  0 }
                            };
    QList<NodeGraph*> listGraph;
    QList<NodeGraph*> listNode;

    Graph(){
          //list_graph = new QList<*Node_graph>;
          int array1[1] = {2};
          int array2[4] = {1, 3, 9, 10};
          int array3[4] = {2, 4, 9, 13};
          int array4[4] = {3, 5, 8, 13};
          int array5[4] = {4, 6, 7, 8};
          int array6[1] = {5};
          int array7[1] = {5};
          int array8[4] = {4, 5, 9, 12};
          int array9[4] = {2, 3, 8, 11};
          int array10[1] = {2};
          int array11[1] = {9};
          int array12[1] = {8};
          int array13[3] = {3, 4, 14};
          int array14[1] = {13};
          listGraph.append(new NodeGraph(1,array1, 1));
          listGraph.append(new NodeGraph(2,array2, 4));
          listGraph.append(new NodeGraph(3,array3, 4));
          listGraph.append(new NodeGraph(4,array4, 4));
          listGraph.append(new NodeGraph(5,array5, 4));
          listGraph.append(new NodeGraph(6,array6, 1));
          listGraph.append(new NodeGraph(7,array7, 1));
          listGraph.append(new NodeGraph(8,array8, 4));
          listGraph.append(new NodeGraph(9,array9, 4));
          listGraph.append(new NodeGraph(10,array10, 1));
          listGraph.append(new NodeGraph(11,array11, 1));
          listGraph.append(new NodeGraph(12,array12, 1));
          listGraph.append(new NodeGraph(13,array13, 3));
          listGraph.append(new NodeGraph(14,array14, 1));

    }

    void search(int start, int end){
      int id = -1;
      NodeGraph *actual = listGraph.at(start-1);
      while(actual->me != end){
          int min = 100000;
        //gerar os filhos e setando o pai e gerando as heuristicas e colocando na fila.
          for(int i=0; actual->children[i] != 0; i++){

            NodeGraph *get = listGraph.at(actual->children[i] - 1);
            NodeGraph *children = new NodeGraph(get->me, get->children, get->size);

            children->father = actual;        // quando eu faço isso father aponta para start?
            qDebug() << "sou: "<< children->me <<"filho do: " << children->father->me; // print de teste

            //gerar hn = pegar distancia na tabela e fazer regra de 3 para mudar para tempo
            children->hfunc = distance[children->me -1][end-1];
            children->hfunc = children->hfunc/30;

           qDebug() <<'\n' << "meu h(n): " << children->hfunc;

            //gerar gn
            NodeGraph *next_children = children;
            NodeGraph *next_father = children->father;
            int actual_color = -1;
            double time = 0;
          //  qDebug() << "sou: " << next_children->me << "e entro no lopp enquanto sou diferente de:" << start;
            while(next_children->me != start){
              //  qDebug() << "loop 1";
                children->gfunc = children->gfunc + distance[next_father->me - 1][next_children->me -1];
                //time = children->gfunc/30;
                //vou saber se eles estão na mesma linha ou não
                for(int j=0; j<4; j++){
                //    qDebug() << "loop2";
;                    int flag = 0;
                    for(int k=0; k<6; k++){
                        if(color[j][k] == next_children->me || color[j][k] == next_father->me){
                            flag ++;
                        }
                     //   qDebug() << "loop3";
                    }
                    // se a flag == 2 significa que ele achou a linha que contem o pai e o filho
                    if(flag == 2){
                        // se for a primeira vez que está percorrendo a matriz ele salva actual_color como j
                        if(actual_color == -1){
                            actual_color = j;
                        }
                        // se não é preciso saber se a linha que contem o pai e o filho é a mesma linha do
                        // pai e do filho passado
                        else{
                            if(!(j == actual_color)){
                                qDebug() << "\ndo no filho: " << next_children->me << "para o no pai: " <<
                                              next_father->me << "teve mudança na rota";
                                time = time + 0.06;
                                actual_color = j;
                            }
                        }
                        break;
                    }
                }
                //qDebug() << "loop444";
                //qDebug() << "start: " << start << "atual " << next_children->me;
                // qDebug() << "antigos filho e pai: " << next_children->me << next_father->me <<
                  //            "para: " << next_father->me << next_father->father->me;
                next_children = next_father;
                next_father = next_father->father;
            }
            children->gfunc = time + (children->gfunc/30);
            children->ffunc = children->gfunc + children->hfunc;
            qDebug() << "\nmeu g(n): " << children->gfunc << " e meu f(n): " << children->ffunc;
            listNode.append(children);
            qDebug() << "minha lista tem tamanho: " << listNode.size();
            children = 0;

          }

          // percorrer a fila para saber qual o próximo nó a ser analisado.
          // se o id == -1 é pq foi o nó raiz a ser analisado, ai não precisa retirar o nó que foi analisado acima
          if(id == -1){
              qDebug() << "f(n) de todos os nós da lista: ";
              for(int j=0; j<listNode.size(); j++){
                  actual = listNode.at(j);
                  qDebug() << actual->ffunc << " ";
                  if(actual->ffunc < min){
                      min = actual->ffunc;
                      id = j;
                  }
              }
              min = 100000;
          }
          else{
              qDebug() << "f(n) de todos os nós da lista: ";
              listNode.removeAt(id);
              for(int j=0; j<listNode.size(); j++){
                  actual = listNode.at(j);
                  qDebug() <<"Nó:" <<actual->me << "tem" <<actual->ffunc << " ";
                  if(actual->ffunc < min){
                      min = actual->ffunc;
                      id = j;
                  }
              }
            min = 100000;
          }
          qDebug() << "escolhi: " << actual->me;
          actual = listNode.at(id);
      }
        while(actual != 0){
            qDebug() << actual->me<<"para";
            actual = actual->father;
        }
      // gerando o próximo nó:
    }


// youcomplete-me vim



};

int main(int argc, char *argv[])
{
    Graph *graph = new Graph();
    graph->search(10,13);
    qDebug() << "pareii";
    QCoreApplication a(argc, argv);



    return a.exec();
}
