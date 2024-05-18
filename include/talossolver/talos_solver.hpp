#pragma once

#include "types.hpp"
#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"

namespace talossolver
{
    typedef std::vector<talossolver::sigil> sigils;

    class talos_solver
    {
        public:
        // Solves the talos puzzle for a board and a given set of sigils
        bool talos_solve(   talossolver::board board,
                            talossolver::sigils sigils);
    };
}