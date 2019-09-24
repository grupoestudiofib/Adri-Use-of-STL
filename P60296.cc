//DONE  (pero cochinoso)
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef map<string,pair<int,bool>> Mp;                   
typedef map<string,pair<int,bool>>::iterator mit;

bool cmp(const pair<string,int>& a, const pair<string,int>& b){                                 //ordenacion para los outputs (me gustaria saber como se hace bien con la STL)
    if(a.second == b.second) return a.first <= b.first; 
    return a.second > b.second; 
}

int main(){

    Mp server;
    string op, player;

    while(cin>>op>>player){
        mit i = server.find(player);
        bool exists = i != server.end();
        if(op == "LOGIN"){  
            if(exists) (i->second).second = true;                                                //ya estaba registrado, ahora esta online; suda de si ya estaba online o no... 
            else {                                                                              //el jugador nunca habia aparecido, => lo creo :)
                pair<int,bool> p = make_pair(1200,true); 
                server.insert(make_pair(player,p));
            }
        }
        else if(op == "LOGOUT"){  
            if(exists){
                (i->second).second = false; 
            }                                                                                   //asumo que si no existe y no estaba no ocurre o no se hace nada

        }
        else if(op == "PLAY"){
            string contender;
            cin>>contender;
            mit j = server.find(contender);                                                     //pre: i != j (nunca ocurre) ?  :)
            if(exists and j != server.end() and (i->second).second and (j->second).second){       //los dos existen y estan online
                (i->second).first += 10;
                if((j->second).first >= 1210) (j->second).first -= 10;
            }
            else cout<<"player(s) not connected"<<endl;                                         
        }
        else if(op == "GET_ELO"){   
            if(exists) cout<<player<<' '<<(i->second).first<<endl;                               //existe (da igual online o no) 
        }
    }
    
    cout<<endl<<"RANKING"<<endl;
    
    int len = server.size();                                    
    vector<pair<string,int>> v (len);                                                           //meter los datos del map en un vector y ordenarlo como me da la gana (esta feo :( but...)
    mit it = server.begin();
    for(int i = 0; it != server.end(); ++i){                                                    //quiero a los online y a los offline :)
        v[i] = make_pair(it->first,(it->second).first);   
        ++it;                                            
    }

    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < len; ++i) cout<<v[i].first<<' '<<v[i].second<<endl;

} 
//comprobar las pre asumidas y que haya mapeado bien las posibilidades 