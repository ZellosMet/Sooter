#include<iostream>
#include<conio.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");

	int side_length;			//����� ������� ������� ����
	int game_zone;				//����� �������� ������� ����
	int player_position;		//��������� ������� ������(������ � ������)
	int code_key;				//��� �������
	char symbol_void = 'O';		//������ �������
	char player = 'X';			//������ ������
	int zone_rend_step = 0;		//��� ��������� ������� ����
	int cnt_step = 0;			//������� �����
	int cnt_shoot = 0;			//������� ���������
	int cnt_jamp = 0;			//������� �������
	bool end_rend = true;		//����� ���������
	bool game_on = true;		//���� ��������
	bool ext_game = true;		//����� �� ����	


	cout << "������� �������� ����� ��� ��������� ������� ����(������������� �������� �� 1 �� 15)" << endl; cin >> side_length;

	if (side_length%2==0)	//�������� �� ����������
	{
		side_length--;
	}
	game_zone = side_length*side_length;
	player_position = game_zone/2;

	cout << "������� ���� ������� �� ���� ��������: '�' - ������ �������, '�' - ������� ������\n";
	cout << "������ ��� ������� �������������� �������� ��������\n";
	cout << "����������:\n";
	cout << "w - ��� �����\n";
	cout << "s - ��� ����\n";
	cout << "a - ��� �����\n";
	cout << "d - ��� ������\n";
	cout << "Enter - �������\n";
	cout << "Space - ������\n";
	cout << "Esc - �����\n\n";

//���� ����� � ����
	while (ext_game)
	{
		do //���� ��������� �������� ���� � ����������
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
			cout << "����� �����: " << cnt_step << endl;
			cout << "����� �������: " << cnt_jamp << endl;
			cout << "����� ���������: " << cnt_shoot << endl;
//******
//���������� ������� ������
			code_key = _getch();

			switch (code_key)
			{
			case 119: cout << endl;		//��� �����
				if ((player_position- side_length) >= 0)
				{
					player_position -= side_length; cnt_step++; game_on = false;
				}  
				else
				{
					player_position += game_zone-side_length; cnt_step++; game_on = false;
				}
				break;	
			case 97: cout << endl;		//��� �����
				if ((player_position-1) >= 0)
				{
					player_position--; cnt_step++; game_on = false;
				}
				break;
			case 115: cout << endl;		//��� ����	
				if ((player_position+ side_length) < game_zone)
				{
					player_position += side_length; cnt_step++; game_on = false;
				}
				else
				{
					player_position -= game_zone - side_length; cnt_step++; game_on = false;
				}
				break;
			case 100: cout << endl;		//��� ������
				if ((player_position+1) < game_zone)
				{
					player_position++; cnt_step++; game_on = false;
				}
				break;
			case 27: cout << endl; ext_game = false; game_on = false; break;		//����� �� ����
			case 32: cout << "\a" << endl; cnt_jamp++; game_on = false; break;		//������
			case 13: cout << "\a\a\a" << endl; cnt_shoot++; game_on = false;break;	//�������
			}
			system("cls");
			end_rend = true;
		} while (game_on);
//*******		
	}
//�����
	cout << "Game Over" << endl;
}