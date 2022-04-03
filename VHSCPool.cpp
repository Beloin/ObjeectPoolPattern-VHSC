//
// Created by beloin on 21/03/2022.
//

#include "VHSCPool.h"

void VHSCPool::setMaxPoolSize(int new_max) {
    if (new_max < max_pool_size) throw "New max pool size cannot be lower than current max size.";

    // Free all current objects and create new others.
    for (int i = 0; i < max_pool_size; ++i) {
        free(vhs_pool[i]);
    }
    free(vhs_pool);
    vhs_pool = (VeryHardAndSlowCreation**) malloc(new_max * sizeof (void*));
    max_pool_size = new_max;
    for (int i = 0; i < new_max; ++i) {
        vhs_pool[i] = new VeryHardAndSlowCreation(i);
    }
    current_size = new_max;

    // Create missing objects ones
//    if (new_max > max_pool_size){
//        auto temp = (VeryHardAndSlowCreation**) malloc(max_pool_size * sizeof (void*));
//        for (int i = 0; i < max_pool_size; ++i) {
//            temp[i] = vhs_pool[i];
//        }
//        // Works?
//        free(vhs_pool);
//
//        vhs_pool = (VeryHardAndSlowCreation**) malloc(new_max * sizeof (void*));
//        for (int i = 0; i < max_pool_size; ++i) {
//            vhs_pool[i] = temp[i];
//        }
//
//        for (int i = new_max-1; i > max_pool_size; --i) {
//            vhs_pool[i] = new VeryHardAndSlowCreation(i);
//        }
//
//        max_pool_size = new_max;
//        current_size = new_max;
//        free(temp);
//    }
}

VeryHardAndSlowCreation *VHSCPool::acquire() {
    if (current_size == 0) throw "There's no objects to pull";
    current_size--;
    VeryHardAndSlowCreation* g = vhs_pool[current_size];
    vhs_pool[current_size] = nullptr;
    return g;
}

void VHSCPool::release(VeryHardAndSlowCreation * vhs) {
    if (current_size == max_pool_size) delete vhs;
    else {
        vhs_pool[current_size] = vhs;
        current_size++;
    }
}

VHSCPool *VHSCPool::_instance = nullptr;
VHSCPool *VHSCPool::Instance() {
    if (_instance == nullptr) _instance = new VHSCPool();
    return _instance;
}

string VHSCPool::getId(int i) {
    return vhs_pool[i]->to_String();
}
