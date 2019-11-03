#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(redirigirTEST, canal1EnRango){
    audio a = {1,2,3,-5,-2,-10};
    int canal = 1;
    int profundidad = 6;
    audio esperado = {1,1,3,-8,-2,-8};

    ASSERT_VECTOR(redirigir(a, canal, profundidad), esperado);

}

TEST(redirigirTEST, canal2EnRango){
    audio a = {1,2,3,-5,-2,-10};
    int canal = 2;
    int profundidad = 6;
    audio esperado = {-1,2,8,-5,8,-10};

    ASSERT_VECTOR(redirigir(a, canal, profundidad), esperado);

}

TEST(redirigirTEST, canal1FueraDeRango){
    audio a = {1,2,3,-4,-2,2};
    int canal = 1;
    int profundidad = 3;
    audio esperado = {1,1,3,-4,-2,3};

    ASSERT_VECTOR(redirigir(a, canal, profundidad), esperado);

}

TEST(redirigirTEST, canal2FueraRango){
    audio a = {1,2,3,-4,-2,3};
    int canal = 2;
    int profundidad = 3;
    audio esperado = {-1,2,3,-4,-4,3};

    ASSERT_VECTOR(redirigir(a, canal, profundidad), esperado);

}