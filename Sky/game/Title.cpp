#include "Title.h"



Title::Title()
{
	font = LoadFontDataToHandle("Font/Love Letter.dft", 0);
	tx = 490;
	adx = 495;
	button = 0;
	music.TitleSound(2);
}


Title::~Title()
{
}


int Title::title() {
	SetAlwaysRunFlag(true);
	graph.Title();

	//360 420 suta 380 500 lo 340 600 exit
	DrawStringToHandle(360, 400, "Star", GetColor(255,255,255), font);
	DrawStringToHandle(tx, 400, "t", GetColor(255, 255, 255), font);
	DrawStringToHandle(400, 485, "Lo", GetColor(255, 255, 255), font);
	DrawStringToHandle(adx, 485, "ad", GetColor(255, 255, 255), font);
	DrawStringToHandle(340, 580, "EÅ@xÅ@iÅ@t", GetColor(255, 255, 255), font);


	if (keyInput.GetIsUpdate(KEY_INPUT_DOWN)) {
		music.TitleSound(0);
		button++;
	}
	else if (keyInput.GetIsUpdate(KEY_INPUT_UP)) {
		music.TitleSound(0);
		button--;
		if (button < 0) {
			button = 2;
		}
	}
	
	switch (button) {
	case 0:
		tx = 465;
		adx = 495;
		DrawLineAA(350, 440, 500, 441, GetColor(255, 255, 255));
		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_SPACE) || keyInput.GetIsUpdate(KEY_INPUT_Z)) {
			graph.Title();
			music.TitleSound(1);
				return 3;

		}
		break;

	case 1:
		tx = 490;
		adx = 455;
		DrawLineAA(390, 525, 540, 526, GetColor(255, 255, 255));
		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_SPACE) || keyInput.GetIsUpdate(KEY_INPUT_Z)) {
			music.TitleSound(1);
			return 2;
		}
		break;
	
	case 2:
		tx = 490;
		adx = 495;
		DrawLineAA(330, 620, 480, 621, GetColor(255, 255, 255));
		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_SPACE) || keyInput.GetIsUpdate(KEY_INPUT_Z)) {
			music.TitleSound(1);
			return 1;
		}
		break;
		


	default:
		tx = 490;
		adx = 495;
		button = 0;
		break;


	}
	
	return 0;

}



