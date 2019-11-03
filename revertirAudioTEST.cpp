#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(revertirAudioValidoTEST, unCanal){
    audio a = {1,2,3,-5,-2,-10,0};
    int canal = 1;
    int profundidad = 6;
    audio esperado = {0,-10,-2,-5,3,2,1};

    ASSERT_VECTOR(revertirAudio(a, canal, profundidad), esperado);
}

TEST(revertirAudioValidoTEST, dosCanales){
    audio a = {1,4,2,3,-5,-2,-10,0};
    int canal = 1;
    int profundidad = 6;
    audio esperado = {-10,0,-5,-2,2,3,1,4};

    ASSERT_VECTOR(revertirAudio(a, canal, profundidad), esperado);
}

TEST(revertirAudioValidoTEST, unElemento){
    audio a = {2};
    int canal = 1;
    int profundidad = 6;
    audio esperado = {2};

    ASSERT_VECTOR(revertirAudio(a, canal, profundidad), esperado);
}

TEST(revertirAudioValidoTEST, igualCanalesQueValores){
    audio a = {1,2,3,4,5,6,7,8,9,10};
    int canal = 10;
    int profundidad = 6;
    audio esperado = {1,2,3,4,5,6,7,8,9,10};

    ASSERT_VECTOR(revertirAudio(a, canal, profundidad), esperado);
}

