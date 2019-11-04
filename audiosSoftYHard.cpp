#include "../solucion.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(audiosSoftYHardTEST, listaVacia){
    vector<audio> as = {};
    int profundidad = 8;
    int longitud = 2;
    int umbral = 2;
    vector<audio> soft = {};
    vector<audio> hard = {};

    vector<audio> esperadoSoft = {};
    vector<audio> esperadoHard = {};

    audiosSoftYHard(as, profundidad, longitud, umbral, soft, hard);

    ASSERT_MATRIX(soft, esperadoSoft);
    ASSERT_MATRIX(hard, esperadoHard);
}

TEST(audiosSoftYHardTEST, unSoloElemento){
    vector<audio> as = {{1}};
    int profundidad = 8;
    int longitud = 2;
    int umbral = 2;
    vector<audio> soft = {};
    vector<audio> hard = {};

    vector<audio> esperadoSoft = {{1}};
    vector<audio> esperadoHard = {};

    audiosSoftYHard(as, profundidad, longitud, umbral, soft, hard);

    ASSERT_MATRIX(soft, esperadoSoft);
    ASSERT_MATRIX(hard, esperadoHard);
}

TEST(audiosSoftYHardTEST, todosSoft){
    vector<audio> as = {{1},{2,4,5},{6,6,5},{1,-1,-5,0,1}};
    int profundidad = 8;
    int longitud = 4;
    int umbral = 2;
    vector<audio> soft = {};
    vector<audio> hard = {};

    vector<audio> esperadoSoft = {{1},{2,4,5},{6,6,5},{1,-1,-5,0,1}};
    vector<audio> esperadoHard = {};

    audiosSoftYHard(as, profundidad, longitud, umbral, soft, hard);

    ASSERT_MATRIX(soft, esperadoSoft);
    ASSERT_MATRIX(hard, esperadoHard);
}

TEST(audiosSoftYHardTEST, todosHard){
    vector<audio> as = {{4,5,6},{2,4,5},{1,2,3},{1,1,1,1,2,3,1}};
    int profundidad = 8;
    int longitud = 2;
    int umbral = 1;
    vector<audio> soft = {};
    vector<audio> hard = {};

    vector<audio> esperadoSoft = {};
    vector<audio> esperadoHard = {{4,5,6},{2,4,5},{1,2,3},{1,1,1,1,2,3,1}};

    audiosSoftYHard(as, profundidad, longitud, umbral, soft, hard);

    ASSERT_MATRIX(soft, esperadoSoft);
    ASSERT_MATRIX(hard, esperadoHard);
}

TEST(audiosSoftYHardTEST, haySoftYHard){
    vector<audio> as = {{4,5,6},{2,4,5},{1,2,3},{2,2,2,5,5,5}};
    int profundidad = 8;
    int longitud = 3;
    int umbral = 2;
    vector<audio> soft = {};
    vector<audio> hard = {};

    vector<audio> esperadoSoft = {{2,4,5},{1,2,3}};
    vector<audio> esperadoHard = {{4,5,6},{2,2,2,5,5,5}};

    audiosSoftYHard(as, profundidad, longitud, umbral, soft, hard);

    ASSERT_MATRIX(soft, esperadoSoft);
    ASSERT_MATRIX(hard, esperadoHard);
}
