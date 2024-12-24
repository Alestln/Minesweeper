#include "Cell.h"

namespace Minesweeper {

	namespace Board {
		Cell::Cell()
			: state(CellState::Hidden), mine(false), adjacentMines(0) {};

		Cell::Cell(CellState state)
			: state(state), mine(false), adjacentMines(0) {};

		void Cell::setState(CellState state) {
			this->state = state;
		}

		CellState Cell::getState() const {
			return state;
		}

		void Cell::placeMine() {
			mine = true;
		}

		bool Cell::isMine() const {
			return mine;
		}

		void Cell::setAdjacentMines(int count) {
			adjacentMines = count;
		}

		int Cell::getAdjacentMines() const {
			return adjacentMines;
		}

		bool Cell::isFlagged() const
		{
			return state == CellState::Flagged;
		}

		bool Cell::isRevealed() const
		{
			return state == CellState::Revealed;
		}
	}
}