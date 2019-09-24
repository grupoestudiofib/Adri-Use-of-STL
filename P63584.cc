//DONE 
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> VI; 
typedef vector<VI> VVI;

//pre: no elems repes y 1 <= k <= m
//pre:  => el map nunca se quedaria vacio segun mi code tt
int k_esim(int k, const VVI& V){                                            
    
    map<int,int> m;
    int nfils = V.size();
    vector<int> col_track (nfils, 1);
    
    for(int i = 0; i < nfils; ++i) if(not V[i].empty()) m.insert(make_pair(V[i][0], i));

    for(int i = 1; i < k; ++i){       

        int fil_menor = m.begin()->second;      
        m.erase(m.begin());

        bool elems_in_fil = col_track[fil_menor] < V[fil_menor].size();
        if(elems_in_fil){
            m.insert(make_pair(V[fil_menor][col_track[fil_menor]], fil_menor));
            ++col_track[fil_menor];
        }       
    }
    return m.begin()->first;
}

int main(){
    /*int m;
    cin>>m;             
    VVI V (m);                                                         
    for(int i = 0; i < m; ++i){
        int n;
        cin>>n;
        VI v (n);
        for(int j = 0; j < n; ++j) cin>>v[j];
        V[i] = v;
    }
    cout<<"mete la k: ";
    int k;
    cin>>k;
    cout<<"resultao: "<<k_esim(k, V)<<endl;*/
}