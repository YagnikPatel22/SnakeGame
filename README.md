🐍 Snake Game in C++

A classic Snake Game brought to life in C++, designed for the Windows Console. Simple, fast, and fun—eat food, grow the snake, and challenge yourself to beat your high score!

🎮 Features

🐍 Classic Snake gameplay
🎯 Random food spawning
➕ Snake grows on food consumption
🧱 Collision detection (walls & self)
⌨️ Real-time keyboard controls
🧮 Score tracking
🖥️ Console-based UI with simple graphics
🕹️ Controls


Key	Action
W / w	Move Up
S / s	Move Down
A / a	Move Left
D / d	Move Right
X / x	Exit Game
🚀 How to Play

Run the game executable.
Use W, A, S, D to control the snake.
Eat * symbols to grow and increase your score.
Avoid hitting the walls or the snake’s own body.
Press X to exit anytime.
Game ends on collision—your final score will be displayed.
🛠️ Compilation & Execution

▶️ Using g++ (MinGW on Windows):
g++ -o snake_game snake_game.cpp -std=c++11
snake_game.exe
▶️ Using Visual Studio:
Open snake_game.cpp in Visual Studio.
Build and run the project.
💻 Requirements

✅ Windows OS
✅ C++ Compiler (MinGW, MSVC, etc.)
✅ Console-based execution
⚙️ Technical Notes

Uses windows.h for console handling (cursor position, screen clear).
conio.h is used for real-time key detection (non-blocking).
Sleep(100) controls the game speed (~10 FPS).
📷 Preview

(You can add a screenshot or screen recording GIF here for visual appeal.)

📌 Disclaimer

This game is designed specifically for Windows systems due to dependencies on platform-specific libraries. It may not work on Unix/Linux without significant modifications.

👨‍💻 Author

Yagnik N. Patel
📧 yagnikptl22@gmail.com
🔗 LinkedIn
