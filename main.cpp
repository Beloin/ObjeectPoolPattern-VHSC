
#include <iostream>
#include "VHSCPool.h"

int main(){
    cout << "Creating Pool With Objects.\n";
    VHSCPool *pool = VHSCPool::Instance();

    std::cout << "Current Pool Size: " << pool->getCurrentSize();
    std::cout << "\n";
    std::cout << "Max Pool Size: " << pool->getMaxPoolSize();
    std::cout << "\n";
    std::cout << "Increasing size for pool." << endl;
    pool->setMaxPoolSize(20);
    std::cout << "New Max Pool Size: " << pool->getMaxPoolSize();
    std::cout << "\n";

    std::cout << "Current Size: " << pool->getCurrentSize() << "\n";

    cout << "Acquire item\n";
    auto r = pool->acquire();
    std::cout << "New Size: " << pool->getCurrentSize() << "\n";

    cout << "Acquired Item id: " << r->to_String() << "\n";
    cout << "Released item\n";
    pool->release(r);
    std::cout << "Size after Item released: " << pool->getCurrentSize() << "\n";
}
