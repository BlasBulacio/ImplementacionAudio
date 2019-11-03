#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(limpiarAudioTEST, audioSinOutliers){
    audio a = {1};
    audio outliers;
    int profundidad = 6;
    audio audioEsperado = {1};
    audio outliersEsperado = {};

    limpiarAudio(a, profundidad, outliers);

    ASSERT_VECTOR(a, audioEsperado);
    ASSERT_VECTOR(outliers, outliersEsperado);
}



TEST(limpiarAudioTEST, audioConOutliersAlFinal){
    audio a = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40};
    audio outliers;
    int profundidad = 6;

    audio audioEsperado = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,38,38};
    audio outliersEsperado = {38,39};
    limpiarAudio(a,profundidad,outliers);

    ASSERT_VECTOR(a,audioEsperado);
    ASSERT_VECTOR(outliers,outliersEsperado);
}

TEST(limpiarAudioTEST, audioConOutliersAlPrincipioYAlFinal){
    audio a = {39,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,40};
    audio outliers;
    int profundidad = 6;

    audio audioEsperado = {1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,38};
    audio outliersEsperado = {0,39};
    limpiarAudio(a,profundidad,outliers);

    ASSERT_VECTOR(a,audioEsperado);
    ASSERT_VECTOR(outliers,outliersEsperado);
}

TEST(limpiarAudioTEST, audioConOutliersAlPrincipio){

    audio a = {39, 40, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
               27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    audio outliers;
    int profundidad = 6;

    audio audioEsperado = {1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                           25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    audio outliersEsperado = {0, 1};
    limpiarAudio(a, profundidad, outliers);

    ASSERT_VECTOR(a, audioEsperado);
    ASSERT_VECTOR(outliers, outliersEsperado);
}

TEST(limpiarAudioTEST, audioConOutliersEnElMedio){

    audio a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,39,40, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
               27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    audio outliers;
    int profundidad = 6;

    audio audioEsperado = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
                           25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38};
    audio outliersEsperado = {10, 11};
    limpiarAudio(a, profundidad, outliers);

    ASSERT_VECTOR(a, audioEsperado);
    ASSERT_VECTOR(outliers, outliersEsperado);
}

