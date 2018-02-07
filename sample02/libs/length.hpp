//
//  length.hpp
//  sample02
//
//  Created by cep3d on 2018/02/07.
//  Copyright © 2018 cep3d. All rights reserved.
//

#ifndef length_hpp
#define length_hpp

#include "config.h"

namespace conv
{
    namespace length
    {
        const double ONE_KM = 0.62137;  // 1km = 0.62137mi
        template <class T>
        class mile {
            T a;
        public:
            mile(T a) { this->a = a; }
            // to kilometre
            T to_km() { return this->a / ONE_KM; }
            // to metre
            T to_m() { return this->a / (ONE_KM/1000); }
            // to yard
            T to_yd() { return this->a * 1760.0; }
            // to feet
            T to_ft() { return this->a * 5280.0; }
        };
        
        template <class T>
        class kilo {
            T a;
        public:
            kilo(T a) { this->a = a; }
            // to mile
            T to_mile() { return this->a / 1.609344; }
            // to feet
            T to_ft() { return this->a * 3280.8; }
        };
        
        template <class T>
        class feet {
            T a;
        public:
            feet(T a) { this->a = a; }
            T to_mile() { return this->a * 0.00018939; }
            T to_kilo() { return this->a / 3280.8; }
        };
    }
}

#endif /* length_hpp */
