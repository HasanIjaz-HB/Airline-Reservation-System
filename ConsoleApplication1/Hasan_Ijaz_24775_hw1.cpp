#include <iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

int M[2][50];
int turn = 0;
bool seatsempty;

void * bookTA3 (void *)
{
	while (true)
	{
		if (seatsempty == false)
			break;
		int r = rand() % 2;
		int c = rand() % 50;
		int seatN;
		if (r == 0)
			seatN = 2 * c + 1;
		else
			seatN = 2 * (c + 1);

		while (turn != 2);
		
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					if (M[r][c] == 0)
					{
						M[r][c] = 1;
						cout << "Seat Number " << seatN << " is resrved by Travel Agency 3" << endl;
						turn = 0;
					}
				}
			}
	}
}

void * bookTA2 (void *)
{
	while (true)
	{
		if (seatsempty == false)
			break;
		int r = rand() % 2;
		int c = rand() % 50;
		int seatN;
		if (r == 0)
			seatN = 2 * c + 1;
		else
			seatN = 2 * (c + 1);

		while (turn != 1);
		
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					if (M[r][c] == 0)
					{
						M[r][c] = 2;
						cout << "Seat Number " << seatN << " is resrved by Travel Agency 2" << endl;
						turn = 2;
					}
				}
			}
	}
}

void * bookTA1 (void *)
{
	while (true)
	{
		if (seatsempty == false)
			break;
		int r = rand() % 2;
		int c = rand() % 50;
		int seatN;
		if (r == 0)
			seatN = 2 * c + 1;
		else
			seatN = 2 * (c + 1);

		while (turn != 0);
		
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 50; j++)
				{
					if (M[r][c] == 0)
					{
						M[r][c] = 3;
						cout << "Seat Number " << seatN << " is resrved by Travel Agency 1" << endl;
						turn = 1;
					}
				}
			}
	}
}

int main() 
{
	int Seatcount = 0;
	srand(time(NULL));
	pthread_t TravelAgency1;
	pthread_t TravelAgency2;
	pthread_t TravelAgency3;


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 50; j++)
		{ 
			M[i][j] = 0;
		}
	}

	pthread_create(&TravelAgency1, NULL, bookTA1, NULL);
	pthread_create(&TravelAgency2, NULL, bookTA2, NULL);
	pthread_create(&TravelAgency3, NULL, bookTA3, NULL);

	while(true)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				if (M[i][j] != 0)
					Seatcount++;
			}
		}

		if (Seatcount == 100)
		{
			seatsempty = false;
		}
		else
		{
			seatsempty = true;
		}
	}
		pthread_join(TravelAgency1, NULL);
		pthread_join(TravelAgency2, NULL);
		pthread_join(TravelAgency3, NULL);
	return 0;
}