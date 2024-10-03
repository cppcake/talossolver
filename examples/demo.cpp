#include "talossolver/board.hpp"
#include "talossolver/sigil.hpp"
#include "talossolver/talos_solver.hpp"

#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    // Create board
    unsigned int n;
    unsigned int m;
    std::cout << "Enter board length" << std::endl;
    std::cin >> n;
    std::cout << "Enter board width" << std::endl;
    std::cin >> m;
    talossolver::board board(n, m);

    // Explain how to add sigils
    std::cout << "You can choose between the following Tetrominos:" << std::endl;
    std::cout << " - I" << std::endl << " - O" << std::endl << " - T" << std::endl;
    std::cout << " - J" << std::endl << " - L" << std::endl << " - S" << std::endl;
    std::cout << " - Z" << std::endl;
    std::cout << "Enter Sigils as a comma seperated list of Tetrominos like this: ";
    std::cout << "\"O,O,T,J,L,S,Z\"" << std::endl;
    std::cout << "List may not contain any spaces!" << std::endl;
    
    // Create Sigils
    std::string tetrominos_input;
    std::cin >> tetrominos_input;
    std::vector<talossolver::sigil> tetrominos = {};
    std::vector<char> tet_chars = {'I', 'O', 'T', 'J', 'L', 'S', 'Z'};
    for(const char tet_char : tetrominos_input)
    {
        if(std::find(tet_chars.begin(), tet_chars.end(), tet_char) != tet_chars.end())
        {
            talossolver::sigil tetromino(tet_char);
            tetrominos.push_back(tetromino);
        }
    }

    // Solve given instance
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