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
#define println(a, b) (std::cout << std::setprecision((b)) << (a) << std::endl)
#define console(a) (std::cout << (a) << std::endl)

namespace po = boost::program_options;

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

int main(int argc, char *argv[]) {
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
        ("help", "produce help message")
//        ("celsius,C", po::value<std::vector<std::string>>(), "set convert celsius")
//        ("fahrenheit,F", po::value<std::vector<std::string>>(), "set convert fahrenheit")
//        ("kelvin,K", po::value<std::vector<std::string>>(), "set convert kelvin")
        ("convert,cc", po::value<std::vector<std::string>>(), "set convert type");
        
        po::positional_options_description p;
        p.add("convert", 3);
//        p.add("celsius", 1);
//        p.add("fahrenheit", 1);
//        p.add("kelvin", 1);

        po::variables_map vm;
        po::store(
                  po::command_line_parser(argc, argv).options(desc).positional(p).run(),
                  vm
                  );
        po::notify(vm);
        
        if (vm.count("help")) {
            std::string msg = "Usage: ./sample02 convert [CFK] value";
            console(msg);
            return 1;
        }
        
        if (vm.count("convert")) {
            std::vector<std::string> conv = vm["convert"].as<std::vector<std::string>>();
            std::string cmd = conv.at(0);
            std::string target = conv.at(1);
            double value = std::stod(conv.at(2).c_str());
            if (target == "C") {
                conv::temp::celsius<double> c(value);
                std::cout << std::fixed;
                println(c.to_f(), 2);
                println(c.to_k(), 2);
            } else if (target == "F") {
                conv::temp::fahrenheit<double> f(value);
                std::cout << std::fixed;
                println(f.to_c(), 2);
                println(f.to_k(), 2);
            } else if (target == "K") {
                conv::temp::kelvin<double> k(value);
                std::cout << std::fixed;
                println(k.to_c(), 2);
                println(k.to_f(), 2);
            }
        }
        
//        if (vm.count("celsius")) {
//            println("C");
//            std::vector<std::string> conv = vm["celsius"].as<std::vector<std::string>>();
//            //std::string cmd = conv.at(0);
//            //std::string target = conv.at(1);
//            double value = std::stod(conv.at(1).c_str());
//            println(value);
//            conv::temp::celsius<double> c(value);
//            std::cout << std::fixed;
//            println(c.to_f());
//            println(c.to_k());
//        }
//
//        if (vm.count("fahrenheit")) {
//            println("F");
//            std::vector<std::string> conv = vm["fahrenheit"].as<std::vector<std::string>>();
//            double value = std::stod(conv.at(1).c_str());
//            conv::temp::fahrenheit<double> f(value);
//            std::cout << std::fixed;
//            println(f.to_c());
//            println(f.to_k());
//        }
//
//        if (vm.count("kelvin")) {
//            println("K");
//            std::vector<std::string> conv = vm["kelvin"].as<std::vector<std::string>>();
//            double value = std::stod(conv.at(1).c_str());
//            conv::temp::kelvin<double> k(value);
//            std::cout << std::fixed;
//            println(k.to_c());
//            println(k.to_f());
//        }

//        if (vm.count("convert")) {
//            conv = vm["convert"].as<std::vector<std::string>>();
//            std::string cmd = conv.at(0);
//            std::string target = conv.at(1);
//            double value = std::stod(conv.at(2).c_str());
//            if (target == "c") {
//                conv::temp::celsius<double> c(value);
//                std::cout << std::fixed;
//                println(c.to_f());
//                println(c.to_k());
//            }
//        }
    } catch (std::exception &e) {
        console(e.what());
        return 1;
    }

    return 0;
    /*
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
     */
}
