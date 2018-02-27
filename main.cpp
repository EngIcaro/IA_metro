#include <QCoreApplication>

class Node_graph{
    int line;
    Node_graph *father;
    int children[14];
    int hfunc;
    int gfunc;

    Node_graph(int linee, int *son, int size){
        father = fatherr;
        line = linee;
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
          E1 = new Node_graph(1,array1[], 1);
          E2 = new Node_graph(1,array2[], 3);
          E3 = new Node_graph(1,array3[], 4);
          E4 = new Node_graph(1,array4[], 4);
          E5 = new Node_graph(1,array5[], 4);
          E6 = new Node_graph(1,array6[], 1);
          E7 = new Node_graph(1,array7[], 1);
          E8 = new Node_graph(1,array8[], 4);
          E9 = new Node_graph(1,array9[], 4);
          E10 = new Node_graph(1,array10[], 1);
          E11 = new Node_graph(1,array11[], 1);
          E12 = new Node_graph(1,array12[], 1);
          E13 = new Node_graph(1,array13[], 3);
          E14 = new Node_graph(1,array14[], 1);
          distance = {{ 0 , 11 , 20 , 27 , 40 , 43 , 39 , 28 , 18 , 10 , 18 , 30 , 30 , 32 },
                      {11 , 0  , 9  , 16 , 29 , 32 , 28 , 19 , 11 , 4  , 17 , 23 , 21 , 24 },
                      {20 , 9  , 0  , 7  , 20 , 22 , 19 , 15 , 10 , 11 , 21 , 21 , 13 , 18 },
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
    }

    void

// youcomplete-me vim



};

int main(int argc, char *argv[])
{


    QCoreApplication a(argc, argv);



    return a.exec();
}
