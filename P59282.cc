//DONE
#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main(){

    cout.setf(ios::fixed);
    cout.precision(4);

    map<int,int> m;                                     //map con pairs (k,v) k = numero y v = veces que ha aparecido

    string op;
    int n = 0, num; 
    double sum = 0;
    while(cin>>op){                     
        if(op == "number") {
            cin>>num;
            bool repe = m.find(num) != m.end();         
            if(repe) m[num] += 1;                           //augmento la frecuencia de ese numero en 1 si ya ha aparecido
            else m[num] = 1;                                //forma alt de crear elem en map
            ++n;
            sum += num;

            double avg = sum/n;                             //n no es nunca 0 aquĂ­
            auto last = m.end();                            //arreglillos pal cout
            --last;
            cout<<"minimum: "<<m.begin()->first<<", maximum: "<<last->first<<", average: "<<avg<<endl;
        }   
        else{                                                  //asumo que op == number XOR op == delete
            if(n == 0) cout<<"no elements"<<endl;
            else {
                num = m.begin()->first;                         //m ordenado de menor a mayor, quiero el valor
                if(m.begin()->second > 1) --m.begin()->second;
                else m.erase(m.begin());                    
                --n;
                sum -= num;

                if(n == 0) cout<<"no elements"<<endl;               //puede ser que sea tras este delete que se quede sin elementos => petaria si no es tratado
                else {
                    double avg = sum/n;                             //arreglillos pal cout 2.0
                    auto last = m.end();
                    --last;
                    cout<<"minimum: "<<m.begin()->first<<", maximum: "<<last->first<<", average: "<<avg<<endl;
                }
            }
        }                
    }

}

