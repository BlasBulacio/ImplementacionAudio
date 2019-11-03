#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(magnitudAbsolutaMaximaTEST, unCanal){
    audio a = {1,2,3,-2};
    int canal = 1;
    int profundidad = 6;
    audio maximos, posicionesMaximos = {};

    audio maximosEsperados = {3};
    audio posicionesMaximosEsperados = {2};

    magnitudAbsolutaMaxima(a, canal, profundidad, maximos, posicionesMaximos);

    ASSERT_VECTOR(maximos, maximosEsperados);
    ASSERT_VECTOR(posicionesMaximos, posicionesMaximosEsperados);
}

TEST(magnitudAbsolutaMaximaTEST, dosCanales){
    audio a = {1,2,3,-2};
    int canal = 2;
    int profundidad = 6;
    audio maximos, posicionesMaximos = {};

    audio maximosEsperados = {3,2};
    audio posicionesMaximosEsperados = {2,1};

    magnitudAbsolutaMaxima(a, canal, profundidad, maximos, posicionesMaximos);

    ASSERT_VECTOR(maximos, maximosEsperados);
    ASSERT_VECTOR(posicionesMaximos, posicionesMaximosEsperados);
}

TEST(magnitudAbsolutaMaximaTEST, mismosCanalesQueValores){
    audio a = {1,2,3,-2};
    int canal = 4;
    int profundidad = 6;
    audio maximos, posicionesMaximos = {};

    audio maximosEsperados = {1,2,3,-2};
    audio posicionesMaximosEsperados = {0,1,2,3};

    magnitudAbsolutaMaxima(a, canal, profundidad, maximos, posicionesMaximos);

    ASSERT_VECTOR(maximos, maximosEsperados);
    ASSERT_VECTOR(posicionesMaximos, posicionesMaximosEsperados);
}

TEST(magnitudAbsolutaMaximaTEST, UnicoElemento){
    audio a = {1};
    int canal = 1;
    int profundidad = 6;
    audio maximos, posicionesMaximos = {};

    audio maximosEsperados = {1};
    audio posicionesMaximosEsperados = {0};

    magnitudAbsolutaMaxima(a, canal, profundidad, maximos, posicionesMaximos);

    ASSERT_VECTOR(maximos, maximosEsperados);
    ASSERT_VECTOR(posicionesMaximos, posicionesMaximosEsperados);
}

TEST(magnitudAbsolutaMaximaTEST, todosIguales){
    audio a = {6,6,6,6,6,6};
    int canal = 2;
    int profundidad = 6;
    audio maximos, posicionesMaximos = {};

    audio maximosEsperados = {6,6};
    audio posicionesMaximosEsperados = {0,1};

    magnitudAbsolutaMaxima(a, canal, profundidad, maximos, posicionesMaximos);

    ASSERT_VECTOR(maximos, maximosEsperados);
    ASSERT_VECTOR(posicionesMaximos, posicionesMaximosEsperados);
}

TEST(magnitudAbsolutaMaximaTEST, maximosAlFinal){
    audio a = {6,6,6,9,7,8};
    int canal = 3;
    int profundidad = 6;
    audio maximos, posicionesMaximos = {};

    audio maximosEsperados = {9,7,8};
    audio posicionesMaximosEsperados = {3,4,5};

    magnitudAbsolutaMaxima(a, canal, profundidad, maximos, posicionesMaximos);

    ASSERT_VECTOR(maximos, maximosEsperados);
    ASSERT_VECTOR(posicionesMaximos, posicionesMaximosEsperados);
}
