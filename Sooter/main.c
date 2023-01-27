#include<iostream>
#include<conio.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");

	int side_length;			//Длина стороны игровой зоны
	int game_zone;				//Общей полощадь игровой зоны
	int player_position;		//Начальная позиция игрока(всегда в центре)
	int code_key;				//Код клавиши
	char symbol_void = 'O';		//Символ пустоты
	char player = 'X';			//Символ игрока
	int zone_rend_step = 0;		//Шаг отрисовки игровой зоны
	int cnt_step = 0;			//Счётчик шагов
	int cnt_shoot = 0;			//Счётчик выстрелов
	int cnt_jamp = 0;			//Счётчик прыжков
	bool end_rend = true;		//Конец отрисовки
	bool game_on = true;		//Игра включена
	bool ext_game = true;		//Выход из игры	


	cout << "Введите нечётное число для генерации игровой зоны(рекомендуемый диапозон от 1 до 15)" << endl; cin >> side_length;

	if (side_length%2==0)	//Проверка на нечётность
	{
		side_length--;
	}
	game_zone = side_length*side_length;
	player_position = game_zone/2;

	cout << "Игровое поле состоит из двух символов: 'О' - пустая область, 'Х' - позиция игрока\n";
	cout << "Прыжок или выстрел сопровождается звуковым сигналом\n";
	cout << "Управление:\n";
	cout << "w - Шаг вверх\n";
	cout << "s - Шаг вниз\n";
	cout << "a - Шаг влево\n";
	cout << "d - Шаг вправо\n";
	cout << "Enter - выстрел\n";
	cout << "Space - Пражок\n";
	cout << "Esc - Выход\n\n";

//Цикл входа в игру
	while (ext_game)
	{
		do //Цикл отрисовки игрового поля и статистики
		{
			while (zone_rend_step < game_zone && end_rend)
			{
				if (zone_rend_step % side_length == 0 && zone_rend_step != 0)
				{
					cout << endl;
				}
				if (zone_rend_step == player_position)
				{
					cout << " " << player;
					zone_rend_step++;

					if (zone_rend_step % side_length == 0 && zone_rend_step != game_zone)
					{
						cout << endl;
					}
				}
				if (zone_rend_step != game_zone)
				{
					cout << " " << symbol_void;
					zone_rend_step++;
				}
				else
				{
					end_rend = false;
				}
			}

			cout << endl << endl;
			game_on = true;
			zone_rend_step = 0;
			cout << "Число шагов: " << cnt_step << endl;
			cout << "Число прыжков: " << cnt_jamp << endl;
			cout << "Число выстрелов: " << cnt_shoot << endl;
//******
//Обработчик нажатия клавиш
			code_key = _getch();

			switch (code_key)
			{
			case 119: cout << endl;		//Шаг вверх
				if ((player_position- side_length) >= 0)
				{
					player_position -= side_length; cnt_step++; game_on = false;
				}  
				else
				{
					player_position += game_zone-side_length; cnt_step++; game_on = false;
				}
				break;	
			case 97: cout << endl;		//Шаг влево
				if ((player_position-1) >= 0)
				{
					player_position--; cnt_step++; game_on = false;
				}
				break;
			case 115: cout << endl;		//Шаг вниз	
				if ((player_position+ side_length) < game_zone)
				{
					player_position += side_length; cnt_step++; game_on = false;
				}
				else
				{
					player_position -= game_zone - side_length; cnt_step++; game_on = false;
				}
				break;
			case 100: cout << endl;		//Шаг вправо
				if ((player_position+1) < game_zone)
				{
					player_position++; cnt_step++; game_on = false;
				}
				break;
			case 27: cout << endl; ext_game = false; game_on = false; break;		//Выход из игры
			case 32: cout << "\a" << endl; cnt_jamp++; game_on = false; break;		//Прыжок
			case 13: cout << "\a\a\a" << endl; cnt_shoot++; game_on = false;break;	//Выстрел
			}
			system("cls");
			end_rend = true;
		} while (game_on);
//*******		
	}
//Выход
	cout << "Game Over" << endl;
}