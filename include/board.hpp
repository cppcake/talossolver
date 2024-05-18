#pragma once

#include "types.hpp"

namespace talossolver
{
    class board
    {
        public:
        // Check if coordinate is valid, such that the coordinate is within the
        // board. Does not check if the coordinate is free.
        bool is_valid(const coordinate& cord);

        // Overload to check multiple coordinates at once
        bool is_valid(const coordinates& cords);

        // Check if coordinate cord on the board is free. Does not check if
        // the coordinate is valid
        bool is_free(const coordinate& cord);

        // Overload to check multiple coordinates at once
        bool is_free(const coordinates& cords);

        // Take coordinate as id. Does not check if already taken or valid.
        void take(const coordinate& cord, const unsigned int& id);

        // Overload to take multiple coordinates at once.
        void take(const coordinates& cords, const unsigned int& id);

        // Resets the board such that all tiles are free
        void reset();

        void print();

        private:
        // The board is represented as an n x m Matrix, the board_map.
        // 0 on this matrix means, that the given coordinate is free
        // Any other numbers represents the sigil taken up that coordinate
        std::vector<std::vector<unsigned int>> board_map;
    };
}