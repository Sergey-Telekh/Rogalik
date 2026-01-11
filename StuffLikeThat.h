#ifndef STUFFLIKETHAT_H
#define STUFFLIKETHAT_H

void clearMap(char** arrMap);
int enemies(char** arrMap);
bool movePlayer(char** arrMap, int& playerX, int& playerY, int& newX, int& newY, int& keys, bool& flagMove, int& bomb);

#endif // STUFFLIKETHAT_H