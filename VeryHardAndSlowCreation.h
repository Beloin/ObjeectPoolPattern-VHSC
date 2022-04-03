//
// Created by beloin on 21/03/2022.
//

#ifndef OBJECT_POOL_CPP_VERYHARDANDSLOWCREATION_H
#define OBJECT_POOL_CPP_VERYHARDANDSLOWCREATION_H
#include "string"
using namespace std;
class VeryHardAndSlowCreation {
private:
    int id;
public:
    VeryHardAndSlowCreation(int id){
        for (double i = 0; i < 100000000.0; i=i+0.5) {
            123+123;
        }
        this->id = id;
    }

    string to_String() {
        return to_string(id);
    }

    void to_String(string *str) const {
        *str = to_string(id);
    }
};


#endif //OBJECT_POOL_CPP_VERYHARDANDSLOWCREATION_H
