#include "solucion.h"
#include "auxiliares.h"
#include <algorithm>
#include <cmath>

using namespace std;

using namespace std;

bool estaEnRangoDeProfundidad (vector<int> a, int p){
    bool res = true;
    for (int i = 0; i<a.size(); i++ ){
        if (a[i] < (-2^(p-1)) || (2^(p-1) -1) > a[i]){
            res = false;
        }

    }
    return res;
}

bool formatoValido(vector<int> a, int canal, int profundidad) {
    if (a.size() < 1 || a.size() % canal != 0  || !estaEnRangoDeProfundidad(a,profundidad))
        return true;
}

audio replicar(audio a, int canal, int profundidad) {
    audio result;
    for (int i = 0; i< a.size(); i++){
        for (int j = 0; j< canal; j++){
            result.push_back(a[i]);
        }
    }
    return result;
}

audio revertirAudio(audio a, int canal, int profundidad) {
    audio result;
    int cantDeBloques = a.size() / canal;
    for(int i = cantDeBloques-1; i > -1; i--){
        for(int j = 0; j<canal; j++) {
            result.push_back(a[(canal*i)+j]);
        }

    }
    return result;
}

//Tiene complejidad O(n) puesto que el T(n) =  k0 +(k1 * n/canal)* k3*canal.

void magnitudAbsolutaMaxima(audio a, int canal, int profundidad, vector<int> &maximos, vector<int> &posicionesMaximos) {
    maximos={};
    posicionesMaximos={};
    for(int i=0;i<canal;i++){
        int max=a[0+i];
        int pos=0+i;
        for(int j=i;j<a.size();j=j+canal){
            if(abs(a[j])>=max){
                max=a[j];
                pos=j;
            }
        }
        maximos.push_back(max);
        posicionesMaximos.push_back(pos);
    }
}

int clip(int v1, int v2, int p){
    if((-2)^(p-1)<=v2-v1<=(2^(p-1)-1)){
        return v2-v1;
    }else{
        if(v2-v1<(-2)^(p-1)){
            return (-2)^(p-1);
        }
        if(v2-v1>(2^(p-1)-1)){
            return (2^(p-1)-1);
        }
    }
}

audio redirigir(audio a, int canal, int profundidad) {
    int n;
    if(canal==1){
        n=1;
    }else{
        n=-1;
    }
    for(int i=canal-1;i<a.size();i=i+2){
        a[i+n]=clip(a[i],a[i+n],profundidad);
    }
    return a;
}

void bajarCalidad(vector<audio> & as, int profundidad1, int profundidad2) {
    for(int i=0;i<as.size();i++){
        for(int j=0;j<as[i].size();j++){
            as[i][j]= static_cast<int>(as[i][j]/(2^(profundidad1-profundidad2)));
        }
    }
}

bool esHard(audio a,int longitud, int umbral){
    int cont=0;
    for(int i=0;i<a.size();i++){
        if(a[i]>umbral){
            cont++;
            if(cont=longitud){
                return true;
            }
        }else{
            cont=0;
        }
    }
        return false;
}


void audiosSoftYHard(vector<audio> as, int profundidad, int longitud, int umbral, vector<audio>& soft, vector<audio>& hard) {
    for(int i=0;i<as.size();i++){
        if(esHard(as[i],longitud,umbral)){
            hard.push_back(as[i]);
        }else{
            soft.push_back(as[i]);
        }
    }
}

vector<int> subseq(vector<int> vec, int d, int h){
    vector<int> vector={};
    for(int i = d;i<h;i++){
        vector.push_back(vec[i]);
    }
    return vector;
}

vector<int> concatenarSecuencias(vector<int> seq1, vector<int> seq2){
    vector<int> res={};
    for(int i=0;i<seq1.size()+seq2.size();i++){
        if(i<seq1.size()){
            res.push_back(seq1[i]);
        }else{
            res.push_back(seq2[i-seq1.size()]);
        }
    }
    return res;
}

void reemplazarSubAudio(audio& a, audio a1, audio a2, int profundidad) {
    for(int i=0;i<=a.size()-a1.size()+1;i=i+1){
         if(subseq(a,i,i+a1.size())==a1){
             a=concatenarSecuencias(concatenarSecuencias(subseq(a,0,i),a2),subseq(a,i+a1.size(),a.size()));
            break;
         }
    }
}

void maximosTemporales(audio a, int profundidad, vector<int> tiempos, vector<int>& maximos, vector<pair<int,int> > &intervalos ) {

}

void limpiarAudio(audio& a, int profundidad, vector<int>& outliers) {


}

