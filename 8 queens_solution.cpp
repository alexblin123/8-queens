#include <iostream>

using namespace std;

const int N = 8; // размер шахматной доски
int board[N][N]; // шахматная доска

// функция для вывода шахматной доски

static void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// функция для проверки, можно ли поставить ферзя на данное место
static bool isSafe(int row, int col) {
    // проверяем вертикаль и горизонталь
    for (int i = 0; i < N; i++) {
        if (board[i][col] == 1 || board[row][i] == 1) {
            return false;
        }
    }

    // проверяем диагонали
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j < N; i++, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// рекурсивная функция для размещения ферзей на доске
static bool solveNQueens(int row, int& solutionCount) {
    if (row == N) {
        cout << "Решение " << solutionCount << ":" << endl;
        printBoard();
        solutionCount++;
        return false; // продолжаем поиск других решений
    }

    // постепенно размещаем ферзей на текущей строке
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            // рекурсивно размещаем следующего ферзя на следующей строке
            if (solveNQueens(row + 1, solutionCount)) {
                return true; // найдено решение задачи
            }

            board[row][col] = 0; // отменяем размещение ферзя
        }
    }

    return false; // не найдено решение задачи для данной строки
}

int main() {

    setlocale(LC_ALL, "RU");

    int solutionCount = 1;
    solveNQueens(0, solutionCount);

    return 0;
}