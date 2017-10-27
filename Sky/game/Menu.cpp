#include "Menu.h"



Menu::Menu() {
	angle = 0;
	FontHandle = LoadFontDataToHandle("Font/マメロン.dft", 0);
	White = false;
	angle = 0;

	stageangle[0] = -3.1416 / 6;
	stageangle[1] = -2 * 3.1416 / 6;
	stageangle[2] = -3 * 3.1416 / 6;
	stageangle[3] = 0;
	stagenum[0] = 12;
	stagenum[1] = 24;
	stagenum[2] = 36;
	stagenum[3] = 0;
	stageselect = 0;

	Savebu = false;
	Rannum = 0;
}


Menu::~Menu() {



}

int Menu::Win() {
	graph.Menu(White);
	graph.MenuCircle(150, 200, angle);
	text.Drawdate();
	//GetMousePoint(&X, &Y);
	//DrawFormatString(20,20,GetColor(255,255,255),"%d,%d",X,Y);

	/*

		if (5 <= X && X <= 200 && 660 <= Y && Y <= 700) {
		White = true;
		if (mouseInput.GetLeftPressFrame() == 1) {
			return 3;
		}
	}
	else {
		White = false;
	}
	*/

	if(keyInput.GetIsUpdate(KEY_INPUT_DOWN)){
		Savebu = true;
		White = true;
}
	else if (keyInput.GetIsUpdate(KEY_INPUT_UP)) {
		Savebu = false;
		White = false;
	
	}


		if (Savebu == true) {
			if (keyInput.GetIsUpdate(KEY_INPUT_RETURN)|| keyInput.GetIsUpdate(KEY_INPUT_SPACE)||keyInput.GetIsUpdate(KEY_INPUT_Z)) {
				return 6;
		}
	}

		if (Savebu == false) {


			if (stagenum[stageselect] == 12) {

				if (keyInput.GetIsUpdate(KEY_INPUT_RIGHT)) {
					music.TitleSound(0);
					if (stageselect == 3) {
						stageselect = 0;
					}
					else {
						stageselect++;
					}

				}
				else if (keyInput.GetIsUpdate(KEY_INPUT_LEFT)) {
					music.TitleSound(0);
					if (stageselect == 0) {
						stageselect = 3;
					}
					else {
						stageselect--;
					}
				}
			}
			else {
				if (stagenum[stageselect] > 12) {

					angle -= 2.5;

					for (int i = 0; i < 4; i++) {
						stageangle[i] += 3.1416 / 72;
						stagenum[i]--;

					}

				}
				if (stagenum[stageselect] < 12) {
					angle += 2.5;
					for (int i = 0; i < 4; i++) {
						stageangle[i] -= 3.1416 / 72;
						stagenum[i]++;

					}
				}
				for (int i = 0; i < 4; i++) {
					if (stagenum[i] == -6) {
						stageangle[i] = -7 * 3.1416 / 12;
						stagenum[i] = 42;
					}
					else if (stagenum[i] == 42) {
						stageangle[i] = 3.1416 / 12;
						stagenum[i] = -6;
					}
				}
			}
		}
	


	DrawFormatStringToHandle(150+300*cos(stageangle[0]), 200-300*sin(stageangle[0]), GetColor(255, 255, 255), FontHandle,"図書館に行く");
	DrawFormatStringToHandle(150 + 300 * cos(stageangle[1]), 200 - 300 * sin(stageangle[1]), GetColor(255, 255, 255), FontHandle, "部室に行く");
	DrawLineAA(400, 370, 520, 370, GetColor(255, 255, 255));
	DrawFormatStringToHandle(150 + 300 * cos(stageangle[2]), 200 - 300 * sin(stageangle[2]), GetColor(255, 255, 255), FontHandle, "屋上に行く");
	DrawFormatStringToHandle(150 + 300 * cos(stageangle[3]), 200 - 300 * sin(stageangle[3]), GetColor(255, 255, 255), FontHandle, "どこかに行く");


	if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
		switch (stageselect)
		{

		case 0:
			text.YLine();
			return 7;
			break;

		case 1:
			text.RLine();
			return 8;
			break;

		case 2:
			text.KLine();
			return 9;
			break;

		case 3:
			text.MLine();
			return 10;
			break;


		default:
			break;


		}
	
	
	
	}

	
	return 5;

}