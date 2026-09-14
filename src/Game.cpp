#include "../include/Game.h"

Game::Game() = default;

void Game::initGame() {
    gameBoard.reset();
    score = 0;
    moveCount = 0;
    historyGameBoards = std::stack<GameBoard>();
    historyScores.clear();
    startTime = std::chrono::steady_clock::now();
    historyGameBoards.push(gameBoard);  // The initial state is the base of the history.
    historyScores.push_back(score);
}

void Game::updateGame(Direction direction) {
    // Safe placeholder use until the TODOs below are completed.
    (void)direction;

    // Perform the move and determine whether the board actually changed.
    // TODO 1

    // For a valid move, update the score and move count.
    // TODO 2

    // Save the resulting board and score. Invalid moves must not be recorded.
    // TODO 3

}

void Game::undoLastMove() {
    if (historyGameBoards.size() > 1) {
        // Remove the current state and restore the previous board.
        // TODO 1

        // Restore the matching score and decrease the valid-move count.
        // TODO 2
    }
    // With only the initial state in history, undo is intentionally a no-op.
}

bool Game::hasWon() const {
    return gameBoard.hasWinningTile();
}

bool Game::hasLost() const {
    return gameBoard.isGameOver();
}

double Game::getElapsedTime() const {
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedSeconds = endTime - startTime;
    return elapsedSeconds.count();
}

int Game::getScore() const {
    return score;
}

int Game::getMoveCount() const {
    return moveCount;
}

const GameBoard& Game::getGameBoard() const {
    return gameBoard;
}
