#include "graphics.h"
#include "stdio.h"
#include "math.h"
#include "time.h"
#include "stdlib.h"
#include "map/intmap.cxx"

#define MaxX 1500
#define MaxY 900
#define Maxx 900
#define cage 50
#define Nx 18
#define Ny 18


void make_charecter(int *xcharecter, int *ycharecter, int *teleport_count, int *hp, int map[Nx][Ny])
{
	int key;
	if (kbhit()) { key = getch(); }
	else { key = 0; }
	if ((key == 75) && (*xcharecter > 0) && (getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2 - 50, *ycharecter * Maxx / Nx + Maxx / Nx / 2) != 7))
	{
		setfillstyle(1, BLACK);
		bar(cage * *xcharecter, cage * *ycharecter, cage * *xcharecter + cage, cage * *ycharecter + cage);
		*xcharecter -= 1;
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == LIGHTMAGENTA))
		{
			*teleport_count += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == GREEN) && (*hp < 10))
		{
			*hp += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
	}
	if ((key == 77) && (*xcharecter < Nx - 1) && (getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2 + 50, *ycharecter * Maxx / Nx + Maxx / Nx / 2) != 7))
	{
		setfillstyle(1, BLACK);
		bar(cage * *xcharecter, cage * *ycharecter, cage * *xcharecter + cage, cage * *ycharecter + cage);
		*xcharecter += 1;
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == LIGHTMAGENTA))
		{
			*teleport_count += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == GREEN) && (*hp < 10))
		{
			*hp += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
	}
	if ((key == 72) && (*ycharecter > 0) && (getpixel(*xcharecter * MaxY / Ny + MaxY / Ny / 2, *ycharecter * MaxY / Ny + MaxY / Ny / 2 - 50) != 7))
	{
		setfillstyle(1, BLACK);
		bar(cage * *xcharecter, cage * *ycharecter, cage * *xcharecter + cage, cage * *ycharecter + cage);
		*ycharecter -= 1;
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == LIGHTMAGENTA))
		{
			*teleport_count += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == GREEN) && (*hp < 10))
		{
			*hp += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
	}
	if ((key == 80) && (*ycharecter < Ny - 1) && (getpixel(*xcharecter * MaxY / Ny + MaxY / Ny / 2, *ycharecter * MaxY / Ny + MaxY / Ny / 2 + 50) != 7))
	{
		setfillstyle(1, BLACK);
		bar(cage * *xcharecter, cage * *ycharecter, cage * *xcharecter + cage, cage * *ycharecter + cage);
		*ycharecter += 1;
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == LIGHTMAGENTA))
		{
			*teleport_count += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == GREEN) && (*hp < 10))
		{
			*hp += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
	}



	if ((key == 9) && (*xcharecter < Nx - 2) && (getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2 + 100, *ycharecter * MaxY / Ny + MaxY / Ny / 2) != LIGHTGRAY) && (*teleport_count > 0))
	{
		setfillstyle(1, BLACK);
		bar(cage * *xcharecter, cage * *ycharecter, cage * *xcharecter + cage, cage * *ycharecter + cage);
		*xcharecter += 2; *teleport_count -= 1;
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == LIGHTMAGENTA))
		{
			*teleport_count += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
		if ((getpixel(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * Maxx / Nx + Maxx / Nx / 2) == GREEN) && (*hp < 10))
		{
			*hp += 1;
			map[*xcharecter][*ycharecter] = 0;
		}
	}

	if (key == 27) { setfillstyle(1, BLACK); bar(0, 0, MaxX, MaxY); outtextxy(MaxX / 2, MaxY / 2, "Пауза"); getch(); key = 0; }
	setfillstyle(1, BLUE);
	fillellipse(*xcharecter * Maxx / Nx + Maxx / Nx / 2, *ycharecter * MaxY / Ny + MaxY / Ny / 2, 15, 15);
}

void laberint()
{
	int xcharecter, ycharecter;
	int hp = 10, n_volna, delay_volna, key = 0, i = 0, j = 0;
	char pattern[8]{ 0x88, 0x44, 0x22, 0x44, 0x88, 0x44, 0x22, 0x44 };
	char pattern2[8]{ 0x11, 0x11, 0xFF, 0x11, 0x11, 0xFF, 0x11, 0x11 };
	char str[6];
	char str2[6];
	int lvl_count = 0;
	int teleport_count = 5;
	int last_point_of_player = 3;
	int map[Nx][Ny];
	srand((unsigned)time(NULL));
	while (hp > 0)
	{
		xcharecter = 0, ycharecter = last_point_of_player;
		int obstacle_massive[8] = { 4 * Maxx / Nx + Maxx / Nx / 2, 0, 9 * Maxx / Nx + Maxx / Nx / 2, 0, 13 * Maxx / Nx + Maxx / Nx / 2, 0, 16 * Maxx / Nx + Maxx / Nx / 2, 0 };
		int obstacle_massive2[4] = { Maxx - 20 , 6 * MaxY / Ny + MaxY / Ny / 2 , Maxx - 20 , 12 * MaxY / Ny + MaxY / Ny / 2 };
		n_volna = -100;
		delay_volna = 0;
		for (i = 0; i < Nx; i++)
		{
			for (j = 0; j < Ny; j++)
			{
				if (obstacle_map[i][j] == 0)
				{
					setfillstyle(1, BLACK);
					bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					map[i][j] = 0;
				}

				if (obstacle_map[i][j] == 1)
				{
					setfillstyle(1, LIGHTGRAY);
					bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					map[i][j] = 1;
				}
				if (obstacle_map[i][j] == 2)
				{
					if (rand() % 2 == 1)
					{
						setfillstyle(1, LIGHTGRAY);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
						map[i][j] = 1;
					}
					else
					{
						setfillstyle(1, BLACK);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
						map[i][j] = 0;
					}
				}

				if (obstacle_map[i][j] == 3)
				{
					if (rand() % 3 + 2 == 3)
					{
						setfillstyle(1, BLACK);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
						setfillstyle(1, WHITE);
						fillellipse(i * Maxx / Nx + Maxx / Nx / 2, j * MaxY / Ny + MaxY / Ny / 2, 10, 10);
						setfillstyle(1, GREEN);
						fillellipse(i * Maxx / Nx + Maxx / Nx / 2, j * MaxY / Ny + MaxY / Ny / 2, 7, 7);
						map[i][j] = 3;
					}
					else
					{
						if (rand() % 3 + 2 == 4)
						{
							setfillstyle(1, BLACK);
							bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
							setfillstyle(1, LIGHTMAGENTA);
							fillellipse(i * Maxx / Nx + Maxx / Nx / 2, j * MaxY / Ny + MaxY / Ny / 2, 7, 7);
							map[i][j] = 4;
						}
						else
						{
							setfillstyle(1, BLACK);
							bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
							map[i][j] = 0;
						}
					}
				}
				if (obstacle_map[i][j] == 5)
				{
					setfillpattern(pattern, LIGHTGREEN);
					bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					map[i][j] = 5;
				}
			}
		}
		while ((xcharecter < Nx - 1) && (hp > 0))
		{

			for (i = 0; i < Nx; i++)
			{
				for (j = 0; j < Ny; j++)
				{
					if (map[i][j] == 0)
					{
						setfillstyle(1, BLACK);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					}

					if (map[i][j] == 1)
					{
						setfillstyle(1, LIGHTGRAY);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					}
					if (map[i][j] == 2)
					{
						setfillstyle(1, LIGHTGRAY);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					}

					if (map[i][j] == 3)
					{
						setfillstyle(1, BLACK);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
						setfillstyle(1, WHITE);
						fillellipse(i * Maxx / Nx + Maxx / Nx / 2, j * MaxY / Ny + MaxY / Ny / 2, 10, 10);
						setfillstyle(1, GREEN);
						fillellipse(i * Maxx / Nx + Maxx / Nx / 2, j * MaxY / Ny + MaxY / Ny / 2, 7, 7);
					}
					if (map[i][j] == 4)
					{
						setfillstyle(1, BLACK);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
						setfillstyle(1, LIGHTMAGENTA);
						fillellipse(i * Maxx / Nx + Maxx / Nx / 2, j * MaxY / Ny + MaxY / Ny / 2, 7, 7);
					}
					if (map[i][j] == 5)
					{
						setfillpattern(pattern, LIGHTGREEN);
						bar(cage * i, cage * j, cage * i + cage, cage * j + cage);
					}
				}
			}

			make_charecter(&xcharecter, &ycharecter, &teleport_count, &hp, map);
			
			if (lvl_count == 1)
			{
				setfillstyle(1, RED);
				fillellipse(obstacle_massive[0], obstacle_massive[1], 5, 20);
				obstacle_massive[1] += 3;
				if (getpixel(obstacle_massive[0], obstacle_massive[1] + 26) == 1) { hp--; obstacle_massive[1] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[1] > MaxY) { obstacle_massive[1] = 0; }
			}

			if (lvl_count == 2)
			{
				setfillstyle(1, RED);
				fillellipse(obstacle_massive[0], obstacle_massive[1], 5, 20);
				obstacle_massive[1] += 7;
				if (getpixel(obstacle_massive[0], obstacle_massive[1] + 26) == 1) { hp--; obstacle_massive[1] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[1] > MaxY) { obstacle_massive[1] = 0; }


				setfillstyle(1, RED);
				fillellipse(obstacle_massive[2], obstacle_massive[3], 5, 20);
				obstacle_massive[3] += 7;
				if (getpixel(obstacle_massive[2], obstacle_massive[3] + 26) == BLUE) { hp--; obstacle_massive[3] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[3] > MaxY) { obstacle_massive[3] = 0; }

			}

			if (lvl_count == 3)
			{
				setfillstyle(1, RED);
				fillellipse(obstacle_massive[0], obstacle_massive[1], 5, 20);
				obstacle_massive[1] += 13;
				if (getpixel(obstacle_massive[0], obstacle_massive[1] + 26) == 1) { hp--; obstacle_massive[1] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[1] > MaxY) { obstacle_massive[1] = 0; }


				setfillstyle(1, RED);
				fillellipse(obstacle_massive[2], obstacle_massive[3], 5, 20);
				obstacle_massive[3] += 13;
				if (getpixel(obstacle_massive[2], obstacle_massive[3] + 26) == BLUE) { hp--; obstacle_massive[3] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[3] > MaxY) { obstacle_massive[3] = 0; }

				setfillstyle(1, RED);
				fillellipse(obstacle_massive[4], obstacle_massive[5], 5, 20);
				obstacle_massive[5] += 13;
				if (getpixel(obstacle_massive[4], obstacle_massive[5] + 26) == BLUE) { hp--; obstacle_massive[5] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[5] > MaxY) { obstacle_massive[5] = 0; }


			}

			if (lvl_count == 4)
			{
				setfillstyle(1, RED);
				fillellipse(obstacle_massive[0], obstacle_massive[1], 5, 20);
				obstacle_massive[1] += 13 + i;
				if (getpixel(obstacle_massive[0], obstacle_massive[1] + 26) == 1) { hp--; obstacle_massive[1] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[1] > MaxY) { obstacle_massive[1] = 0; }


				setfillstyle(1, RED);
				fillellipse(obstacle_massive[2], obstacle_massive[3], 5, 20);
				obstacle_massive[3] += 13 + i;
				if (getpixel(obstacle_massive[2], obstacle_massive[3] + 26) == BLUE) { hp--; obstacle_massive[3] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[3] > MaxY) { obstacle_massive[3] = 0; }

				setfillstyle(1, RED);
				fillellipse(obstacle_massive[4], obstacle_massive[5], 5, 20);
				obstacle_massive[5] += 13 + i;
				if (getpixel(obstacle_massive[4], obstacle_massive[5] + 26) == BLUE) { hp--; obstacle_massive[5] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[5] > MaxY) { obstacle_massive[5] = 0; }

				setfillstyle(1, RED);
				fillellipse(obstacle_massive[6], obstacle_massive[7], 5, 20);
				obstacle_massive[7] += 13 + i;
				if (getpixel(obstacle_massive[6], obstacle_massive[7] + 26) == BLUE) { hp--; obstacle_massive[5] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[7] > MaxY) { obstacle_massive[7] = 0; }

				i += 3;
				j = 0;

			}

			if (lvl_count >= 5)
			{
				setfillstyle(1, RED);
				fillellipse(obstacle_massive[0], obstacle_massive[1], 5, 20);
				obstacle_massive[1] += 13 + i;
				if (getpixel(obstacle_massive[0], obstacle_massive[1] + 26) == 1) { hp--; obstacle_massive[1] = 0; setfillstyle(1, BLACK); }
				if (obstacle_massive[1] > MaxY) { obstacle_massive[1] = 0; }


				setfillstyle(1, RED);
				fillellipse(obstacle_massive[2], obstacle_massive[3], 5, 20);
				obstacle_massive[3] += 13 + i;
				if (getpixel(obstacle_massive[2], obstacle_massive[3] + 26) == BLUE) { hp--; obstacle_massive[3] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[3] > MaxY) { obstacle_massive[3] = 0; }

				setfillstyle(1, RED);
				fillellipse(obstacle_massive[4], obstacle_massive[5], 5, 20);
				obstacle_massive[5] += 13 + i;
				if (getpixel(obstacle_massive[4], obstacle_massive[5] + 26) == BLUE) { hp--; obstacle_massive[5] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[5] > MaxY) { obstacle_massive[5] = 0; }

				setfillstyle(1, RED);
				fillellipse(obstacle_massive[6], obstacle_massive[7], 5, 20);
				obstacle_massive[7] += 13 + i;
				if (getpixel(obstacle_massive[6], obstacle_massive[7] + 26) == BLUE) { hp--; obstacle_massive[7] = 0; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive[7] > MaxY) { obstacle_massive[7] = 0; }

				i += 3;

				setfillstyle(1, RED);
				fillellipse(obstacle_massive2[0], obstacle_massive2[1], 20, 5);
				obstacle_massive2[0] -= j;
				if (getpixel(obstacle_massive2[0] - 26, obstacle_massive2[1]) == BLUE) { hp--; obstacle_massive2[0] = Maxx - 20; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive2[0] < 0) { obstacle_massive2[0] = Maxx - 20; }

				setfillstyle(1, RED);
				fillellipse(obstacle_massive2[2], obstacle_massive2[3], 20, 5);
				obstacle_massive2[2] -= j;
				if (getpixel(obstacle_massive2[2] - 26, obstacle_massive2[3]) == BLUE) { hp--; obstacle_massive2[2] = Maxx - 20; setfillstyle(1, BLACK); bar(990, 20, 990 + 25 * 10, 40); }
				if (obstacle_massive2[2] < 0) { obstacle_massive2[2] = Maxx - 20; }


				j += 3;

			}

			setfillstyle(1, RED);
			bar(950, 20, 950 + 25 * hp, 40);
			outtextxy(920, 20, " HP");

			itoa(teleport_count, str2, 10);
			outtextxy(920, 50, " TAB - телепорт через стену в одну клетку. Осталось использований: ");
			outtextxy(1385, 50, str2);

			itoa(lvl_count, str, 10);
			outtextxy(920, 80, " Количсетво пройденых уровней:");
			outtextxy(1150, 80, str);
			setfillstyle(1, LIGHTMAGENTA);
			fillellipse(927, 117, 7, 7);
			outtextxy(941, 110, "- это сферы, которые увеличивают количество телепортов");

			setfillstyle(1, WHITE);
			fillellipse(930, 147, 10, 10);
			setfillstyle(1, GREEN);
			fillellipse(930, 147, 7, 7);
			outtextxy(943, 140, "- это аптечка. Восполнит ваше HP. Еcли оно менmше 10");

			outtextxy(920, 170, "Мой совет. Не задерживайтесь на одном уровне долго. ");
			outtextxy(920, 200, "Иначе Вы умрёте. Если хотите взять паузу, нажмите ESC");

			for (i = 0; i < n_volna; i++)
			{
				for (j = 0; j < n_volna; j++)
				{
					obstacle_map[i][j] = 5;
				}
			}
			if (delay_volna == 5)
			{
				n_volna += 1;
				delay_volna = 0;
			}

			else
			{
				delay_volna++;
			}
			if ((getpixel(xcharecter * MaxY / Ny + MaxY / Ny / 2 + 15, ycharecter * MaxY / Ny + MaxY / Ny / 2 + 15) != BLACK) && (getpixel(xcharecter * MaxY / Ny + MaxY / Ny / 2 + 15, ycharecter * MaxY / Ny + MaxY / Ny / 2 + 15) != LIGHTGRAY)) { hp = 0; }
			delay(5);
		}
		last_point_of_player = ycharecter;
		if (hp > 0)
		{
			lvl_count++;
		}
		cleardevice();
	}
	outtextxy(Maxx / 2, MaxY / 2, "Вы умерли. Ну что же. Удачи в следующий раз");
	itoa(lvl_count, str, 10);
	outtextxy(Maxx / 2, MaxY / 2 + 30, "Количсетво пройденых уровней:");
	outtextxy(Maxx / 2 + 230, MaxY / 2 + 30, str);

	getch();
	closegraph();
	
}

int menu()
{
	int key = 0;
	int status = 3;
	setfillstyle(1, BLACK);
	bar(0, 0, MaxX, MaxY);
	outtextxy(MaxX / 2, 50, "Это меню");
	outtextxy(MaxX / 2 - 300, MaxY / 2, "Найжмите ENTER для начала игры");
	outtextxy(MaxX / 2 + 300, MaxY / 2, "Нажмите ESC для выхода из игры ");
	while (status == 3)
	{
		if (kbhit()) { key = getch(); }
		else { key = 0; }
		if (key == 27) { status = 0; }
		if (key == 13) { status = 1; }
	}
	return status;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	initwindow(MaxX, MaxY);
	int key = 0;
	if (menu() == 1)
	{
		cleardevice();
		laberint();
	}
	else
	{
		closegraph();
	}


	return 0;
}