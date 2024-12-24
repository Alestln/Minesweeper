#ifndef BOARD_DISPLAY_H
#define BOARD_DISPLAY_H

#include "Board.h"

namespace Minesweeper {

	namespace UI {
		/// Responsible for displaying the board to the user (console-based or UI framework-based).
		class BoardDisplay {
		public:
			/// Constructor that accepts a reference to the board.
			explicit BoardDisplay(const std::vector<std::vector<Board::Cell>>& board);

			/// Displays the current state of the board to the user.
			void displayBoard() const;

		private:
			const std::vector<std::vector<Board::Cell>>& board;
		};
	}
}

#endif // BOARD_DISPLAY_H