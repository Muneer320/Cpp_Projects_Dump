#include <iostream>
#include <conio.h>
#include <windows.h>

const int width = 40, height = 20;
int ballX, ballY, player1Y, player2Y, ballDirX = 1, ballDirY = 1, score1 = 0, score2 = 0;
bool gameRunning = true;
const int winningScore = 5;

void Draw() {
    system("cls");
    for (int i = 0; i <= height; ++i) {
        for (int j = 0; j <= width; ++j) {
            if (i == 0 || i == height) std::cout << "#"; // Walls
            else if (j == 0 || j == width) std::cout << "|"; // Borders
            else if (j == 1 && i >= player1Y && i < player1Y + 4) std::cout << "|"; // Player 1 paddle
            else if (j == width - 1 && i >= player2Y && i < player2Y + 4) std::cout << "|"; // Player 2 paddle
            else if (j == ballX && i == ballY) std::cout << "O"; // Ball
            else std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "Player 1: " << score1 << "  Player 2: " << score2 << "\n";
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'w': if (player1Y > 1) player1Y--; break;
        case 's': if (player1Y < height - 4) player1Y++; break;
        case 'i': if (player2Y > 1) player2Y--; break;
        case 'k': if (player2Y < height - 4) player2Y++; break;
        case 'q': gameRunning = false; break;
        }
    }
}

void Logic() {
    ballX += ballDirX;
    ballY += ballDirY;

    // Ball collision with top and bottom walls
    if (ballY == 1 || ballY == height - 1) ballDirY *= -1;

    // Ball collision with paddles
    if ((ballX == 2 && ballY >= player1Y && ballY < player1Y + 4) ||
        (ballX == width - 2 && ballY >= player2Y && ballY < player2Y + 4))
        ballDirX *= -1;

    // Ball out of bounds
    if (ballX <= 0) { score2++; ballX = width / 2; ballY = height / 2; ballDirX = 1; ballDirY = (std::rand() % 2 == 0) ? 1 : -1; }
    if (ballX >= width) { score1++; ballX = width / 2; ballY = height / 2; ballDirX = -1; ballDirY = (std::rand() % 2 == 0) ? 1 : -1; }

    // Check winning condition
    if (score1 == winningScore || score2 == winningScore) {
        gameRunning = false;
    }
}

void DisplayControls() {
    std::cout << "Welcome to Pong!\n";
    std::cout << "Player 1 Controls: W (up), S (down)\n";
    std::cout << "Player 2 Controls: I (up), K (down)\n";
    std::cout << "Press Q anytime to quit.\n";
    std::cout << "First to " << winningScore << " wins!\n\n";
    std::cout << "Press any key to start...\n";
    _getch();
}

int main() {
    ballX = width / 2; ballY = height / 2;
    player1Y = player2Y = height / 2 - 2;

    DisplayControls();

    while (gameRunning) {
        Draw();
        Input();
        Logic();
        Sleep(80); // Adjust speed (slowed down vertical movement)
    }

    std::cout << "\nGame Over! ";
    if (score1 == winningScore) std::cout << "Player 1 Wins!\n";
    else std::cout << "Player 2 Wins!\n";
    
    system("pause");

    return 0;
}
