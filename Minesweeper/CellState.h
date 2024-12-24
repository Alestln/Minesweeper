#ifndef CELL_STATE_H
#define CELL_STATE_H

namespace Minesweeper {
	enum class CellState {
		Hidden, ///< ячейка скрыта и не была открыта игроком.
		Revealed, ///< ячейка открыта, еЄ содержимое видно игроку.
		Flagged ///< ячейка помечена флагом, предположительно содержит мину.
	};
}

#endif // CELL_STATE_H