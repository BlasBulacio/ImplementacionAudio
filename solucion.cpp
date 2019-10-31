#include "solucion.h"
#include "auxiliares.h"
#include <algorithm>
#include <cmath>

using namespace std;

bool formatoValido(audio a, int canal, int profundidad) {
    return true;
}

audio replicar(audio a, int canal, int profundidad) {
    return a;
}

audio revertirAudio(audio a, int canal, int profundidad) {
    return a;
}

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

void maximosTemporales(audio a, int profundidad, vector<int> tiempos, vector<int>& maximos, vector<pair<int,int> > &intervalos ) { //O(|tiempos|*|a|)
    int d; //desde
    int h; //hasta
    int max;
    for(int i=0;i<tiempos.size();i++){ //O(|tiempos|)
        d=0; 
        h=tiempos[i]-1; 
        max=a[0];
        for(int j=0;j<a.size();j++){ //O(|a|)
        if(j<=h){
            if(a[j]>=max){
                max=a[j];
                }
            }else{
            intervalos.push_back(make_pair(d,h));
            maximos.push_back(max);
            d=j;
            h=j+tiempos[i]-1;
            max=a[j];
            }
        }
        maximos.push_back(max);                  // Agrego esto porque si j<=h y h>=audio.size() entonces nunca entra al else a pushear las cosas
        intervalos.push_back(make_pair(d,h));
    }
}
void limpiarAudio(audio& a, int profundidad, vector<int>& outliers) {


}

