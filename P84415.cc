//DONE
#include <iostream>
#include <map> 
using namespace std;
typedef map<string,int>::iterator mit;

int main(){
    
    map<string,int> bw;
    
    string action;
    while(cin>>action){
        
        if(action == "minimum?") {
            if(bw.begin() == bw.end()) cout<<"indefinite minimum"<<endl;
            else cout<<"minimum: "<<bw.begin()->first<<", "<<bw.begin()->second<<" time(s)"<<endl;
        }
        
        else if(action == "maximum?") {
            if(bw.begin() == bw.end()) cout<<"indefinite maximum"<<endl;
            else {
                mit i =  bw.end();
                --i;
                 cout<<"maximum: "<<i->first<<", "<<i->second<<" time(s)"<<endl;
            }
        }
        
        else{
            string p;
            cin>>p;
            mit i = bw.find(p);
            bool exists = i != bw.end();
            if(action == "store"){
                if(exists) bw[p] += 1;  //se puede ++bw[p];
                else bw.insert(make_pair(p,1));
            }
            else if(action == "delete" and exists) {
                if(bw[p] == 1) bw.erase(i);
                else bw[p] -= 1;
            }
        }
        
    }
    
    
}

//segun que criterio ordena el map de primeras? Como se cambia? (igual con las priority_queues...)
