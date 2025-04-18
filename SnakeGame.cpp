#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>  // For _kbhit() and _getch()

using namespace std;

const int width = 30, height = 20;
int Highscore = 0;

class SnakeGame {
private:
    HANDLE console;
    bool gameOver;
    int x, y, foodX, foodY, score;
    vector<pair<int, int>> snake;
    enum Direction { STOP, LEFT, RIGHT, UP, DOWN };
    Direction dir;

    void GotoXY(int x, int y) {
        COORD coord = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(console, coord);
    }

    void HideCursor() {
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(console, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(console, &cursorInfo);
    }

    void Setup() {
        gameOver = false;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        foodX = rand() % width;
        foodY = rand() % height;
        score = 0;
        snake.clear();
        snake.push_back({x, y});
        HideCursor();
    }

    void Draw() {
        GotoXY(0, 0);

        for (int i = 0; i < width + 2; i++) cout << "# ";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0) cout << "# ";

                if (i == y && j == x) cout << "O ";  // Head
                else if (i == foodY && j == foodX) cout << "* ";  // Food
                else {
                    bool print = false;
                    for (auto s : snake) {
                        if (s.first == j && s.second == i) {
                            cout << "o ";
                            print = true;
                            break;
                        }
                    }
                    if (!print) cout << "  ";
                }

                if (j == width - 1) cout << "# ";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++) cout << "# ";
        cout << "\nScore: " << score; // << endl;
        GotoXY(0,height+4);
        cout << "                                    \r";
        GotoXY(0,height+3);
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': case 'A': dir = LEFT; break;
                case 'd': case 'D': dir = RIGHT; break;
                case 'w': case 'W': dir = UP; break;
                case 's': case 'S': dir = DOWN; break;
                case 'x': gameOver = true; break;
            }
        }
    }

    void Logic() {
        int prevX = snake[0].first, prevY = snake[0].second;
        int prev2X, prev2Y;
        snake[0] = {x, y};

        for (size_t i = 1; i < snake.size(); i++) {
            prev2X = snake[i].first;
            prev2Y = snake[i].second;
            snake[i] = {prevX, prevY};
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (dir) {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
            default: break;
        }

        if (x < 0 || x >= width || y < 0 || y >= height) gameOver = true;
        for (size_t i = 1; i < snake.size(); i++) {
            if (snake[i].first == x && snake[i].second == y) gameOver = true;
        }

        if (x == foodX && y == foodY) {
            score += 10;
            snake.push_back({foodX, foodY});

            bool validFoodPosition;
            do {
                validFoodPosition = true;
                foodX = rand() % width;
                foodY = rand() % height;

                for (const auto& segment : snake) {
                    if (segment.first == foodX && segment.second == foodY) {
                        validFoodPosition = false;
                        break;
                    }
                }
            } while (!validFoodPosition);
        }
    }

public:
    SnakeGame() : console(GetStdHandle(STD_OUTPUT_HANDLE)) {}

    void Run() {
        Setup();
        while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(100);
        }
        if (Highscore < score) Highscore = score;   
        cout << "High score: "<< Highscore << "     "<< endl;
        cout << "Game Over! Final Score: " << score << "      " <<endl;
    }
};

int main() {
    while (1) {
        SnakeGame game;
        game.Run();
        Sleep(5000);
    }
    return 0;
}
