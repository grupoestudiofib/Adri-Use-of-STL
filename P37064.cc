//DONE
#include <iostream>
#include <set>
using namespace std;

int main(){
    
    string w;
    if(cin>>w and w != "END") {
        
        cout<<w<<endl;
        int len = 1;
        
        set<string> st;
        st.insert(w);
        auto med = st.begin();
        
        while(cin>>w and w != "END"){
            
            st.insert(w);
            ++len;
            if(w < *med and len%2 == 0) --med;                      //Dependiendo de si el nuevo valor es mayor o menor que la mediana actual esta cambiara
            else if(w > *med and len%2 != 0) ++med;                 //y tambien importa si habia un numero par o impar de elementos, jugar con casos...

            cout<<*med<<endl;
        }
        
    }
    
    
}
