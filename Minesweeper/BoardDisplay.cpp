#include "BoardDisplay.h"
#include <iostream>

namespace Minesweeper {

	namespace UI {
		BoardDisplay::BoardDisplay(const std::vector<std::vector<Board::Cell>>& board)
			: board(board) {}

		void BoardDisplay::displayBoard() const {
			// Get the number of rows and columns of the board
			size_t rows = board.size();
			size_t cols = board[0].size();

			// Print the top border of the board
			std::cout << "   ";
			for (size_t j = 0; j < cols; j++) {
				std::cout << "+---";  // Horizontal line for each cell
			}
			std::cout << "+" << std::endl;

			// Loop through each row of the board
			for (size_t i = 0; i < rows; i++) {
				std::cout << "   ";  // Print space before the vertical boundary of the row
				for (size_t j = 0; j < cols; j++) {
					std::cout << "| ";  // Print the left boundary of each cell
					const auto& cell = board[i][j];  // Get the current cell

					// Check if the cell is flagged and print 'F'
					if (cell.isFlagged()) {
						std::cout << "F ";
					}
					// Check if the cell is a mine and print '*'
					else if (cell.isMine()) {
						std::cout << "* ";
					}
					// Check if the cell is revealed
					else if (cell.isRevealed()) {
						// If the cell is revealed, print the number of neighboring mines or a space if there are none
						int adjacentMines = cell.getAdjacentMines();  // Get the number of adjacent mines
						if (adjacentMines == 0) {
							std::cout << "  ";  // Empty space if no mines around
						}
						else {
							std::cout << adjacentMines << " ";  // Print the number of adjacent mines
						}
					}
					// If the cell is not revealed and not flagged, print '#'
					else {
						std::cout << "# ";
					}
				}

				std::cout << "|" << std::endl;  // Print the right boundary of the row

				// Print the bottom border of the board row
				std::cout << "   ";
				for (size_t j = 0; j < cols; j++) {
					std::cout << "+---";  // Horizontal line for each cell
				}
				std::cout << "+" << std::endl;
			}
		}
	}
}
