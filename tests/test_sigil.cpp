#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"

// I know that this is a not prober a test, but it does the job alright.
// If somebody did this in POOSE though, i would make sure they fix it :P
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
    std::array<talossolver::sigil, 7> tetrominos = {I, O, T, J, L, S, Z};

    for(auto& tetromino : tetrominos)
    {
        tetromino.rotate();
        board.take(tetromino.get_cords(4, 4), 1);
        board.print();
        board.reset();
    }

    for(auto& tetromino : tetrominos)
    {
        tetromino.rotate();
        board.take(tetromino.get_cords(4, 4), 1);
        board.print();
        board.reset();
    }

    for(auto& tetromino : tetrominos)
    {
        tetromino.rotate();
        board.take(tetromino.get_cords(4, 4), 1);
        board.print();
        board.reset();
    }

    for(auto& tetromino : tetrominos)
    {
        tetromino.rotate();
        board.take(tetromino.get_cords(4, 4), 1);
        board.print();
        board.reset();
    }

    talossolver::sigil X({  {0, 0}, {1, 0}, {2, 0}, {3, 0}, {2, 1}, {4, 1}, 
                            {2, 2}, {3, 3} });
    board.take(X.get_cords(4, 4), 1);
    board.print();
    board.reset();

    X.rotate();
    board.take(X.get_cords(4, 4), 1);
    board.print();
    board.reset();

    return 0;
}