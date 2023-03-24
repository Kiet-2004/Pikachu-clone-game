#include "lib.h"
#include "consoleSetting.cpp"

void login(PlayerState &player, int &mCurX, int &menu, int &playerid, bool &succlog);
void checkLogin(PlayerState player, int &playerid, bool &succ, int &submenu);
void checkRegis(PlayerState player, int &playerid, bool &succ, int &submenu, bool &log);

//void readData(vector<Player> &list);
//void writeData(vector<Player> &list);
//void login(vector<Player> &list, Player &a, bool &flag);
//void signUp(vector<Player> &list, Player &a, bool &flag);
//
//void readSaveFile(vector<Save> &a);
//void writeSaveFile(vector<Save> &a);
