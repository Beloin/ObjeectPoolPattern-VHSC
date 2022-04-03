//
// Created by beloin on 21/03/2022.
//

#ifndef OBJECT_POOL_CPP_VHSCPOOL_H
#define OBJECT_POOL_CPP_VHSCPOOL_H


#include <cstdlib>
#include <iostream>
#include "VeryHardAndSlowCreation.h"

class VHSCPool {
protected:
    VHSCPool(){
        vhs_pool = (VeryHardAndSlowCreation**) malloc((max_pool_size) * sizeof (void*));
        for (int i = 0; i < max_pool_size; ++i) {
            vhs_pool[i] = new VeryHardAndSlowCreation(i);
            current_size++;
        }
    }

private:
    VeryHardAndSlowCreation** vhs_pool;
    int max_pool_size = 10;
    int current_size = 0;
    static VHSCPool * _instance;

public:
    void setMaxPoolSize(int);
    VeryHardAndSlowCreation* acquire();
    void release(VeryHardAndSlowCreation*);
    static VHSCPool * Instance();
    int getMaxPoolSize(){
        return max_pool_size;
    }
    int getCurrentSize(){
        return current_size;
    }

    string getId(int);
};


#endif //OBJECT_POOL_CPP_VHSCPOOL_H
