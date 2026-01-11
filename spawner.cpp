#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stuffLikeThat.h"

void spavner(char** arrMap, int& enemyCount)
{
	if (enemies(arrMap) <= 38)
	{
		srand(time(0));

		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 56; ++j)
			{
				if (arrMap[i][j] == '"')
				{
					for (int l = -3; l < 4; ++l)
					{
						int temp = rand() % 75;
						if (temp == 1 && i + l < 30 && i + l > 0)
						{
							if (arrMap[i + l][j] == ' ')
							{
								arrMap[i + l][j] = 'D';
							}
						}
						if (temp == 2 && j + l < 56 && j + l > 0)
						{
							if (arrMap[i][j + l] == ' ')
							{
								arrMap[i][j + l] = 'D';
							}
						}
					}
				}
			}
		}
		return;
	}
	else
	{
		return;
	}

}