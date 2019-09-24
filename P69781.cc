//DONE
#include <iostream>
#include <map>
using namespace std;

int main(){
    
    int x,y,n;
    while(cin>>x>>y>>n){
        map<int,int> m;
        auto it = m.begin();
        m.insert(make_pair(n,0));
        bool repe = false;
        int r;
        for(int i = 1; n <= 100000000 and not repe; ++i){
            if(n%2 == 0)  n = n/2 + x; 
            else n = 3*n + y;
            it = m.find(n);    
            if(it == m.end()) m.insert(make_pair(n,i));             //ver si aparece en la seq un elemento repetido, si aparece es que hay un ciclo :)
            else {
                repe = true;
                r = i - it->second;                    
            }
        }
        if(repe) cout<<r<<endl;
        else cout<<n<<endl;
    }
    
}
