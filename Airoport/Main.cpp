#include <iostream>
#include <Windows.h>
 
int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));
	int airID = 0;
	const int tbak = 100;
	int AB = 0;
	int BC = 0;
	int m = 0;
	
	int air = 0;
	int l[6]{ 750, 1500,2000, 1000,2000,3000 }; // порог

	int exp[6]{ 1, 4, 7,2,4,6 };
	int k = 0;
	int fuel[2]{ 300, 1000 };
	int max[2]{ 2000, 3000 };
	int ckm = 0; // расчет на 1 км
	int fuelAB = 0;
	int fuelBC = 0;
	int useAB = 0;
	int remainAB = 0;
	int possible = 1;
	int z = 0; // заправка
	
		std::cout << "Введите номер самолета (1 или 2): ";
		std::cin >> air;
		if (air != 1 && air != 2)
		{
			std::cout << "Недопустимый номер самолета";
			Sleep(2000);
			system("cls");
			return 0;
		}
		airID = air - 1;
		std::cout << "Введите расстояние от A до B: ";
		std::cin >> AB;
		std::cout << "Введите расстояние от B до C: ";
		std::cin >> BC;
		std::cout << "Введите массу груза: ";
		std::cin >> m;
		if (m > max[airID])
		{
			possible = 0;
			

		}
		if (possible == 1)
		{
			int id = airID * 3;
			if (m <= l[id])
			{
				ckm = exp[id];
			}
			else if (m <= l[id + 1])
			{
				ckm = exp[id + 1];
			}
			else if (m <= l[id + 2])
			{
				ckm = exp[id + 2];
			}
		}
		if (possible == 1)
		{
			fuelAB = AB * ckm;
			if (fuelAB <= tbak)
			{
				useAB = 0;
			}
			else
			{
				useAB = fuelAB - tbak;
			}
		}
		if (useAB > fuel[airID])
		{
			possible = 0;
		}
		if (possible == 1)
		{
			remainAB = fuel[airID] - useAB;
			fuelBC = BC * ckm;
			if (remainAB >= fuelBC)
			{
				z = 0;
			}
			else
			{
				z = fuelBC - remainAB;
			}
			if (z > fuel[airID])
			{
				possible = 0;
			}
		}
				
		if (possible == 0)
		{
			std::cout << "Самолет не может пролететь такое расстояние или превышена грузоподъемность";
		}
		else if (z == 0)
		{
			std::cout << "Самолет долетел без заправки";
		}
		else
		{
			std::cout << "Минимальное количество дозаправки в точке B составило: " << z << " литров";
		}







	return 0;


}