#include "solucion.h"
#include "auxiliares.h"
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

using namespace std;

bool estaEnRangoDeProfundidad (vector<int> a, int p){
    bool res = true;
    for (int i = 0; i<a.size(); i++ ){
        if (a[i] < -pow(2,p-1) || pow(2,p-1)-1 < a[i]){
            res = false;
        }

    }
    return res;
}

bool formatoValido(vector<int> a, int canal, int profundidad) {
    if (a.size() < 1 || a.size() % canal != 0  || !estaEnRangoDeProfundidad(a,profundidad))
        return false;
}

audio replicar(audio a, int canal, int profundidad) {
    audio result = {};
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
            if(abs(a[j])>max){
                max=a[j];
                pos=j;
            }
        }
        maximos.push_back(max);
        posicionesMaximos.push_back(pos);
    }
}

int clip(int v1, int v2, int p){
    if(-pow(2,p-1) <= v2-v1 && v2-v1 <= pow(2,p-1)-1){
        return v2-v1;
    }else{
        if(v2-v1 < -pow(2,p-1)){
            return -pow(2,p-1) ;
        }
        if(v2-v1> pow(2,p-1)-1){
            return pow(2,p-1)-1;
        }
    }
}

audio redirigir (audio a, int canal, int profundidad) {
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
            as[i][j]= floor(as[i][j]/(2^(profundidad1-profundidad2)));
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

audio ordenado (audio a) {
    int i = 0;
    int j = 0;
    for (int i = 0; i < a.size()-1; i++) {
        for (int j = 0; j < a.size() - i-1; j++) {
            if (a[j]  > a[j + 1]) {
                int c = a[j];
                a[j] = a[j + 1];
                a[j + 1] = c;
            }
        }
    }
    return a;
}

bool esOutlier(int valor, int valorminDeOutlier){
 if (valor > valorminDeOutlier){
     return true;
 } else {
     return false;
 }
}

int NoOutlierSiguiente(audio a, int pos, int valorMinimoParaSerOutlier) {
    while (esOutlier(a[pos],valorMinimoParaSerOutlier)) {
        pos++;
    }
    return a[pos];
}
void limpiarAudio(audio& a, int profundidad, vector<int>& outliers) {

    audio audio_ordenado = ordenado(a);
    outliers = {};
int numeroDePosiblesOutliers = a.size() - floor(a.size()*0.95);
int valorMinimoParaSerOutlier = audio_ordenado[a.size()-numeroDePosiblesOutliers-1];
int posDelPrimerNoOutlier= -1;
int numeroDeNoOutliers = 0;
int numeroDeNoOutliersVistos = 0;
int NoOutlierAnterior = -1;
for (int i= 0; i<a.size(); i++){
    if (esOutlier (a[i],valorMinimoParaSerOutlier)) {

        outliers.push_back(i);

    } else {
        if (posDelPrimerNoOutlier == -1) {
            posDelPrimerNoOutlier = i;
        }
        numeroDeNoOutliers++;
    }
}


for (int j=0; j<a.size(); j++){
    if (esOutlier(a[j],valorMinimoParaSerOutlier)){
        if (j < posDelPrimerNoOutlier){
            a[j] = NoOutlierSiguiente(a,j, valorMinimoParaSerOutlier);
        }
        else if (j > posDelPrimerNoOutlier && numeroDeNoOutliersVistos < numeroDeNoOutliers){
            a[j] = floor ((NoOutlierAnterior + NoOutlierSiguiente(a,j, valorMinimoParaSerOutlier) )/ 2);
        }
        else if (numeroDeNoOutliersVistos == numeroDeNoOutliers){
            a[j] = NoOutlierAnterior;
        }

    } else {
        numeroDeNoOutliersVistos++;
        NoOutlierAnterior = a[j];
    }
}

}
