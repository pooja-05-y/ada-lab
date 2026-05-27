#include <stdio.h>
#include <stdlib.h>

int board[20], n;

int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row) {
    if (row > n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (board[i] == j)
                    printf("Q ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(1);

    return 0;
}
