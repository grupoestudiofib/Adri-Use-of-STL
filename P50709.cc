//DONE
#include <iostream>
#include <queue>                                            
using namespace std;

int main(){
    
    priority_queue<int> pq;                                     //priority dcon el mayor al inicio, alqays ordered :)
    char op;
    while(cin>>op){
        
        if(op == 'S' or op == 'I' or op == 'D'){
            int n;
            cin>>n;
            if(op == 'S') pq.push(n);
            else if (pq.empty()) cout<<"error!"<<endl;
            else {
                int x = pq.top();
                pq.pop();
                if(op == 'I') pq.push(x + n);
                else pq.push(x - n);
            }
        }
        else if(op == 'A' or op == 'R'){
            if(pq.empty()) cout << "error!" << endl;
            else{
                if(op == 'A') cout << pq.top() << endl;
                else pq.pop();
            }
        }
        
    }
    
    
    
}


//question: como se puede cambiar la priority (si se puedee :) )
