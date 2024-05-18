#include "talossolver/sigil.hpp"

namespace talossolver
{
    // Construct a sigil from a template teromino
    sigil::sigil(char sigil_id)
    {
        switch(sigil_id)
        {
            case 'I':
                cords = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
                break;
            case 'O':
                cords = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
                break;
            case 'T':
                cords = {{0, 0}, {0, 1}, {0, 2}, {1, 1}};
                break;
            case 'J':
                cords = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
                break;
            case 'L':
                cords = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
                break;
            case 'S':
                cords = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
                break;
            case 'Z':
                cords = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
                break;
        }
    }

    // Overload to return the coordinates but displaced by (x, y)
    const coordinates sigil::get_cords(unsigned int x, unsigned int y)
    {
        coordinates displaced_cords = cords;
        for(auto& cord : displaced_cords)
        {
            cord[0] = cord[0] + x;
            cord[1] = cord[1] + y;
        }
        return displaced_cords;
    }

    // Rotates the sigil by 90° clockwhise
    void sigil::rotate()
    {
        for(auto& cord : cords)
            cord = {cord[1], -cord[0]};
    }
}