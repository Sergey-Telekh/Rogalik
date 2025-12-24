#ifndef MOVEENEMIES_H
#define MOVEENEMIES_H

bool isDeapth(int** enemyPositions, int playerX, int playerY, int enemyCount, int& armor);
int moveEnemies(char** arrMap, int playerX, int playerY, int** enemyPositions);
void bit(char** arrMap, int playerX, int playerY, int sword, int bow);

#endif // MOVEENEMIES_H
