#include "talossolver/board.hpp"
#include <iostream>

namespace talossolver
{
    // Check if coordinate is valid, such that the coordinate is within the
    // board. Does not check if the coordinate is free.
    const bool board::is_valid(const coordinate& cord)
    {
        if(cord[0] >= n) return false;
        if(cord[1] >= m) return false;

        return true;
    }

    // Overload to check multiple coordinates at once
    const bool board::is_valid(const coordinates& cords)
    {
        for(const auto& cord : cords)
            if(!is_valid(cord)) return false;

        return true;
    }

    // Check if coordinate cord on the board is free. Does not check if
    // the coordinate is valid
    const bool board::is_free(const coordinate& cord)
    {
        return !board_map[cord[0]][cord[1]];
    }

    // Overload to check multiple coordinates at once
    const bool board::is_free(const coordinates& cords)
    {
        for(const auto& cord : cords)
            if(!is_free(cord)) return false;

        return true;
    }

    // Take coordinate as id. Does not check if already taken or valid.
    void board::take(const coordinate& cord, unsigned int id)
    {
        board_map[cord[0]][cord[1]] = id;
    }

    // Overload to take multiple coordinates at once.
    void board::take(const coordinates& cords, unsigned int id)
    {
        for(const auto& cord : cords)
            take(cord, id);
    }

    // Free a coordinate. Equal to calling take with id=0
    void board::free(const coordinate& cord){take(cord, 0);}

    // Overload to free multiple coordinates at once.
    void board::free(const coordinates& cords){take(cords, 0);}

    // Resets the board such that all tiles are free
    void board::reset()
    {
        for(unsigned int r = 0; r < n; r++)
        {
            for(unsigned int c = 0; c < m; c++)
                board_map[r][c] = 0;
        }
    }

    coordinate board::size(){return {n, m};}

    const void board::print()
    {
        // Iterate over all rows
        for(unsigned int r = 0; r < board_map.size(); r++)
        {
            std::cout << "| ";
            // Iterate over all columns in row
            for(unsigned int c = 0; c < board_map[r].size(); c++)
            {
                unsigned int id = board_map[r][c];

                // First case: Spot is empty
                if(id == 0)
                {
                    std::cout << '-' << " | ";
                    continue;
                }

                // Second case: Spot is within alphabet range
                if(id > 0 && id < 26)
                {
                    std::cout << char('A' + (id - 1)) << " | ";
                    continue;
                }

                // Second case: Spot is out of alphabet range, print number instead
                if(id > 0 && id < 26)
                {
                    std::cout << id - 26 << " | ";
                    continue;
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
