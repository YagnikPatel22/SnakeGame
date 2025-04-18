# 🐍 Snake Game in C++

A classic **Snake Game** brought to life in **C++**, designed for the **Windows Console**.  
Simple, fast, and fun—**eat food**, **grow the snake**, and **challenge yourself** to beat your high score!

---

## 🎮 Features

- 🐍 Classic Snake gameplay  
- 🎯 Random food spawning  
- ➕ Snake grows on food consumption  
- 🧱 Collision detection (walls & self)  
- ⌨️ Real-time keyboard controls  
- 🧮 Score tracking  
- 🖥️ Console-based UI with simple graphics  

---

## 🕹️ Controls

| Key   | Action      |
|-------|-------------|
| W / w | Move Up     |
| S / s | Move Down   |
| A / a | Move Left   |
| D / d | Move Right  |
| X / x | Exit Game   |

---

## 🚀 How to Play

1. Run the game executable.
2. Use **W**, **A**, **S**, **D** to control the snake.
3. Eat `*` symbols to grow and increase your score.
4. Avoid hitting the walls or the snake’s own body.
5. Press **X** to exit anytime.
6. Game ends on collision—your **final score** will be displayed.

---

## 🛠️ Compilation & Execution

### ▶️ Using `g++` (MinGW on Windows):

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
Uses conio.h for real-time key detection (non-blocking).
Uses Sleep(100) to control game speed (~10 FPS).
📷 Preview

Add a screenshot or a GIF recording here to show gameplay.

📌 Disclaimer

This game is designed specifically for Windows systems due to dependencies on platform-specific libraries.
It may not work on Unix/Linux without significant modifications.

👨‍💻 Author

Yagnik N. Patel
📧 yagnikptl22@gmail.com
🔗 LinkedIn Profile

Let me know if you’d like me to also generate a downloadable file for this or help upload it to GitHub!
