#include <gtest/gtest.h>
#include "talossolver/board.hpp"

// Define a test fixture
class BoardTestSuite : public testing::Test {
};

TEST_F(BoardTestSuite, is_valid_test) {
    talossolver::board board(6, 4);

    // Test all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            EXPECT_TRUE(board.is_valid({r, c}));
    }

    // Test many coordinates around the board
    for(unsigned int r = 6; r < 10; r++)
    {
        for(unsigned int c = 0; c < 10; c++)
            EXPECT_FALSE(board.is_valid({r, c}));
    }
    for(unsigned int r = 0; r < 10; r++)
    {
        for(unsigned int c = 4; c < 10; c++)
            EXPECT_FALSE(board.is_valid({r, c}));
    }
    for(unsigned int r = 6; r < 10; r++)
    {
        for(unsigned int c = 4; c < 10; c++)
            EXPECT_FALSE(board.is_valid({r, c}));
    }

    // Test the overload
    coordinates cords_within = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}};
    coordinates cords_outside = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}};

    EXPECT_TRUE(board.is_valid(cords_within));
    EXPECT_FALSE(board.is_valid(cords_outside));
}

TEST_F(BoardTestSuite, is_free_test) {
    talossolver::board board(6, 4);

    // Test all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            EXPECT_TRUE(board.is_free({r, c}));
    }

    // Test the overload
    coordinates cords_within = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}};
    EXPECT_TRUE(board.is_free(cords_within));

    board.take({0, 2}, 1);
    EXPECT_FALSE(board.is_free(cords_within));

    // Test all coordinates within the board after reset
    board.reset();
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            EXPECT_TRUE(board.is_free({r, c}));
    }
}

TEST_F(BoardTestSuite, take_test) {
    talossolver::board board(6, 4);

    // Take all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            board.take({r, c}, r+1);
    }

    // Test all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            EXPECT_FALSE(board.is_free({r, c}));
    }

    // Test the overload
    coordinates cords_within = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}};

    board.take(cords_within, 1);
    EXPECT_FALSE(board.is_free(cords_within));
}

TEST_F(BoardTestSuite, free_test) {
    talossolver::board board(6, 4);

    // Take all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            board.take({r, c}, r+1);
    }

    // Free all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            board.free({r, c});
    }

    // Test all coordinates within the board
    for(unsigned int r = 0; r < 6; r++)
    {
        for(unsigned int c = 0; c < 4; c++)
            EXPECT_TRUE(board.is_free({r, c}));
    }

    // Test the overload
    coordinates cords_within = {{0,0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}};

    board.take(cords_within, 1);
    EXPECT_FALSE(board.is_free(cords_within));
    board.free(cords_within);
    EXPECT_TRUE(board.is_free(cords_within));
}