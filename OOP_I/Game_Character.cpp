#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string hero_gun = "▄︻デ══━一━";

string enemy_gun = "━一══╦̵̵̿━︻▄";

class GameHero
{
private:
    int max_power_boost = 10;
    bool powerStatus = true;

public:
    string name = "Hero";
    string specialPower = "Wrath";

    int health = 100;
    int energy = 50;
    int score = 0;

    void Move()
    {
        cout << name << " is moving..." << endl;
    }

    void Attack()
    {
        energy -= 5;
        score += 10;
        cout << name << " fires a bullet!" << endl;
    }

    void PowerBoost()
    {
        if (max_power_boost)
        {
            energy += 10;
            max_power_boost--;
        }
        else
        {
            cout << "Not available !" << endl;
        }
    }

    void TakeHit()
    {
        health -= 10;
        cout << name << " got hit! -10 HP" << endl;
    }

    void ShowStatus()
    {
        cout << endl
             << "----------- " << name << " -----------" << endl;
        cout << "Special Power : " << specialPower << endl;
        cout << "Health        : " << health << endl;
        cout << "Energy        : " << energy << endl;
        cout << "Score         : " << score << endl;
        cout << "------------------------------" << endl;
    }
    void ShowStatus1()
    {
        cout << endl
             << "----------- " << name << " -----------" << endl;
        cout << "Health        : " << health << endl;
        cout << "Score         : " << score << endl;
        cout << "------------------------------" << endl;
    }
};

class Enemy
{
private:
    int max_power_boost = 10;
    bool powerStatus = true;

public:
    string name = "Enemy";
    string specialPower = "Shadow";

    int health = 100;
    int energy = 50;
    int score = 0;

    void Attack()
    {
        score += 10;
        cout << name << " fires a shadow bolt!" << endl;
    }

    void TakeHit()
    {
        health -= 10;
        cout << name << " got hit! -10 HP" << endl;
    }

    void ShowStatus1()
    {
        cout << endl
             << "----------- " << name << " -----------" << endl;
        cout << "Health        : " << health << endl;
        cout << "Score         : " << score << endl;
        cout << "------------------------------" << endl;
    }
};

int getRandomNum()
{
    return rand() % 3;
}

void GameScreen(int hero_row, int enemy_row, bool arr[3][6], bool hero_pos[3], bool enemy_pos[3], int hero_bullets[3][2], int enemy_bullets[3][2], string hero_name, string enemy_name)
{

    cout << endl
         << "|     " << hero_name << "                                        " << enemy_name << "     ";
    cout << endl
         << "-------------------------------------------------------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        if (enemy_bullets[2][0] == hero_row)
        {

            if (hero_pos[i])
            {
                cout << "|💥💥";
                cout << hero_gun;
            }
            else
                cout << "|    \t\t\t";
        }
        else
        {
            if (hero_pos[i])
            {
                cout << "|    ";
                cout << hero_gun;
            }
            else
                cout << "|    \t\t\t";
        }

        for (int j = 0; j < 6; j++)
        {
            if (j % 2 == 0)
            {
                if (arr[i][j])
                    cout << "  ◀  ";
                else
                    cout << "     ";
            }
            else
            {
                if (arr[i][j])
                    cout << " ▶️  ";
                else
                    cout << "     ";
            }
        }

        if (hero_bullets[2][0] == enemy_row)
        {

            if (enemy_pos[i])
            {
                cout << enemy_gun;
                cout << "💥💥 ";
            }
            else
                cout << "\t\t\t    ";
        }
        else
        {
            if (enemy_pos[i])
            {
                cout << enemy_gun;
                cout << "     ";
            }
            else
                cout << "\t\t\t    ";
        }

        cout << endl
             << endl;
    }
    cout << "-------------------------------------------------------------" << endl;
}

int main()
{
    //-------------------------------------Main Challenge ------------------------------

    srand(time(0));
    GameHero hero;
    Enemy enemy;

    cout << "First 5 sec -- mian challenge" << endl;
    cout << "After 5 sec -- bonus challenge" << endl;
    cout << endl;

    hero.Move();
    hero.Attack();
    hero.PowerBoost();
    hero.TakeHit();
    hero.ShowStatus();
    cout << endl
         << endl;

    //----------------------------------------------------------------------------------

    //----------------------------------Optional----------------------------------------
    Sleep(5000);

    {
        int hero_bullets[3][2] = {{-1, 1}, {-1, 3}, {-1, 5}};
        int enemy_bullets[3][2] = {{-1, 4}, {-1, 2}, {-1, 0}};

        while (hero.health > 0 && enemy.health > 0)
        {
            bool arr[3][6] = {false};
            bool hero_pos[3] = {false};
            bool enemy_pos[3] = {false};

            system("cls");

            int hero_row = getRandomNum();
            int enemy_row = getRandomNum();

            hero_pos[hero_row] = true;
            enemy_pos[enemy_row] = true;

            for (int i = 2; i > 0; i--)
            {
                hero_bullets[i][0] = hero_bullets[i - 1][0];
            }
            hero_bullets[0][0] = hero_row;

            for (int i = 2; i > 0; i--)
            {
                enemy_bullets[i][0] = enemy_bullets[i - 1][0];
            }
            enemy_bullets[0][0] = enemy_row;

            for (int i = 0; i < 3; i++)
            {
                if (hero_bullets[i][0] != -1)
                {
                    arr[hero_bullets[i][0]][hero_bullets[i][1]] = true;
                }

                if (enemy_bullets[i][0] != -1)
                {
                    arr[enemy_bullets[i][0]][enemy_bullets[i][1]] = true;
                }
            }

            if (enemy_bullets[2][0] == hero_row)
            {
                hero.TakeHit();
                enemy.Attack();
            }
            if (hero_bullets[2][0] == enemy_row)
            {
                enemy.TakeHit();
                hero.Attack();
            }

            GameScreen(hero_row, enemy_row, arr, hero_pos, enemy_pos, hero_bullets, enemy_bullets, hero.name, enemy.name);

            hero.ShowStatus1();
            enemy.ShowStatus1();

            Sleep(1000);
        }
        if (hero.health > enemy.health)
        {
            cout << "!!!  " << hero.name << " Won !!!" << endl;
        }
        else if (hero.health < enemy.health)
        {
            cout << endl;
            cout << "!!!  " << enemy.name << " Won !!!" << endl;
        }
        else
        {
            cout << "The match is draw " << endl;
        }
    }

    return 0;
}