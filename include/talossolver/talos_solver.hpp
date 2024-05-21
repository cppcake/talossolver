#pragma once

#include <cstddef>

#include "types.hpp"
#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"

namespace talossolver
{
    typedef std::vector<talossolver::sigil> sigils;

    class talos_solver
    {
        public:
        // Solves the talos puzzle for a board and a given set of sigils.
        // Check out the flowchart in the docs.
        bool talos_solve(   talossolver::board& board,
                            talossolver::sigils& sigils);

        private:
        // Solves the talos puzzle for a board and a given set of sigils.
        // This Helperfunction is necessary for the recrusive part, see docs.
        bool talos_solve(   talossolver::board& board,
                            talossolver::sigils& sigils,
                            size_t index);

        // Tries to place a sigil on coordinate cord of the board.
        // Returns true if succesful, otherwhise returns false.
        bool try_place(     talossolver::board& board,
                            talossolver::sigil& sigil,
                            coordinate& cord,
                            size_t id);
    };
}