#include "lib.h"
#include "consoleSetting.cpp"

void login(PlayerState &player, int &mCurX, int &menu, int &playerid, bool &succlog, SaveState &save);
void checkLogin(PlayerState player, int &playerid, bool &succ, int &submenu);
void checkRegis(PlayerState &player, int &playerid, bool &succ, int &submenu, bool &log);
void saveGame(SaveState &save, int playerid, BoardState a, int mode, time_t oriTime, int lvl, int lvlcap, int count, int score);
void createGame(int playerid);
void loadMode(SaveState &save, int playerid);
void loadGame(SaveState &save, int playerid, BoardState &a, int &mode, time_t &oriTime, int &lvl, int lvlcap[], int &count, int &score);
void loadLB(PlayerState &player, int playerid);
void updateLB(PlayerState &player, int playerid, int mode, int score);
