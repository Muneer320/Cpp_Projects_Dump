#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Enum for directions
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
Direction dir;

// Game variables
bool gameOver;
const int height = 20;
const int width = 30;
int headX, headY, fruitX, fruitY, score;
int tailx[100], taily[100];
int tail_len;

// Function declarations
void setup();
void draw();
void input();
void logic();


int main() {
    // Welcome screen and controls
    cout << "\t+-----------------------------+" << endl;
    cout << "\t|        :Snake King:         |" << endl;
    cout << "\t+-----------------------------+" << endl;
    cout << "Controls: \n\tW - Up\n\tA - Left\n\tS - Down\n\tD - Right\n\tESC - Quit\n\tQ - Quit and Show Score" << endl;
    cout << "\n\tPress any key to start...";
    getch();

    setup();
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(30);
        system("cls");
    }

    // Game Over Screen
    draw();
    cout << "\n\tGame Over! Your Score: " << score << endl;
    cout << "\n\tPress Enter to exit...";
    while (true) {
        if (getch() == 13) break; // Wait for Enter key
    }
    return 0;
}

void setup() {
    gameOver = false;
    dir = STOP;
    headX = width / 2;
    headY = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    tail_len = 0;
}

void draw() {
    // Upper border
    cout << "\t\t";
    for (int i = 0; i < width+2; i++) {
        cout << "=";
    }
    cout << endl;

     // Game area
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "\t\t|"; // Left border
            }

            if (i == headY && j == headX) {
                cout << "O"; // Snake head
            } else if (i == fruitY && j == fruitX) {
                cout << "*"; // Fruit
            } else {
                bool print = false;
                for (int k = 0; k < tail_len; k++) {
                    if (tailx[k] == j && taily[k] == i) {
                        cout << "o"; // Snake tail
                        print = true;
                        break;
                    }
                }
                if (!print) {
                    cout << " "; // Empty space
                }
            }

            if (j == width - 1) {
                cout << "|"; // Right border
            }
        }
        cout << endl;
    }


    // Lower border
    cout << "\t\t";
    for (int i = 0; i < width+2; i++) {
        cout << "=";
    }
    cout << endl;

    // Score
    cout << "\t\tScore: " << score << endl;
}

void input() {
    if (_kbhit()) {
        char key = getch();
        switch (key) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'q': gameOver = true; break;
            case 27: gameOver = true; break; // ESC to quit
            default: break;
        }
    }
}

void logic() {
    // Update tail positions
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x, prev2y;
    tailx[0] = headX;
    taily[0] = headY;

    for (int i = 1; i < tail_len; i++) {
        prev2x = tailx[i];
        prev2y = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }

    // Update head position based on direction
    switch (dir) {
        case LEFT:  headX--; break;
        case RIGHT: headX++; break;
        case UP:    headY--; break;
        case DOWN:  headY++; break;
        default:    break;
    }

    // Handle wall collision (wrap-around)
    if (headX >= width)  headX = 0;
    else if (headX < 0)  headX = width - 1;

    if (headY >= height) headY = 0;
    else if (headY < 0)  headY = height - 1;

    // Check if snake bites itself
    for (int i = 0; i < tail_len; i++) {
        if (tailx[i] == headX && taily[i] == headY) {
            gameOver = true;
        }
    }

    // Check if snake eats fruit
    if (headX == fruitX && headY == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        tail_len++;

        // End game if snake grows too large
        if (tail_len > (width * height) / 2) {
            gameOver = true;
        }
    }
}
