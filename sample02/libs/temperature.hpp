//
//  temperature.hpp
//  sample02
//
//  Created by cep3d on 2018/02/07.
//  Copyright © 2018 cep3d. All rights reserved.
//

#ifndef temperature_hpp
#define temperature_hpp

#include "config.h"

namespace conv {
    // temperature
    namespace temp
    {
        enum TemperatureType {
            CELSIUS,
            FAHRENHEIT,
            KELVIN
        };
        template <class T>
        class celsius {
            T a;
        public:
            celsius(T a) { this->a = a; }
            // to fahrenheit
            T to_f() { return (this->a * 1.8) + 32; }
            // to kelvin
            T to_k() { return this->a + 273.15; }
        };
        
        template <class T>
        class fahrenheit {
            T a;
        public:
            fahrenheit(T a) { this->a = a; }
            // to celsius
            T to_c() { return (this->a - 32) / 1.8; }
            // to kelvin
            T to_k() { return (this->a - 32) * 5/9 + 273.15; }
        };
        
        template <class T>
        class kelvin {
            T a;
        public:
            kelvin(T a) { this->a = a; }
            // to celsius
            T to_c() { return this->a - 273.15; }
            // to fahrenheit
            T to_f() { return (this->a - 273.15) * 1.8 + 32; }
        };
    }
}


#endif /* temperature_hpp */
