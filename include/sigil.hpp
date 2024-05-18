#pragma once

#include "types.hpp"

namespace talossolver
{
    class sigil
    {
        public:
        // Construct a sigil with given coordinates
        sigil(const coordinates& cos_) : cos(cos_){};

        // Return the coordinates associated with the sigil
        coordinates get_cos(){return cos;}

        // Rotates the sigil by 90° clockwhise
        void rotate();

        private:
        // Represent the sigil as a vector of coordinates
        coordinates cos;
    };
}