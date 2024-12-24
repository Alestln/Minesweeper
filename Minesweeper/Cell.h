#ifndef CELL_H
#define CELL_H

#include "CellState.h"

namespace Minesweeper {

	namespace Board {
		/// Represents a single cell on the Minesweeper board.
		class Cell {
		public:
			/// Default constructor.
			Cell();

			/// Constructor with a specific state.
			explicit Cell(CellState state);

			/// Sets the state of the cell.
			void setState(CellState state);

			/// Gets the current state of the cell.
			CellState getState() const;

			/// Marks the cell as containing a mine.
			void placeMine();

			/// Checks if the cell contains a mine.
			bool isMine() const;

			/// Sets the number of adjacent mines.
			void setAdjacentMines(int count);

			/// Gets the number of adjacent mines.
			int getAdjacentMines() const;

			/// Checks if the cell state is Flagged
			bool isFlagged() const;

			/// Checks if the cell state is Revealed
			bool isRevealed() const;

		private:
			CellState state; ///< The current state of the cell (e.g., Hidden, Revealed, Flagged).
			bool mine; ///< Indicates whether the cell contains a mine.
			int adjacentMines; ///< Number of adjacent mines.
		};
	}
}

#endif // CELL_H
