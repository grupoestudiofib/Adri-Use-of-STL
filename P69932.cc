//DONE
#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main(){

    string str;
    while(getline(cin,str)){

        set<int> st;
        istringstream iss(str);
        int x;
        while (iss >> x) {
            st.insert(x);
        }

        int setsize = st.size();        
        if(setsize < 2) {
            if(setsize == 0) cout<<0<<endl;
            else cout<<1<<endl;
        }
        else {
            auto it = st.begin(), ed = st.end();
            bool pari = *it%2;
            ++it;
            int l = 1;                                      //siempre hay al menos 1 a estas alturas tt
            while(it != ed){
                if(pari != *it%2) {
                    ++l;
                    pari = not pari;                        //neg == shipt paridad
                }
                ++it;
            }
            cout<<l<<endl;
        }
        
    }


    
}

