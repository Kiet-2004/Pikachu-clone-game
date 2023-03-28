#include "lib.h"
#include "consoleSetting.cpp"

void login(PlayerState &player, BoardState &a, int &mCurX, int &menu, int &playerid, bool &succlog, int lvlcap[], time_t &oriTime);
void checkLogin(PlayerState player, int &playerid, bool &succ, int &submenu);
void checkRegis(PlayerState &player, int &playerid, bool &succ, int &submenu, bool &log);
void saveGame(PlayerState player, int playerid, BoardState a);
void loadGame(PlayerState &player, int playerid, BoardState &a, int lvlcap[], time_t &oriTime);
void loadLB(LeaderBoard &lb);
void updateLB(LeaderBoard &lb, PlayerState player);
