#include "Music.h"



Music::Music()
{
	ice = LoadSoundMem("Musik/2.mp3");
	key = LoadSoundMem("Musik/pageturn1.mp3");
	titleback = LoadSoundMem("Musik/Refraction(Piano Improvisation).mp3");
	ChangeVolumeSoundMem(180, ice);
	ChangeVolumeSoundMem(250, titleback);
}


Music::~Music()
{
}

void Music::TitleMusic() {
	PlaySoundMem(titleback, DX_PLAYTYPE_LOOP);
}

void Music::TitleSound(int a) {

	switch (a) {
	
	case 0:
		PlaySoundMem(ice, DX_PLAYTYPE_BACK);
		break;

	case 1:
		PlaySoundMem(key, DX_PLAYTYPE_NORMAL);
		break;

	case 2:
		PlaySoundMem(titleback, DX_PLAYTYPE_LOOP);
		break;

	default:
		break;
	
	}

}