#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(formatoValidoTEST, longitudErronea){
    audio a = {1,2,3,4,5};
    int canal = 3;
    int profundidad = 4;

    EXPECT_FALSE(formatoValido(a, canal, profundidad));
}

TEST(formatoValidoTEST, fueraDeRangoDeProfundiad){
    audio a = {1,2,3,4,5,6};
    int canal = 3;
    int profundidad = 1;

    EXPECT_FALSE(formatoValido(a, canal, profundidad));
}

TEST(formatoValidoTEST, audioVacio){
    audio a = {};
    int canal = 3;
    int profundidad = 1;

    EXPECT_FALSE(formatoValido(a, canal, profundidad));
}

TEST(formatoValidoTEST, fueraDeRangoDeProfundidadYLongitudErronea){
    audio a = {1,2,3,8};
    int canal = 3;
    int profundidad = 1;

    EXPECT_FALSE(formatoValido(a, canal, profundidad));
}

TEST(formatoValidoTEST, formatoValido){
    audio a = {1,2,3};
    int canal = 3;
    int profundidad = 3;

    EXPECT_TRUE(formatoValido(a, canal, profundidad));
}