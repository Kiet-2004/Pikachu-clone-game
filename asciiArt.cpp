#include "asciiArt.h"

void deleteArt(int m, int n, char **&display){
    for (int i = 0; i < 5 * (m + 2); i++)
        delete[] display[i];
    delete[] display;
}

void generateArt(int m, int n, char **&display){
    display = new char*[5 * (m + 2)];
    for (int i = 0; i < 5 * (m + 2); i++)
        display[i] = new char[7 * (n + 2)];

    ifstream ifs;
    ifs.open("art.txt");
    if(!ifs.is_open()){
        srand(time(0));
        for (int i = 0; i < 5 * (m + 2); i++){
            for (int j = 0; j < 7 * (n + 2); j++){
                char gen = (char) (rand() % 94 + 33);
                display[i][j] = gen;
            }
        }
    }
    else{
        for (int i = 0; i < 5 * (m + 2); i++){
            string str;
            getline(ifs, str, '\n');
            for (int j = 0; j < 7 * (n + 2); j++){
                display[i][j] = str[j];
            }
        }
    }
    ifs.close();
}

void drawLine(int line[][2])
{
    for (int k = 0; k < 3; k++)
    {
        if(line[k+1][0] == 0 && line[k+1][1] == 0)
            break;
        SHORT x1 = line[k][0], x2 = line[k+1][0], y1 = line[k][1], y2 = line[k+1][1];
        if (x1 == x2)
        {
            if (y1 > y2)
                swap (y1, y2);
            for (SHORT i = y1 * 7 + 3; i <= y2 * 7 + 3; i++)
                {
                    cursor((SHORT)i, (SHORT)(x1 * 5 + 3));
                    cout << '@';
                }
        }
        else
        {
            if (x1 > x2)
                swap (x1, x2);
            for (SHORT i = x1 * 5 + 3; i <= x2 * 5 + 3; i++)
                {
                    cursor((SHORT)(y1 * 7 + 3), (SHORT)i);
                    cout << '@';
                }
        }
    }
}
