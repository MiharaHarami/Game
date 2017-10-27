#include "SaveLoad.h"



SaveLoad::SaveLoad()
{
	Sswitch = false;
	White = false;
	LoadFlag = 0;
	numb = 1;
	FontHandle = LoadFontDataToHandle("Font/マメロン.dft", 0);
	ico = LoadGraph("Img/ico.png");
	for (int i = 0; i < 5;i++) {
		SaveWin(i);
	}
}


SaveLoad::~SaveLoad()
{
}


void SaveLoad::Save() 
{



	DrawFormatStringToHandle(280, 50, GetColor(255, 255, 255), FontHandle, "Save");


	for (int Y = 1; Y < 5;Y++) {
		DrawFormatStringToHandle(0, 150 +(Y-1) * 100, GetColor(255, 255, 255), FontHandle, "セーブ %d", Y);
		if (date[Y] != NULL &&date[Y] <= 10) {
			DrawFormatStringToHandle(100, 150 + (Y - 1) * 100, GetColor(255, 255, 255), FontHandle, "%d日目", date[Y]);
		}
	}


	if (keyInput.GetIsUpdate(KEY_INPUT_DOWN)) {
		if (numb <= 5) {
			numb++;
		}
	}
	else if (keyInput.GetIsUpdate(KEY_INPUT_UP)) {
		if (numb >= 2) {
			numb--;
		}

	}

	if (numb >= 5) {
		Savebu = true;
		White = true;
	}
	if (numb < 5) {
		DrawGraph(0, 140 + (numb-1) * 100, ico, true);
		Savebu = false;
		White = false;
	}
	if (numb <= 4) {
		if (keyInput.GetIsUpdate(KEY_INPUT_SPACE) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_RETURN)) {
			text.Save(numb);
			for (int i = 0; i < 5; i++) {
				SaveWin(i);
			}
		}
	}

}

void SaveLoad::Load() 
{


	DrawFormatStringToHandle(280, 50, GetColor(255, 255, 255), FontHandle, "Load");


	for (int Y = 1; Y < 5; Y++) {
		DrawFormatStringToHandle(0, 150 + (Y-1) * 100, GetColor(255, 255, 255), FontHandle, "セーブ %d", Y);
		if (date[Y] != NULL &&date[Y] <= 10) {
			DrawFormatStringToHandle(100, 150 + (Y - 1) * 100, GetColor(255, 255, 255), FontHandle, "%d日目", date[Y]);
		}
		
	}

	

	if (keyInput.GetIsUpdate(KEY_INPUT_DOWN)) {

		if (numb < 5) {
			numb++;
		}
	}
	else if (keyInput.GetIsUpdate(KEY_INPUT_UP)) {
		if (numb >= 2) {
			numb--;
		}
	}
	if (numb < 5) {
		DrawGraph(0, 140 + (numb - 1) * 100, ico, true);
		Savebu = false;
		White = false;
	}
	if (numb >= 5) {
		Savebu = true;
		White = true;
	}
	if (numb <= 4) {
		if (keyInput.GetIsUpdate(KEY_INPUT_SPACE) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_RETURN)) {
			LoadFlag = text.Load(numb);
		}
	
	}

}


void SaveLoad::SaveWin(int num)
{

	using namespace std;
	struct stat buf;

	std::string str1("Save");
	std::string str2(std::to_string(num));
	std::string str3(".txt");
	std::string filename = str1 + str2 + str3;



	if (stat(filename.c_str(), &buf) == 0) {

		// ファイルが存在する
		std::ifstream ifs(filename);

		std::string datastr;
		while (getline(ifs, datastr, ',')) {
			std::cout << datastr << std::endl;
			LoadIn.push_back(datastr);
		}

		date[num] = std::stoi(LoadIn[1].c_str());
	}
	else {

		// ファイルが存在しない

	}

	

	

}

int SaveLoad::SaveForm(int num) {
	//SaveWin();
	if (LoadFlag == 1) {
		LoadFlag = 0;
			return 5;
	}
	if (LoadFlag == -1) {
		DrawFormatStringToHandle(280, 100, GetColor(255, 255, 255), FontHandle, "セーブファイルがないよ");
	}
	
	GetMousePoint(&X, &Y);
	//DrawFormatString(20, 20, GetColor(255, 255, 255), "%d,%d", X, Y);
	if (keyInput.GetIsUpdate(KEY_INPUT_LEFT) || keyInput.GetIsUpdate(KEY_INPUT_RIGHT)) {
		if (Sswitch == true ) {
			Sswitch = false;

		}
		else if (Sswitch == false && num != 0) {
			Sswitch = true;

		}
	}


	graph.Save(Sswitch, White);
	text.Come();
	GetMousePoint(&X, &Y);

	
		if (Sswitch == true) {
			Save();
	}
	else if (Sswitch == false ) {
		Load();
	}
	


	if (Savebu == true) {

		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_SPACE) || keyInput.GetIsUpdate(KEY_INPUT_Z)) {
			switch (num) {

			case 0:
				text.ComBox(true);
				return 0;
				break;

			case 1:
				text.ComBox(true);
				return 5;
				break;

			default:
				break;
			}
		}
	}

	else {
		White = false;
	}





	switch (num) {

	case 0:
		return 2;
		break;

	case 1:
		return 6;
		break;

	default:
		break;
	}

}

