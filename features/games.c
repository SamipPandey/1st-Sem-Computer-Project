#include "../main/header.h"

/* ================== TIC TAC TOE GAME ================== */

/* Function prototypes */
void drawBoard(char board[3][3]);
int checkWin(char board[3][3]);
int game();

int game() {
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };

    int choice, row, col;
    char player = 'X';
    int moves = 0;

    printf("\n===== TIC TAC TOE =====\n");

    while (moves < 9) {
        drawBoard(board);

        printf("Player %c, enter position (1-9): ", player);

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Try again.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 1 || choice > 9) {
            printf("Invalid position! Choose 1-9.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            printf("Position already taken! Try again.\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(board)) {
            clearScreen();
            drawBoard(board);
            printf("!! Player %c Wins!\n", player);
            return 1;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    drawBoard(board);
    printf("Game Draw!\n");

    return 0;
}

void drawBoard(char board[3][3]) {
    int i, j;
    clearScreen();
    printf("\n-------------\n");
    for (i = 0; i < 3; i++) {
        printf("| ");
        for (j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

int checkWin(char board[3][3]) {
    int i;

    /* Check rows and columns */
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
            return 1;

        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
            return 1;
    }

    /* Check diagonals */
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return 1;

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return 1;

    return 0;
}
