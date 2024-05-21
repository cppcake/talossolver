#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"
#include "talossolver/talos_solver.hpp"

#include <iostream>

int main()
{
    talossolver::board board(6, 4);

    talossolver::sigil I('I');
    talossolver::sigil O('O');
    talossolver::sigil T('T');
    talossolver::sigil J('J');
    talossolver::sigil L('L');
    talossolver::sigil S('S');
    talossolver::sigil Z('Z');

    std::vector<talossolver::sigil> tetrominos = {I, O, T, T, L, Z};

    talossolver::talos_solver solver;
    if(solver.talos_solve(board, tetrominos) == true)
    {
        std::cout << "True!" << std::endl;
    }
    else
    {
        std::cout << "False!" << std::endl;
    }

    board.print();

    return 0;
}