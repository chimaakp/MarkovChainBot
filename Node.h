#ifndef NODE_H
#define NODE_H 

#include <set>
#include <iostream>
#include "Path.h"
using namespace std;
struct Path;//forward declaration

struct Node{
    vector<string> next;
    string value;
    
    Node(string s){
        value=s;
    }
     //~Node(){
          //delete &value;
    //      delete &next;
     //}
};

#endif 
