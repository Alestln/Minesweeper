#ifndef CELL_STATE_H
#define CELL_STATE_H

namespace Minesweeper {
	enum class CellState {
		Hidden, ///< ������ ������ � �� ���� ������� �������.
		Revealed, ///< ������ �������, � ���������� ����� ������.
		Flagged ///< ������ �������� ������, ���������������� �������� ����.
	};
}

#endif // CELL_STATE_H