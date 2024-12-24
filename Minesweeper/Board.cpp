#include "Board.h"
#include <random>

namespace Minesweeper {
	
	namespace Board {
		Board::Board(int width, int height, int numMines)
			: width(width), height(height), numMines(numMines), cells(height, std::vector<Cell>(width)) {}

		void Board::initializeBoard() {
			placeMines();
			calculateAdjacentMines();

			cells[3][3].setState(CellState::Flagged);
			cells[2][2].setState(CellState::Revealed);
		}

		void Board::placeMines() {
			// Randomly place mines on the board.
			std::mt19937 rng(static_cast<unsigned int>(time(0)));
			std::uniform_int_distribution<int> distX(0, width - 1);
			std::uniform_int_distribution<int> distY(0, height - 1);

			int placeMines = 0;
			while (placeMines < numMines) {
				int x = distX(rng);
				int y = distY(rng);

				if (!cells[y][x].isMine()) {
					cells[y][x].placeMine();
					placeMines++;
				}
			}
		}

		void Board::calculateAdjacentMines() {
			// For each cell, calculate the number of adjacent mines.
			for (int y = 0; y < height; ++y) {
				for (int x = 0; x < width; ++x) {
					if (!cells[y][x].isMine()) {
						int adjacentMines = 0;
						for (int dy = -1; dy <= 1; ++dy) {
							for (int dx = -1; dx <= 1; ++dx) {
								int nx = x + dx, ny = y + dy;
								if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
									if (cells[ny][nx].isMine()) {
										adjacentMines++;
									}
								}
							}
						}

						cells[y][x].setAdjacentMines(adjacentMines);
					}
				}
			}
		}

		bool Board::checkWinCondition() const {
			// The player wins if all non-mine cells are revealed.
			for (size_t y = 0; y < height; ++y) {
				for (size_t x = 0; x < width; ++x) {
					if (!cells[y][x].isMine() && cells[y][x].getState() != CellState::Revealed) {
						return false; // Not all non-mine cells are revealed.
					}
				}
			}

			return true; // All non-mine cells are revealed.
		}

		void Board::flagCell(int x, int y) {
			if (cells[y][x].getState() == CellState::Hidden) {
				cells[y][x].setState(CellState::Flagged);
			}
		}

		void Board::openCell(int x, int y) {
			if (cells[y][x].getState() == CellState::Hidden) {
				cells[y][x].setState(CellState::Revealed);

				if (cells[y][x].isMine()) {
					// Game over if the cell is a mine.
					// This logic could trigger a game-over state in your game engine.
				}
			}
		}

		int Board::getWidth() const {
			return width;
		}

		int Board::getHeight() const {
			return height;
		}

		const std::vector<std::vector<Cell>>& Board::getCells() const {
			return cells;
		}
	}
}