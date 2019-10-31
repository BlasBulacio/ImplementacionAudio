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

void audiosSoftYHard(vector<audio> as, int profundidad, int longitud, int umbral, vector<audio>& soft, vector<audio>& hard) {

}

void reemplazarSubAudio(audio& a, audio a1, audio a2, int profundidad) {

}

void maximosTemporales(audio a, int profundidad, vector<int> tiempos, vector<int>& maximos, vector<pair<int,int> > &intervalos ) { //O(|tiempos|*|a|)
    int d;
    int h;
    int max;
    for(int i=0;i<tiempos.size();i++){ //O(|tiempos|)
        d=0; //desde
        h=tiempos[i]-1; //hasta
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

