#include<iostream> // for cout and cin
#include<conio.h>  // console input output check krta hy 
#include <windows.h> // delay or screen colour wagaira kai liye 
#include<string> // Naaam kai liye
#include <cstring> // char arrays kai liye use hotien
#include<ctime>  // time or date kai liye 

using namespace std;

bool gameOver;
int gameSpeed;
const int length = 20;
const int width = 20;
int road[length][width];

int livesofPlayer1 = 3;
int livesofPLayer2 = 3;
int winner = 0;
int score = 0;

int difficulty = 1;
int oilSpanTime1 = 0;
int oilSpanTime2 = 0;

struct Players
{
    int x;
    int y;
    char symbol;
};

Players PLayer1, Player2;

void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void GotoXY(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Setup()
{
    gameOver = false;
    winner = 0;
    score = 0;
    oilSpanTime1 = 0;
    oilSpanTime2 = 0;

    if (difficulty == 1)
    {
        gameSpeed = 120;
        livesofPlayer1 = 3;
        livesofPLayer2 = 3;
    }
    else if (difficulty == 2)
    {
        gameSpeed = 100;
        livesofPlayer1 = 3;
        livesofPLayer2 = 3;
    }
    else if (difficulty == 3)
    {
        gameSpeed = 60;
        livesofPlayer1 = 1;
        livesofPLayer2 = 1;
    }

    PLayer1.x = 5;
    PLayer1.y = length - 2;
    PLayer1.symbol = 'A';

    Player2.x = width - 6;
    Player2.y = length - 2;
    Player2.symbol = 'B';

    srand(time(0));

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            road[i][j] = 0;
        }
    }
}

void StartCountdown()
{
    system("cls");
    string pads = "\n\n\n\n\n\n\n                                              ";

    SetColor(12);
    cout << pads << "3" << endl;
    Beep(523, 400);
    Sleep(400);

    system("cls");
    SetColor(14);
    cout << pads << "2" << endl;
    Beep(587, 400);
    Sleep(400);

    system("cls");
    SetColor(10);
    cout << pads << "1" << endl;
    Beep(659, 400);
    Sleep(400);

    system("cls");
    SetColor(11);
    cout << pads << "GOOOOO!" << endl;
    Beep(784, 600);
    Sleep(400);
}

void Draw()
{
    GotoXY(0, 0);
    string pad = "                                    ";

    cout << "\n\n";

    SetColor(11);
    cout << pad << " P1: ";

    for (int i = 0; i < livesofPlayer1; i++)
    {
        cout << "\x03 ";
    }
    for (int i = livesofPlayer1; i < 3; i++)
    {
        cout << ". ";
    }

    SetColor(7);
    cout << "|";

    SetColor(14);
    cout << " P2: ";

    for (int k = 0; k < livesofPLayer2; k++)
    {
        cout << "\x03 ";
    }
    for (int k = livesofPLayer2; k < 3; k++)
    {
        cout << ". ";
    }

    SetColor(7);
    cout << "|";

    SetColor(13);
    cout << " [P] Pause\n";

    SetColor(7);
    cout << pad;

    for (int i = 0; i < width; i++)
    {
        cout << "_";
    }
    cout << endl;

    for (int i = 0; i < length; i++)
    {
        cout << pad;

        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                SetColor(7);
                cout << "|";
            }
            else if (i == PLayer1.y && j == PLayer1.x)
            {
                if (oilSpanTime1 > 0 && rand() % 2 == 0)
                {
                    SetColor(13);
                }
                else
                {
                    SetColor(11);
                }
                cout << PLayer1.symbol;
            }
            else if (i == Player2.y && j == Player2.x)
            {
                if (oilSpanTime2 > 0 && rand() % 2 == 0)
                {
                    SetColor(13);
                }
                else
                {
                    SetColor(14);
                }
                cout << Player2.symbol;
            }
            else if (road[i][j] == 1)
            {
                SetColor(12);
                cout << "#";
            }
            else if (road[i][j] == 3)
            {
                SetColor(8);
                cout << "~";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    SetColor(7);
    cout << pad << "|";

    for (int i = 0; i < width - 2; i++)
    {
        cout << "_";
    }
    cout << "|\n";

    cout << pad << " Distance: " << score << "m\n";
}

void Input()
{
    if (_kbhit())
    {
        char k = _getch();

        bool rev1 = (oilSpanTime1 > 0);

        if (((k == 'a' || k == 'A') && !rev1) || ((k == 'd' || k == 'D') && rev1))
        {
            if (PLayer1.x > 1)
            {
                PLayer1.x--;
            }
        }
        else if (((k == 'd' || k == 'D') && !rev1) || ((k == 'a' || k == 'A') && rev1))
        {
            if (PLayer1.x < width - 2)
            {
                PLayer1.x++;
            }
        }

        bool rev2 = (oilSpanTime2 > 0);

        if (((k == 'j' || k == 'J') && !rev2) || ((k == 'l' || k == 'L') && rev2))
        {
            if (Player2.x > 1)
            {
                Player2.x--;
            }
        }
        else if (((k == 'l' || k == 'L') && !rev2) || ((k == 'j' || k == 'J') && rev2))
        {
            if (Player2.x < width - 2)
            {
                Player2.x++;
            }
        }

        if (k == 'p' || k == 'P')
        {
            _getch();
        }
    }
}

void Logic()
{
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = 0; j < width; j++)
        {
            road[i][j] = road[i - 1][j];
        }
    }

    for (int j = 0; j < width; j++)
    {
        road[0][j] = 0;
    }

    int r = rand() % 100;
    int spawnRate;

    if (difficulty == 1)
    {
        spawnRate = 15;
    }
    else if (difficulty == 2)
    {
        spawnRate = 40;
    }
    else
    {
        spawnRate = 60;
    }

    if (r < spawnRate)
    {
        int type = (rand() % 100 < 30) ? 3 : 1;
        road[0][(rand() % (width - 2)) + 1] = type;
    }

    if (road[PLayer1.y][PLayer1.x] == 1)
    {
        livesofPlayer1--;
        road[PLayer1.y][PLayer1.x] = 0;
        Beep(500, 100);

        if (livesofPlayer1 == 0)
        {
            gameOver = true;
            winner = 2;
        }
    }
    else if (road[PLayer1.y][PLayer1.x] == 3)
    {
        oilSpanTime1 = 30;
        road[PLayer1.y][PLayer1.x] = 0;
        Beep(300, 200);
    }

    if (road[Player2.y][Player2.x] == 1)
    {
        livesofPLayer2--;
        road[Player2.y][Player2.x] = 0;
        Beep(500, 100);

        if (livesofPLayer2 == 0)
        {
            gameOver = true;
            winner = 1;
        }
    }
    else if (road[Player2.y][Player2.x] == 3)
    {
        oilSpanTime2 = 30;
        road[Player2.y][Player2.x] = 0;
        Beep(300, 200);
    }

    if (oilSpanTime1 > 0)
    {
        oilSpanTime1--;
    }
    if (oilSpanTime2 > 0)
    {
        oilSpanTime2--;
    }

    score++;

    if (score % 100 == 0 && gameSpeed > 30)
    {
        gameSpeed -= 5;
    }
}

int main()
{
    system("mode con: cols=100 lines=35");

    while (true)
    {
        SetColor(7);
        system("cls");

        SetColor(3);
        cout << "\n\n";
        cout << R"(
               _____          _____        _____              _____  _____  _   _  _____
              / ____|   /\   |  __ \      |  __ \     /\     / ____||_   _|| \ | |/ ____|
             | |       /  \  | |__) |     | |__) |   /  \   | |       | |  |  \| | |  __
             | |      / /\ \ |  _  /      |  _  /   / /\ \  | |       | |  | . ` | | |_ |
             | |____ / ____ \| | \ \      | | \ \  / ____ \ | |____  _| |_ | |\  | |__| |
              \_____/_/    \_\_|  \_\     |_|  \_\/_/    \_\ \_____||_____||_| \_|\_____|
        )" << endl;

        SetColor(8);
        cout << "                                 Created By: Muhammad Faizan Naeem \n" << endl;

        string pad = "                                ";

        SetColor(7);
        cout << pad << " __________________________________ " << endl;
        cout << pad << "|                                  |" << endl;
        cout << pad << "|           "; SetColor(11); cout << "1. START GAME"; SetColor(7); cout << "          |" << endl;
        cout << pad << "|           "; SetColor(12); cout << "2. EXIT      "; SetColor(7); cout << "          |" << endl;
        cout << pad << "|                                  |" << endl;
        cout << pad << "|           "; SetColor(15); cout << "Enter Choice:"; SetColor(7); cout << "          |" << endl;
        cout << pad << "|__________________________________|" << endl;

        SetColor(14);
        cout << "\n                                             [ CONTROLS ]" << endl;
        cout << "                                 Player 1: 'A' (Left) & 'D' (Right)" << endl;
        cout << "                                 Player 2: 'J' (Left) & 'L' (Right)" << endl;

        SetColor(7);
        GotoXY(58, 17);

        char choice;

        while (true)
        {
            choice = _getch();
            if (choice == '1' || choice == '2')
            {
                cout << choice;
                break;
            }
        }

        if (choice == '2')
        {
            system("cls");
            SetColor(3);
            cout << "\n\n";
            cout << R"(
               _____          _____        _____              _____  _____  _   _  _____
              / ____|   /\   |  __ \      |  __ \     /\     / ____||_   _|| \ | |/ ____|
             | |       /  \  | |__) |     | |__) |   /  \   | |       | |  |  \| | |  __
             | |      / /\ \ |  _  /      |  _  /   / /\ \  | |       | |  | . ` | | |_ |
             | |____ / ____ \| | \ \      | | \ \  / ____ \ | |____  _| |_ | |\  | |__| |
              \_____/_/    \_\_|  \_\     |_|  \_\/_/    \_\ \_____||_____||_| \_|\_____|
            )" << endl;

            SetColor(8);
            cout << "                             Created By: Muhammad Faizan Naeem \n" << endl;
            SetColor(11);
            cout << "\n                                      Thanks For Playing !!!" << endl;

            Sleep(2000);
            break;
        }

        if (choice == '1')
        {
            system("cls");
            SetColor(3);
            cout << "\n\n";

            cout << R"(
               _____          _____        _____              _____  _____  _   _  _____
              / ____|   /\   |  __ \      |  __ \     /\     / ____||_   _|| \ | |/ ____|
             | |       /  \  | |__) |     | |__) |   /  \   | |       | |  |  \| | |  __
             | |      / /\ \ |  _  /      |  _  /   / /\ \  | |       | |  | . ` | | |_ |
             | |____ / ____ \| | \ \      | | \ \  / ____ \ | |____  _| |_ | |\  | |__| |
              \_____/_/    \_\_|  \_\     |_|  \_\/_/    \_\ \_____||_____||_| \_|\_____|
            )" << endl;

            SetColor(8);
            cout << "                             Created By: Muhammad Faizan Naeem \n" << endl;

            SetColor(7);

            cout << pad << " __________________________________ " << endl;
            cout << pad << "|                                  |" << endl;

            cout << pad << "|           ";
            SetColor(2);
            cout << "1. EASY  ";
            SetColor(7);
            cout << "              |" << endl;

            cout << pad << "|           ";
            SetColor(6);
            cout << "2. NORMAL";
            SetColor(7);
            cout << "              |" << endl;

            cout << pad << "|           ";
            SetColor(12);
            cout << "3. HARD  ";
            SetColor(7);
            cout << "              |" << endl;

            cout << pad << "|                                  |" << endl;

            cout << pad << "|           ";
            SetColor(15);
            cout << "Enter Choice:";
            SetColor(7);
            cout << "          |" << endl;

            cout << pad << "|__________________________________|" << endl;

            SetColor(14);
            cout << "\n                                        [ DIFFICULTY GUIDE ]" << endl;
            cout << "                                 1. EASY   - Slower speed , 3 lives" << endl;
            cout << "                                 2. NORMAL - Medium speed , 3 lives" << endl;
            cout << "                                 3. HARD   - Fast speed   , 1 life" << endl;

            GotoXY(58, 18);

            char diff;

            while (true)
            {
                diff = _getch();

                if (diff == '1' || diff == '2' || diff == '3')
                {
                    cout << diff;
                    break;
                }
            }

            if (diff == '1')
            {
                difficulty = 1;
            }
            else if (diff == '2')
            {
                difficulty = 2;
            }
            else if (diff == '3')
            {
                difficulty = 3;
            }

            Setup();
            StartCountdown();

            while (!gameOver)
            {
                Draw();
                Input();
                Logic();
                Sleep(gameSpeed);
            }

            system("cls");
            SetColor(4);
            cout << "\n\n\n";

            cout << R"(
                   _____          __  __  ______    ____ __      __ ______  _____
                  / ____|   /\   |  \/  ||  ____|  / __ \\ \    / /|  ____||  __ \
                 | |  __   /  \  | \  / || |__    | |  | |\ \  / / | |__   | |__) |
                 | | |_ | / /\ \ | |\/| ||  __|   | |  | | \ \/ /  |  __|  |  _  /
                 | |__| |/ ____ \| |  | || |____  | |__| |  \  /   | |____ | | \ \
                  \_____/_/    \_\_|  |_||______|  \____/    \/    |______||_|  \_\
            )" << endl;

            cout << pad;
            SetColor(12);

            if (winner == 2)
            {
                cout << "      Player 1 Crashed!" << endl;
                SetColor(10);
                cout << pad << "    Player 2 Wins!" << endl;
            }
            else
            {
                cout << "      Player 2 Crashed!" << endl;
                SetColor(10);
                cout << pad << "      Player 1 Wins!" << endl;
            }

            SetColor(14);
            cout << "\n" << pad << "        SCORE: " << score << "m" << endl;

            Sleep(5000);
            while (_kbhit())
            {
                _getch();
            }

            SetColor(7);
            cout << pad << "\nPress any key to return...";
            _getch();
        }
    }

    return 0;
}