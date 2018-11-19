#ifndef PATH_H
#define PATH_H 
#include <set>
#include <iostream>
#include "Node.h"
using namespace std;

struct Node;//forward declaration

struct Path{
    Node* endpoint;
    int count =0;
    
};
#endif
