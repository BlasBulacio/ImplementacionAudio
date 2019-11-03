#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(reemplazarSubAudioTEST, unElementoYPresente){
    audio a = {1};
    audio a1 = {1};
    audio a2 = {3};
    int profundidad = 5;
    audio esperado = {3};

    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}


TEST(reemplazarSubAudioTEST, unElementoNoPresente){
    audio a = {1};
    audio a1 = {2};
    audio a2 = {3};
    int profundidad = 5;
    audio esperado = {1};
    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}

TEST(reemplazarSubAudioTEST, elBuscadoEsVacio){
    audio a = {1,2,4,5,6};
    audio a1 = {};
    audio a2 = {3,4,5};
    int profundidad = 5;
    audio esperado = {3,4,5,1,2,4,5,6};

    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}


TEST(reemplazarSubAudioTEST, audioBuscadoAlFinal){
    audio a = {1,2,3,4,5,6};
    audio a1 = {5,6};
    audio a2 = {3,4};
    int profundidad = 5;
    audio esperado = {1,2,3,4,3,4};

    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}


TEST(reemplazarSubAudioTEST, audioBuscadoAlPrincipio){
    audio a = {1,2,3,4,5,6};
    audio a1 = {1,2};
    audio a2 = {3,4};
    int profundidad = 5;
    audio esperado = {3,4,3,4,5,6};

    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}

TEST(reemplazarSubAudioTEST, buscadoMayorASustituto){
    audio a = {1,2,4,5,6};
    audio a1 = {1,2,4,5};
    audio a2 = {3,4};
    int profundidad = 5;
    audio esperado = {3,4,6};

    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}

TEST(reemplazarSubAudioTEST, SustitutoMayorABuscado){
    audio a = {1,2,4,5,6};
    audio a1 = {1,2};
    audio a2 = {3,4,5};
    int profundidad = 5;
    audio esperado = {3,4,5,4,5,6};

    reemplazarSubAudio(a, a1, a2, profundidad);

    ASSERT_VECTOR(a, esperado);
}






