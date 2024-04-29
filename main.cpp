#include <iostream>
#include <vector>
#include <climits>

const int BOARD_SIZE = 8;

// Función para imprimir el tablero
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Función para verificar si se puede colocar una reina en una casilla
bool canPlaceQueen(const std::vector<std::vector<int>>& board, int row, int col) {
    // Verificar la fila y la columna
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == 1 || board[i][col] == 1) {
            return false;
        }
    }
    // Verificar diagonales
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i < BOARD_SIZE && j >= 0; ++i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

// Función para colocar una reina utilizando la heurística
bool placeQueen(std::vector<std::vector<int>>& board, int row) {
    if (row == BOARD_SIZE) {
        return true;
    }
    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (canPlaceQueen(board, row, col)) {
            board[row][col] = 1;
            if (placeQueen(board, row + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
};

int main() {
    std::vector<std::vector<int>> board(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));

    // Asignar valores de eliminación a cada casilla
    int eliminationValues[BOARD_SIZE][BOARD_SIZE] = {
        { 22, 20, 18, 16, 16, 18, 20, 22 },
        { 20, 18, 16, 14, 14, 16, 18, 20 },
        { 18, 16, 14, 12, 12, 14, 16, 18 },
        { 16, 14, 12, 10, 10, 12, 14, 16 },
        { 16, 14, 12, 10, 10, 12, 14, 16 },
        { 18, 16, 14, 12, 12, 14, 16, 18 },
        { 20, 18, 16, 14, 14, 16, 18, 20 },
        { 22, 20, 18, 16, 16, 18, 20, 22 }
    };

    // Colocar las reinas utilizando la heurística
    if (placeQueen(board, 0)) {
        std::cout << "Solución encontrada:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "No se encontró solución." << std::endl;
    }

    return 0;
}
