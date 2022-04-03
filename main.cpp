
#include <iostream>
#include "VHSCPool.h"

int main(){
    cout << "Creating Pool With 10 default VHSC Objects...\n";
    VHSCPool *pool = VHSCPool::Instance();

    std::cout << endl;
    std::cout << "Current Pool Size: " << pool->getCurrentSize();
    std::cout << "\n";
    std::cout << "Max Pool Size: " << pool->getMaxPoolSize();
    std::cout << "\n";

    std::cout << endl;
    std::cout << "Increasing max pool size to 20..." << endl;
    pool->setMaxPoolSize(20);
    std::cout << endl;
    std::cout << "New Max Pool Size: " << pool->getMaxPoolSize();
    std::cout << "\n";

    std::cout << endl;
    cout << "Acquiring item\n";
    auto r = pool->acquire();
    std::cout << endl;
    std::cout << "New Size: " << pool->getCurrentSize() << "\n";

    cout << "Acquired Item id: " << r->to_String() << "\n";
    std::cout << endl;

    cout << "Released item.\n";
    pool->release(r);

    std::cout << "Size after Item released: " << pool->getCurrentSize() << "\n";
}
