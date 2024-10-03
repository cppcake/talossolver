#include <gtest/gtest.h>
#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"

// Define a test fixture
class BoardTestSuite : public testing::Test {
};

TEST_F(BoardTestSuite, size_test) {
    talossolver::sigil I('I');
    talossolver::sigil O('O');
    talossolver::sigil T('T');
    talossolver::sigil J('J');
    talossolver::sigil L('L');
    talossolver::sigil S('S');
    talossolver::sigil Z('Z');
    std::array<talossolver::sigil, 7> tetrominos = {I, O, T, J, L, S, Z};

    for(const talossolver::sigil& tetromino : tetrominos)
    {
        EXPECT_EQ(tetromino.size(), 4);
    }
}