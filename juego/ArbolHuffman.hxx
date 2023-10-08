#include <iostream>
#include <utility>
#include <vector>
 
 
// structura de los nodos
struct Node {
    char caracter;
    int freq;
    Node *l, *r;
 
    Node(char c, int f)
        : caracter(c)
        , freq(f)
        , l(nullptr)
        , r(nullptr)
    {
    }
};

