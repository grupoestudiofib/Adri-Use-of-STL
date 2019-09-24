//DONE
#include <iostream>
#include <map>
using namespace std;

typedef map<string,int>::iterator mit;


int main(){
    
    map<string,int> casino;                                                             //map will order itselve rigth  
    mit i = casino.begin();    
    
    string person, action;
    while(cin>>person and cin>>action){         
        
        i = casino.find(person);                                                        //averiguar si esta :)
        
        if(action == "enters"){                                                          
            if(i == casino.end()){
                casino.insert(make_pair(person,0));  
            }
            else cout<<person<<" is already in the casino"<<endl;
            
        }
        else if(action == "leaves"){
            if(i == casino.end()) cout<<person<<" is not in the casino"<<endl;
            else {
                int n = casino[person];
                casino.erase(i);
                cout<<person<<" has won "<<n<<endl;
            }
            
        }
        else if(action == "wins"){
            int n;
            cin>>n;
            if(i == casino.end()) cout<<person<<" is not in the casino"<<endl;
            else casino[person] += n;                       //si no recuerdo mal se hacia asin ;)            
        }
        
    }
    
    cout<<"----------"<<endl;
    
    //print casino status (players that have not left) :)
    
    for (i = casino.begin(); i != casino.end(); ++i)   //reutilizar i
    cout << i->first << " is winning " << i->second << endl;   
    
}
