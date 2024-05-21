#include "talossolver/talos_solver.hpp"

namespace talossolver
{
    bool talos_solver::try_place(talossolver::board& board, talossolver::sigil& sigil, coordinate cord, size_t id)
    {
        coordinates to_place = sigil.get_cords(cord[0], cord[1]);
        if(board.is_valid(to_place))
        {
            if(board.is_free(to_place))
            {
                board.take(to_place, id);
                return true;
            }
        }

        return false;
    }

    bool talos_solver::talos_solve(   talossolver::board& board, talossolver::sigils& sigils){return talos_solve(board, sigils, 0);}

    bool talos_solver::talos_solve(   talossolver::board& board, talossolver::sigils& sigils, size_t index)
    {
        // Board already solved, return true
        if(index >= sigils.size())
            return true;

        unsigned int n = board.size()[0];
        unsigned int m = board.size()[1];
        size_t new_index = index + 1;

        for(unsigned int i = 0; i < n; i++)
        {
            for(unsigned int j = 0; j < m; j++)
            {
                for(unsigned int k = 0; k < 4; k++)
                {
                    coordinate to_place = {i, j};
                    if(try_place(board, sigils[index], to_place, new_index))
                    {
                        bool status = talos_solve(board, sigils, new_index);
                        if(status)
                            return true;
                        board.free(sigils[index].get_cords(i, j));
                    }
                    sigils[index].rotate();
                }
            }
        }

        return false;
    }

}
                                