//
//  main.cpp
//  sample02
//
//  Created by cep3d on 2018/02/07.
//  Copyright © 2018 cep3d. All rights reserved.
//

#include "config.h"
#include "libs/temperature.hpp"
#include "libs/length.hpp"

#define hr() (std::cout << ("===================================") << std::endl)
#define println(a) (std::cout << std::setprecision(2) << (a) << std::endl)

int main(int argc, const char * argv[]) {
    // temp
    conv::temp::celsius<double> c(20);
    std::cout << std::fixed;
    println(c.to_f());
    println(c.to_k());
    conv::temp::fahrenheit<double> f(68);
    println(f.to_c());
    println(f.to_k());
    conv::temp::kelvin<double> k(300);
    println(k.to_c());
    println(k.to_f());
    hr();
    // length
    conv::length::mile<double> mile(70);
    println(mile.to_m());
    println(mile.to_km());
    conv::length::kilo<double> kilo(40);
    println(kilo.to_mile());
    println(kilo.to_ft());
    conv::length::feet<double> feet(5000);
    println(feet.to_mile());
    println(feet.to_kilo());
    return 0;
}
