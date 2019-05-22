#include <iostream>
#include <vector>
#include <string>
using namespace std;

int itr=0;

class Node{
public:
    bool state;
    char data;
    Node *next[4];
};

void makeqtree(Node *qtree, string qtree_str, int prexnth){
    for(int i=0; i<4; ++i){
        if(qtree_str[itr]!='x'){
            qtree[itr].state=false;
            qtree[itr].data=qtree_str[itr];
            qtree[prexnth].next[i]=&qtree[itr];
            itr++;
        }
        else{
            qtree[itr].state=true;
            qtree[itr].data='x';
            qtree[prexnth].next[i]=&qtree[itr];
            itr++;
            makeqtree(qtree,qtree_str,itr-1);
        }
    }
} 

void printqtree(Node n,string &ans){
    ans+=n.data;
    if(n.state){
        for(int i=0; i<4; ++i){
            printqtree(*(n.next[i]),ans);
        }
    }
}

int main(){
    int C;
    cin >> C;
    string *ans = new string[C];
    for(int t=0; t<C; ++t){
        string qtree_str;
        cin>>qtree_str;
        Node *qtree = new Node[qtree_str.size()];
        if(qtree_str[0]=='x'){
            qtree[0].state=true;
            qtree[0].data='x';
            itr=1;
            makeqtree(qtree,qtree_str,0);

            for(int i=0; i<qtree_str.size(); ++i){
                if(qtree[i].state){
                    Node *temp[4];
                    for(int j=0; j<4; ++j){
                        temp[j]=qtree[i].next[j];
                    }
                    qtree[i].next[0]=temp[2];
                    qtree[i].next[1]=temp[3];
                    qtree[i].next[2]=temp[0];
                    qtree[i].next[3]=temp[1];
                }
            }
        }
        else{
            qtree[0].data=qtree_str[0];
            qtree[0].state=false;
        }
        printqtree(qtree[0],ans[t]);
        /*for(int i=0; i<qtree_str.size(); ++i){
            if(qtree[i].state){
                cout<<qtree[i].next[0]->data<<" ";
                cout<<qtree[i].next[1]->data<<" ";
                cout<<qtree[i].next[2]->data<<" ";
                cout<<qtree[i].next[3]->data<<" ";
                cout<<endl;
            }
        }*/
        
    }
    for(int i=0; i<C; ++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}