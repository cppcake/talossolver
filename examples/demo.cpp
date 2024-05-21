#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"
#include "talossolver/talos_solver.hpp"

#include <iostream>

int main()
{
    talossolver::board board(7, 8);

    talossolver::sigil I('I');
    talossolver::sigil O('O');
    talossolver::sigil T('T');
    talossolver::sigil J('J');
    talossolver::sigil L('L');
    talossolver::sigil S('S');
    talossolver::sigil Z('Z');

    std::vector<talossolver::sigil> tetrominos = {O, O, O, O, I, I, T, T, T, T, S, Z, L, J};

    talossolver::talos_solver solver;
    if(solver.talos_solve(board, tetrominos) == true)
    {
        std::cout << "The puzzle can be solved! Here is the solution:" << std::endl;
        board.print();
    }
    else
    {
        std::cout << "The puzzle can't be solved! :(" << std::endl;
    }
    return 0;
}