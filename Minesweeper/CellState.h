#ifndef CELL_STATE_H
#define CELL_STATE_H

namespace Minesweeper {

	namespace Board {
		/// Represents the possible states of a cell on the game board.
		enum class CellState {
			Hidden, ///< The cell is hidden (not revealed by the player).
			Revealed, ///< The cell is revealed (its content is visible).
			Flagged ///< The cell is flagged (suspected to contain a mine).
		};
	}
}

#endif // CELL_STATE_H