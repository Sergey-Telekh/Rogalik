#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stuffLikeThat.h"

void spavner(char** arrMap, int& enemyCount)
{
	if (enemies(arrMap) <= 60)
	{
		srand(time(NULL));

		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 56; ++j)
			{
				if (arrMap[i][j] == '"')
				{
					bool spawnX = false;
					bool spawnY = false;
					for (int l = -3; l < 4; ++l)
					{
						int temp = rand() % 80;
						if (temp == 54 && i + l < 30 && i + l > 0 && !spawnX)
						{
							if (arrMap[i + l][j] == ' ')
							{
								arrMap[i + l][j] = 'D';
								spawnX = true;
							}
						}
						if (temp == 61 && j + l < 56 && j + l > 0 && !spawnY)
						{
							if (arrMap[i][j + l] == ' ')
							{
								arrMap[i][j + l] = 'D';
								spawnY = true;
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