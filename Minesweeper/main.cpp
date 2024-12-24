#include "Board.h"
#include "BoardDisplay.h"

int main()
{
    Minesweeper::Board::Board board(5, 5, 3);

    board.initializeBoard();

    Minesweeper::UI::BoardDisplay display(board.getCells());

    display.displayBoard();

    return 0;
}
