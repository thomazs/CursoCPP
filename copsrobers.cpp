/***************************
* Criado por Marcos Thomaz da Silva
* marcosthomazs@gmail.com
*/////////////////////////////////

#include <iostream>

using namespace std;

#define L 5

bool has_ok(const int w[L][L], int latual=0, int catual=0, bool volta=true){
    int PP = L-1;
    bool achou = false;
    //cout << "(" << latual << ";" << catual <<")";
    //if (w[PP][PP] == 1 || w[0][0] == 1) return false;
    if (w[0][0] == 1) return false;
    if (latual == PP && catual == PP) return (w[PP][PP] == 0);
    if (volta && catual > 0 && latual < PP && w[latual][catual-1] == 0){
        volta = false;
        while (catual > 0 && latual < PP && w[latual][catual-1] == 0) catual--;
    }
    if (achou == false && latual < PP && w[latual+1][catual] == 0) achou = has_ok(w, latual+1, catual, true);
    if (achou == false && catual < PP && w[latual][catual+1] == 0) achou = has_ok(w, latual, catual+1, volta);
    return achou;
}

int main(){
    int t, suml, sumc;
    cin >> t;
    int w[L][L];
    for(int m=0; m<t; m++){
        for(int l=0; l<L; l++)
            for(int c=0; c<L; c++)
                cin >> w[l][c];
        if (has_ok(w))
            cout << "COPS" << endl;
        else
            cout << "ROBBERS" << endl;
    }
    return 0;
}
