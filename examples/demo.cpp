#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"
#include "talossolver/talos_solver.hpp"

int main()
{
    talossolver::board board(10, 10);

    talossolver::sigil I('I');
    talossolver::sigil O('O');
    talossolver::sigil T('T');
    talossolver::sigil J('J');
    talossolver::sigil L('L');
    talossolver::sigil S('S');
    talossolver::sigil Z('Z');

    return 0;
}