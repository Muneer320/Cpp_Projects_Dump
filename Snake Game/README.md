# Snake King Game

Welcome to **Snake King**, The classic Snake game written in C++! Control your snake, eat fruits, grow longer, and avoid colliding with yourself. The game is simple ~~but challenging~~, ~~with additional features~~ to keep you hooked.

-----------------
## Table of Contents
- [Snake King Game](#snake-king-game)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Controls](#controls)
  - [How to Play](#how-to-play)
  - [Installation and Compilation](#installation-and-compilation)
    - [Requirements](#requirements)
    - [Compilation](#compilation)
    - [Run the Game](#run-the-game)
  - [Preview](#preview)
    - [Game Start Screen:](#game-start-screen)
    - [Gameplay:](#gameplay)
  - [Contributing](#contributing)
---

## Features
- ~~Square~~ playing area for a balanced gaming experience.
- Controls include **WASD** for movement, **ESC** to quit, and special **Q** key to end the game and display the score.
- Snake stops growing when it occupies more than half of the game board.
- Input for the opposite direction is ignored to prevent accidental collisions.
- [Exact Opposite of] Smooth gameplay
- Wrap-around feature when the snake hits the edge.
- Displays final score and waits for **Enter** key to quit after the game ends.

---

## Controls
| Key       | Action                      |
|-----------|-----------------------------|
| `W`       | Move Up                    |
| `A`       | Move Left                  |
| `S`       | Move Down                  |
| `D`       | Move Right                 |
| `ESC`     | Quit the game              |
| `Q`       | Quit and show the score    |

---

## How to Play
1. Run the program to start the game.
2. Use **WASD** keys to move the snake and collect the fruit (`*`) to increase your score.
3. Avoid colliding with your own tail.
4. Press **Q** or let the snake grow larger than half the game board to end the game and display the score.
5. After the game ends, press **Enter** to exit.

---

## Installation and Compilation
### Requirements
- **C++ Compiler** (e.g., g++, MinGW, or MSVC)
- **Windows OS** (for conio.h and Windows-specific features)
  <sub>Not for tech bros from Linux coomunity😞</sub>

### Compilation
Use the following command to compile the code:
```bash
g++ -o snake_game snake_game.cpp
```

### Run the Game
After compilation, run the executable:
```bash
./snake_game
```

---

## Preview
### Game Start Screen:
```
+-------------------------------+
|         :Snake King:          |
+-------------------------------+
Controls: 
	W - Up
	A - Left
	S - Down
	D - Right
	ESC - Quit
	Q - Quit and Show Score
Press any key to start...
```

### Gameplay:
```
==============================
|                            |
|       ooO                 *|
|       o                    |
|       o                    |
|                            |
|                            |
|                            |
|                            |
==============================
Score: 50
```

---
## Contributing
Contributions aren't really necessary for this project — it's more of a learning journey I embarked on while picking up the language. However, if you find it interesting and have some cool ideas or enhancements in mind, feel free to fork the repo and make it your own! You can even fork it and create your own version.