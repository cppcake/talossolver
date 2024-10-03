#pragma once

#include "types.hpp"

namespace talossolver
{
    class sigil
    {
        public:
        // Construct a sigil from a template teromino
        sigil(char sigil_id);

        // Return the coordinates associated with the sigil
        const coordinates get_cords(){return cords;}

        // Overload to return the coordinates but displaced by (x, y)
        const coordinates get_cords(unsigned int x, unsigned int y);

        // Rotates the sigil by 90° clockwhise
        void rotate();

        const unsigned int size() const;

        private:
        // Represent the sigil as a vector of coordinates
        coordinates cords;
        // Size of sigil e.g. how much space it takes up on the board
        const unsigned int size_;
    };
}