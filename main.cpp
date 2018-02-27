#include <QCoreApplication>
#include <QList>
class Node_graph{
    //int line;
    int me;
    Node_graph *father;
    int children[14];
    double hfunc;
    double gfunc;
    double ffunc;

    Node_graph(int mee, int *son, int size){
        me = mee;
        father = fatherr;
      //  line = linee;
        ffunc = 0;
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
class graph{
    Node_graph E1;
    Node_graph E2;
    Node_graph E3;
    Node_graph E4;
    Node_graph E5;
    Node_graph E6;
    Node_graph E7;
    Node_graph E8;
    Node_graph E9;
    Node_graph E10;
    Node_graph E11;
    Node_graph E12;
    Node_graph E13;
    Node_graph E14;
    int distance[14][14];
    int azul[6];
    int amarelo[6];
    int vermelho[6];
    int verde[6];
    QList<Node_graph> list_graph;

    graph(){
          int array1[1] = {2};
          int array2[3] = {1, 3, 9, 10};
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
          list_graph.append(E1 = new Node_graph(1,array1[], 1));
          list_graph.append(E2 = new Node_graph(2,array2[], 3));
          list_graph.append(E3 = new Node_graph(3,array3[], 4));
          list_graph.append(E4 = new Node_graph(4,array4[], 4));
          list_graph.append(E5 = new Node_graph(5,array5[], 4));
          list_graph.append(E6 = new Node_graph(6,array6[], 1));
          list_graph.append(E7 = new Node_graph(7,array7[], 1));
          list_graph.append(E8 = new Node_graph(8,array8[], 4));
          list_graph.append(E9 = new Node_graph(9,array9[], 4));
          list_graph.append(E10 = new Node_graph(10,array10[], 1));
          list_graph.append(E11 = new Node_graph(11,array11[], 1));
          list_graph.append(E12 = new Node_graph(12,array12[], 1));
          list_graph.append(E13 = new Node_graph(13,array13[], 3));
          list_graph.append(E14 = new Node_graph(14,array14[], 1));
          distance = {{ 0 , 11 , 20 , 27 , 40 , 43 , 39 , 28 , 18 , 10 , 18 , 30 , 30 , 32 },
                      {11 , 0  , 9  , 16 , 29 , 32 , 28 , 19 , 11 , 4  , 17 , 23 , 21 , 24 },
                      {20 , 9  , 0  , 7  , 20 , 22 , 19 , 15 , 10 , 11 , 21 , 21 , 13 , 18 },start
                      {27 , 16 , 7  , 0  , 13 , 16 , 12 , 13 , 13 , 18 , 26 , 21 , 11 , 17 },
                      {40 , 29 , 20 , 13 , 0  , 3  , 2  , 21 , 25 , 31 , 38 , 27 , 16 , 20 },
                      {43 , 32 , 22 , 16 , 3  , 0  , 4  , 23 , 28 , 33 , 41 , 30 , 17 , 20 },
                      {39 , 28 , 19 , 12 , 2  , 4  , 0  , 22 , 25 , 29 , 38 , 28 , 13 , 17 },
                      {28 , 19 , 15 , 13 , 21 , 23 , 22 , 0  , 9  , 22 , 18 , 7  , 25 , 30 },
                      {18 , 11 , 10 , 13 , 25 , 28 , 25 , 9  , 0  , 13 , 12 , 12 , 23 , 28 },
                      {10 , 4  , 11 , 18 , 31 , 33 , 29 , 22 , 13 , 0  , 20 , 27 , 20 , 23 },
                      {18 , 17 , 21 , 26 , 38 , 41 , 38 , 18 , 12 , 20 , 0  , 15 , 35 , 39 },
                      {30 , 23 , 21 , 21 , 27 , 30 , 28 , 7  , 12 , 27 , 15 , 0  , 31 , 37 },
                      {30 , 21 , 13 , 11 , 16 , 17 , 13 , 25 , 23 , 20 , 35 , 31 , 0  , 5  },
                      {32 , 24 , 18 , 17 , 20 , 20 , 17 , 30 , 28 , 23 , 39 , 37 , 5  , 0  }
                      };
          azul     = {1, 2, 3 , 4 , 5 , 6 };
          amarelo  = {2, 5, 7 , 8 , 9 , 10};
          vermelho = {3, 9, 11, 14, 0 , 0 };
          verde    = {4, 8, 12, 13, 14, 0 };

    }

    void search(int start, int end){

      Node_graph *actual = list_graph.operator(start-1);
      while(actual->me != end){
        //gerar os filhos e setando o pai e gerando as heuristicas e colocando na fila.
          for(int i=0; actual->children[i] != 0; i++){
            Node_graph *children = list_graph.operator(actual->children[i] - 1);
            children->father = actual;        // quando eu faço isso father aponta para start?
            //gerar hn = pegar distancia na tabela e fazer regra de 3 para mudar para tempo
            children->hfunc = distance[children->me -1][end-1];
            children->hfunc = children->hfunc/30;
            //gerar gn
            Node_graph *next_children = children;
            Node_graph *next_father = children->father;
            while(next_father->me != start){
              children->ffunc =
            }

          }
        // percorrer a fila para saber qual o próximo nó a ser analisado.
      }
      if(actual == end){

      }
      else{

      }
    }

// youcomplete-me vim



};

int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);



    return a.exec();
}
