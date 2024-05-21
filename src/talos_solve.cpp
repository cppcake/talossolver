#include "talossolver/talos_solver.hpp"

namespace talossolver
{
    bool talos_solver::try_place(talossolver::board& board, talossolver::sigil& sigil, coordinate& cord, size_t id)
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
        return true;
    }

}
                                