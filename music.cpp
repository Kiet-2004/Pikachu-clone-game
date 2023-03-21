#include "music.h"

void playMusic()
{
    PlaySound(TEXT("kawaikute.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
