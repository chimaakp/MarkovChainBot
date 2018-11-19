#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include<iterator>
#include<fstream>
#include <time.h>  
#include "Node.h"
#include "Path.h"
using namespace std;

int main(){
        string str ("Bottom seuss Text. hahahah Bottom dr dr seuss goose Bottom hahahah loose seuss caboose");


    //reads from file
     std::ifstream file( "text.txt" );
     std::stringstream iss;

    if ( file )
    {
        
        iss << file.rdbuf();

        file.close();

        // operations on the buffer...
    }


        //istringstream iss (str);

        vector<Node>* wordlist= new vector<Node> ;
        string tmp;
        Node* prev = NULL;
        getline(iss, tmp,' ');
        wordlist->push_back(*(new Node(tmp)));
        prev=&wordlist->back();
        vector<Node>::iterator it;
        Node* curr;
        
        while(!iss.eof()){
            //cout<<endl<<"FINDING ERROR"<<endl;
            getline(iss, tmp,' ');//ERROR
            //cout<<endl<<"FINDING ERROR"<<endl;
            for(it =wordlist->begin();it!=wordlist->end();it++){
                if(!it->value.compare(tmp)){
                    //cout<<tmp<<" is already in"<<endl;
                     curr =&*it;
                     prev->next.push_back(tmp);
                     prev= curr;
                    break;
                    
                }
                else{
                    //cout<<tmp<<" isnt at this index"<<endl;
                }
                
            }
            if(it==wordlist->end()){//words added for the first time WTF IS GOING ON IN THIS LOOP
                //cout<<endl<<endl<<endl<<tmp<<" isnt in the wordlist"<<endl<<endl<<endl;
                Node* npoint = new Node(tmp);
                prev->next.push_back(tmp);
                wordlist->push_back(*npoint);//THIS MIGHT BE THE PROBLEM
                //wordlist->push_back(*(new Node(tmp)));
                //linked to ERROR ths does not do what it is supposed to do
                //cout<<endl<<"Make "<<(prev-> value)<<" point to "<<tmp<<endl;
                  prev=&wordlist->back();
                //cout<<"adding "<<tmp<<endl;
                
            }

        }
        
        //print vector
        //cout<<endl<<"Print Everything"<<endl;
        for(it =wordlist->begin();it!=wordlist->end();it++){
            //cout<<it->value<<endl;
        }
        
        cout<<"Bot printing "<<endl;
         srand (time(NULL));
         int randomIndex = rand() % (wordlist->size());
         //cout<<"index "<<randomIndex<<" of "<<wordlist->size()-1 <<endl;
         int slength =200;//sentance length
         prev =&wordlist->at(randomIndex);
         for(slength;slength>=0;slength--){
            cout<<prev->value<<" ";
             randomIndex =rand() % (prev->next.size());
             //cout<<"index "<<randomIndex<<" of "<<prev->next.size()-1 <<endl;
             tmp = prev->next[randomIndex];
             //cout<<tmp<<endl;
             for(it =wordlist->begin();it!=wordlist->end();it++){
                 if(!it->value.compare(tmp)){
                     prev = &*it;
                 }
             }
             //prev = &prev->next.at(randomIndex);
         }
}
