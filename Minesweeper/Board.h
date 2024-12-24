#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"

namespace Minesweeper {

	namespace Board {
		/// Represents the game board, containing cells and game logic.
		class Board {
		public:
			/// Constructor to initialize the board with specified dimensions and mines count.
			Board(int width, int height, int numMines);

			/// Initializes the board by placing mines and calculating adjacent mines for each cell.
			void initializeBoard();

			/// Opens a cell at the given coordinates (x, y).
			void openCell(int x, int y);

			/// Flags or unflags a cell at the given coordinates (x, y).
			void flagCell(int x, int y);

			/// Checks if the player has won the game by opening all non-mine cells.
			bool checkWinCondition() const;

			/// Gets the width of the board.
			int getWidth() const;

			/// Gets the height of the board.
			int getHeight() const;

			/// Gets the 2D matrix of cells on the board.
			const std::vector<std::vector<Cell>>& getCells() const;

		private:
			int width; ///< Width of the board (number of columns).
			int height; ///< Height of the board (number of rows).
			int numMines; ///< Total number of mines on the board.

			std::vector<std::vector<Cell>> cells; ///< 2D vector representing the board's cells.

			/// Helper function to randomly place mines on the board.
			void placeMines();

			/// Helper function to calculate the number of adjacent mines for each cell.
			void calculateAdjacentMines();
		};
	}
}

#endif // BOARD_H