#pragma warning(disable:4996)
#include "Text.h"



Text::Text()
{
	select[0] = LoadGraph("Img/select_yes.png");
	select[1] = LoadGraph("Img/select_no.png");
	select[2] = LoadGraph("Img/select_summer.png");
	select[3] = LoadGraph("Img/select_winter.png");
	FontHandle = LoadFontDataToHandle("Font/マメロン.dft", 0);
	kbmode = 1;
	NewLine = false;
	line = 0;
	i = 0;
	ii = 0;
	Read("Txt/ひとこと.txt");
	j = 0;
	jj = 0;
	//Capac = In[].capacity();
	Rannum = 0;
	bar = LoadGraph("Img/bar.png");
	count = 0;
	date = 1;
	sabuny = 1;
	sabunr = 1;
	sabunk = 1;
	sabunm = 1;

	flag = false;
	YFlag = false;
	RFlag = false;
	KFlag = false;
	MFlag = false;

	decision = false;
	right = false;
	o = false;
	oo = false;
	miuo = false;
	Yresult = 0;
	Mresult = 0;
	Mresult2 = 0;
}


Text::~Text()
{
}


void Text::Read(const std::string & fileName)
{
	if (In.empty() == false) {
		In.clear();
	}

	std::ifstream ifs(fileName);
	//ファイルをオープンしてifsに入れる

	In.push_back(std::vector<std::string>());



	std::string from = "$主人公$";
	std::string s_name(name);





	while (getline(ifs, str))
{	//getlineは指定文字リテラルで文字を分割することもできます。3つめの引数にカンマなどの文字を指定することで可能
		std::string::size_type pos = str.find(from);

		while (pos != std::string::npos) {
			str.replace(pos, from.size(), s_name);
			pos = str.find(from, pos + s_name.size());

			}
		std::cout << str << std::endl;


	if (str.empty()) {
		In.push_back(std::vector<std::string>());
		//行が空のとき、次の配列の箱(の中の箱)を作っている
	}
	else {
		In.back().push_back(str);
		//最後尾(back)に入れる(push_back)
	}


}

}

void Text::Come() {
	ComBox(false);
	Capac = In[Rannum].capacity();
	DrawExtendGraph(0, 540, 600, 570 + jj * 23, bar, true);
	int size;
	for (jj = 0; jj < Capac; jj++) {
		size = GetDrawStringWidthToHandle(In[Rannum][jj].c_str(), In[Rannum][jj].size(), FontHandle);
		DrawFormatStringToHandle((600 - size) / 2, 570 + jj * 20, GetColor(255, 255, 255), FontHandle, "%s", In[Rannum][jj].c_str());
	}

}

void Text::ComBox(bool exit) 
{
	if (exit == true) {
		count = 0;
	}

	else if (count == 0) {
		Rannum = Rand.Generate(0, 68);
		count++;
	}

}


int Text::Tu() {

	graph.Back(0);

			switch (kbmode) {

				case 1:
					kb = MakeKeyInput(14, false, false, false);
					SetKeyInputString("あなた", kb);
					kbmode = 2;
					break;

				case 2:
					//DrawKeyInputModeString(1000,700);
					DrawKeyInputString(20, 400, kb);
					SetActiveKeyInput(kb);
					kbmode = 3;
					break;

				case 3:
					DrawFormatStringToHandle(20, 380,  GetColor(255, 255, 255), FontHandle, "あなたの名前↓");
					DrawKeyInputString(20, 405, kb);
					if (CheckKeyInput(kb) != 0) {
						kbmode = 4;
					}
					break;

				case 4:
					GetKeyInputString(name, kb);
					DeleteKeyInput(kb);
					kbmode = 5;
					break;

				case 5:
					DrawFormatStringToHandle(20, 380, GetColor(255, 255, 255), FontHandle, "あなたの名前は%sですか", name);
					DrawFormatStringToHandle(20, 400, GetColor(255, 255, 255), FontHandle, "よろしければエンターを押してください");
					DrawFormatStringToHandle(20, 420, GetColor(255, 255, 255), FontHandle, "やり直したければF1を押してください");
					if (keyInput.GetIsUpdate(KEY_INPUT_F1) == 1) {
						kbmode = 1;
					}
					if (keyInput.GetIsUpdate(KEY_INPUT_RETURN)==1) {
						std::ofstream ofs("Txt/data.txt");
						ofs << name;
						kbmode = 6;
					}
					break;

				case 6:
					return 4;
					break;

				default:
					return 4;
					break;
				}
			
			return 3;


}

int Text::Tu2()
{
	Read("Txt/tutorial.txt");
	int Capa;
	Capa = In[i].size();

	graph.Back(0);

	if (i == 3) {
		NewLine = true;
	}

	if (NewLine == true) {
		i = 0;
		ii = 0;
		return 5;
	}



			for (ii = 0; ii < Capa ; ii++) {
				if (In[i][ii].c_str() != NULL) {
				DrawFormatStringToHandle(20, 380 + ii * 20, GetColor(255, 255, 255), FontHandle, "%s", In[i][ii].c_str());
				}
			}

			if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)|| keyInput.GetIsUpdate(KEY_INPUT_Z)) {
				i++;
				ii = 0;
			}

	return 4;
}


int Text::Yamato()
{


	if (flag == false) {
		YLine();
		LineLoad();
		Read("Txt/3.txt");
		flag = true;
	}



	int Capa;
	Capa = In[line].size();
	YamatoSabun();
	graph.SkyBack(date, 0);
	graph.Yamato(sabuny);
	for (ii = 0; ii < Capa; ii++) {
		if (In[line][ii].c_str() != NULL) {
			DrawFormatStringToHandle(20, 380 + ii * 20, GetColor(255, 255, 255), FontHandle, "%s", In[line][ii].c_str());
		}
	}

	DrawFormatStringToHandle(550, 5, GetColor(255, 255, 255), FontHandle, "%d日目", date);

	if (line != 151) {
	

		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
			line++;
			ii = 0;
		}
		if (keyInput.GetPressFrame(KEY_INPUT_C)) {
			line++;
			ii = 0;
		}
	
	}

	DrawFormatStringToHandle(20, 10, GetColor(255, 255, 255), FontHandle, "%d", line);
	DrawFormatStringToHandle(20, 22, GetColor(255, 255, 255), FontHandle, "%d", ii);

	switch (date) {
	case 1:
		if (line == 9) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;


	case 2:
		if (line == 30) {
			i = 0;
			ii = 0;
			return 11;
		}
		
		break;

	case 3:
		if (line == 42) {
		i = 0;
		ii = 0;
		RFlag = true;
		return 11;
	}
		break;

	case 4:
		if (line == 60) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 5:
		if (line == 81) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;


	case 6:
		if (YFlag == true && line == 97) {
			i = 0;
			ii = 0;
			return 11;
		}

		else if (YFlag == false && line == 114) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 7:
		if (line == 131) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 8:
		if (line == 144) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 9:

		if (line == 151) {
			Yresult = Select(select[2], select[3]);
			Select(select[2], select[3]);
		}
		if (o == false){
			if (Yresult == -1){
				line = 152;
				ii = 0;
				o = true;
			}
			else if (Yresult == 1){
				line = 160;
				ii = 0;
				o = true;
			
			}
		}
		if (Yresult == -1 && line == 160) {
			i = 0;
			ii = 0;
			selectNum = 0;
			return 11;
		}
		if (Yresult == 1 && line == 174) {
			i = 0;
			ii = 0;
			selectNum = 0;
			return 11;
		}
		break;
	}
	return 7;

}

int Text::Rie() 
{
	if (flag == false) {
		RLine();
		LineLoad();
		Read("Txt/4.txt");
		flag = true;
	}


	int Capa;
	Capa = In[line].size();
	RieSabun();
	graph.SkyBack(date, 1);
	graph.Rie(sabunr);
	for (ii = 0; ii < Capa; ii++) {
		if (In[line][ii].c_str() != NULL) {
			DrawFormatStringToHandle(20, 380 + ii * 20, GetColor(255, 255, 255), FontHandle, "%s", In[line][ii].c_str());
		}
	}

	DrawFormatStringToHandle(550, 5, GetColor(255, 255, 255), FontHandle, "%d日目", date);
	DrawFormatStringToHandle(20, 10, GetColor(255, 255, 255), FontHandle, "%d", line);
	if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
		line++;
		ii = 0;
	}
	if (keyInput.GetPressFrame(KEY_INPUT_C)) {
		line++;
		ii = 0;
	}

	
	switch (date) {
	case 1:
		if (line == 16) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;


	case 2:
		if (line == 31) {
			i = 0;
			ii = 0;
			return 11;
		}

		break;

	case 3:
		if (line == 59) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 4:
		if (RFlag == true&& line == 81) {
			i = 0;
			ii = 0;
			return 11;
		}
			if (RFlag == false && line == 106) {
				i = 0;
				ii = 0;
				return 11;
		}
		break;

	case 5:
		if (line == 119) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;


	case 6:
		if (line == 144) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 7:
		if (line == 156) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 8:
		if (line == 180) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 9:
		if (line == 202) {
		i = 0;
		ii = 0;
		return 11;
		}
		break;
	}
	


	return 8;
}

int Text::Kyoko() 
{
	if (flag == false) {
		KLine();
		LineLoad();
		Read("Txt/5.txt");
		flag = true;
	}
	int Capa;
	Capa = In[line].size();
	KyokoSabun();
	graph.SkyBack(date, 2);
	graph.Kyoko(sabunk);
	for (ii = 0; ii < Capa; ii++) {
		if (In[line][ii].c_str() != NULL) {
			DrawFormatStringToHandle(20, 380 + ii * 20, GetColor(255, 255, 255), FontHandle, "%s", In[line][ii].c_str());
		}
	}

	DrawFormatStringToHandle(550, 5, GetColor(255, 255, 255), FontHandle, "%d日目", date);
	DrawFormatStringToHandle(20, 10, GetColor(255, 255, 255), FontHandle, "%d", line);
	if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
		line++;
		ii = 0;
	}
	if (keyInput.GetPressFrame(KEY_INPUT_C)) {
		line++;
		ii = 0;
	}


	
	switch (date) {
	case 1:
	if (line == 17) {
	i = 0;
	ii = 0;
	return 11;
	}
	break;


	case 2:
	if (line == 37) {
	i = 0;
	ii = 0;
	return 11;
	}

	break;

	case 3:
	if (line == 71) {
	i = 0;
	ii = 0;
	KFlag = true;
	return 11;
	}
	break;

	case 4:
	if (line == 90) {
	i = 0;
	ii = 0;
	KFlag = true;
	return 11;
	}
	break;

	case 5:
	if (line == 104) {
	i = 0;
	ii = 0;
	return 11;
	}
	break;


	case 6:
		if (KFlag == true && line == 119) {
			i = 0;
			ii = 0;
			return 11;
		}
		else if (KFlag == false && line == 138) {
		i = 0;
		ii = 0;
		return 11;
		}
	break;

	case 7:
	if (line == 169) {
	i = 0;
	ii = 0;
	return 11;
	}
	break;

	case 8:
	if (line == 182) {
	i = 0;
	ii = 0;
	return 11;
	}
	break;

	case 9:
	if (line == 213) {
	i = 0;
	ii = 0;
	return 11;
	}
	break;
	}
	

	return 9;
}

int Text::Miame()
{
	if (flag == false) {
		MLine();
		LineLoad();
		Read("Txt/6.txt");
		flag = true;
	}
	int Capa;
	Capa = In[line].size();
	MiameSabun();
	graph.SkyBack(date, 3);
	graph.Miame(sabunm);
	for (ii = 0; ii < Capa; ii++) {
		if (In[line][ii].c_str() != NULL) {
			DrawFormatStringToHandle(20, 380 + ii * 20, GetColor(255, 255, 255), FontHandle, "%s", In[line][ii].c_str());
		}
	}

	DrawFormatStringToHandle(550, 5, GetColor(255, 255, 255), FontHandle, "%d日目", date);
	DrawFormatStringToHandle(20, 10, GetColor(255, 255, 255), FontHandle, "%d", line);

	if (line != 5 && line != 27) {

		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
			line++;
			ii = 0;
		}
		if (keyInput.GetPressFrame(KEY_INPUT_C)) {
			line++;
			ii = 0;
		}
	}

	switch (date) {
	case 1:


		if (line == 5) {
			Mresult = Select(select[0], select[1]);
			Select(select[0], select[1]);
		}
		if (oo == false) {
			if (Mresult == -1) {
				line = 6;
				ii = 0;
				oo = true;
			}
			else if (Mresult == 1) {
				line = 11;
				ii = 0;
				oo = true;
			}
		}

			if (Mresult == -1 && line == 11) {
				i = 0;
				ii = 0;
				selectNum = 0;
				return 11;
			}
			if (Mresult == 1 && line == 19) {
				i = 0;
				ii = 0;
				selectNum = 0;
				return 11;
			}

		break;


	case 2:
		if (line == 27) {
			Mresult2 = Select(select[0], select[1]);
			Select(select[0], select[1]);
		}
		if (miuo == false) {
			if (Mresult2 == -1) {
				line = 28;
				ii = 0;
				miuo = true;
			}
			else if (Mresult2 == 1) {
				line = 32;
				ii = 0;
				miuo = true;
			}
			else {
			
			}
		}

		if (Mresult2 == -1 && line == 32) {
			i = 0;
			ii = 0;
			MFlag = true;
			Sweet = true;
			selectNum = 0;
			return 11;
		}
		if (Mresult2 == 1 && line == 37) {
			i = 0;
			ii = 0;
			MFlag = true;
			Sweet = false;
			selectNum = 0;
			return 11;
		}
	
		break;

	case 3:
		if (line == 54) {
			i = 0;
			ii = 0;
			YFlag = true;
			return 11;
		}
		break;

	case 4:
		if (line == 74) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 5:
		if (line == 98) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;


	case 6:
		if (line == 132) {
			i = 0;
			ii = 0;
			return 11;
		}
		
		break;

	case 7:
		if (MFlag == true && line == 147) {
			i = 0;
			ii = 0;
			return 11;
		}

		else if (MFlag == false && line == 172) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 8:
		if (line == 192) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;

	case 9:
		if (line == 215) {
			i = 0;
			ii = 0;
			return 11;
		}
		break;
	}

	return 10;
}

void Text::YLine() 
{

	//std::ofstream ofs("Txt/data.txt");
	//DateLoad();
	
	switch (date) {

	case 1:
		dateline = 0;
		break;


	case 2:
		dateline = 10;
		break;


	case 3:
		dateline = 30;
		break;

	case 4:
		dateline = 42;
		break;

	case 5:
		dateline = 60;
		break;

	case 6:
		if (YFlag == true) {
			dateline = 81;
		}
		else {
			dateline = 97;
		
		}
		break;

	case 7:
		dateline = 114;
		break;

	case 8:
		dateline = 131;
		break;

	case 9:
		dateline = 144;
		break;

	default:
		break;

	}

	

}


void Text::RLine()
{
	


	switch (date) {


		case 1:
			dateline = 0;
		break;


	case 2:
		dateline = 16;
		break;


	case 3:
		dateline = 31;
		break;

	case 4:
		if (RFlag == true) {
		dateline = 59;
		}
		else {
			dateline = 81;
		}
		break;

	case 5:
		dateline = 106;
		break;

	case 6:
		dateline = 119;

		break;

	case 7:
		dateline = 144;
		break;

	case 8:
		dateline = 156;
		break;

	case 9:
		dateline = 180;
		break;

	default:
		break;

	}
		



}

void Text::KLine()
{


	switch (date) {
	case 1:
		dateline = 0;
		break;

	case 2:
		dateline = 17;
		break;


	case 3:
		dateline = 37;
		break;

	case 4:
		dateline = 71;
		break;

	case 5:
		dateline = 90;
		break;

	case 6:
		if (KFlag == true) {
		dateline = 104;
	}
		else if (KFlag == false) {
			dateline = 119;
		}
		break;


	case 7:
			dateline = 138;
		break;

	case 8:
		dateline = 169;
		break;

	case 9:
		dateline = 182;
		break;

	case 10:
		dateline = 216;
		break;

	default:
		break;
	}

}

void Text::MLine()
{
	switch (date) {
	case 1:
		dateline = 0;
		break;

	case 2:
		dateline = 19;
		break;


	case 3:
		dateline = 37;
		break;

	case 4:
		dateline = 54;
		break;

	case 5:
		dateline = 74;
		break;

	case 6:
		dateline = 98;
		break;


	case 7:
		if (MFlag == true) {
			dateline = 132;
		}
		else if (MFlag == false) {
			dateline = 147;
		}
		break;

	case 8:
		dateline = 172;
		break;

	case 9:
		dateline = 192;
		break;

	case 10:
		dateline = 215;
		break;

	default:
		break;
	}
}
void Text::LineLoad()
{

	line = dateline;

	
}
void Text::DateLoad()
{


	
		std::ifstream ifs("Txt/date.txt");
	std::string str;
	getline(ifs, str);
	date = std::stoi(str);
	


}

void Text::YamatoSabun()
{
	switch (date) {


	case 1:
		if (line == 6 || line == 8) {
			sabuny = 1;
		}
		else if (line == 9) {
			sabuny = -1;
		}
		else {
			sabuny = 0;
		}
		break;


	case 2:
		if (line == 12 || line == 13) {
			sabuny = 4;
		}

		else if (line >= 20 && line <= 23 || line == 29) {
			sabuny = 5;
		}

		else if (line == 31) {
			sabuny = -1;
		}

		else {
			sabuny = 3;
		}
		break;

	case 3:

		if (line >= 36 && line <=39) {
			sabuny = 13;
		}

		else {
			sabuny = 14;
		}
		break;


	case 4:
		if (line >= 54 && line <= 57) {
			sabuny = 12;
		}

		else if (line >= 58 && line <= 60) {
			sabuny = 11;
		}

		else if (line == 61) {
			sabuny = -1;
		}

		else {
			sabuny = 15;
		}
		break;

	case 5:
		if (line >= 67 && line <= 76) {
			sabuny = 12;
		}

		else if (line >= 79 && line <= 80) {
			sabuny = 11;
		}

		else if (line == 81) {
			sabuny = -1;
		}

		else if (line == 60 && line == 61) {
			sabuny = 6;
		}

		else {
			sabuny = 2;
		}
		break;

	case 6:

		if (YFlag == true) {
		
			if (line >= 81 && line <= 82 || line == 93 || line == 94) {
				sabuny = 7;
			}

			else if (line >= 89 && line <= 90 || line == 96) {
				sabuny = 9;
			}

			else if (line == 92) {
				sabuny = 10;
			}

			else if (line == 97) {
				sabuny = -1;
			}

			else {
				sabuny = 7;
			}
			
		
		}

		if (YFlag == false) {
			if (line >= 106 && line <= 108 || line >= 112 && line <= 113) {
				sabuny = 14;
			}

			else if (line == 114) {
				sabuny = -1;
			}

			else {
				sabuny = 15;
			}


		}
			break;


	case 7:
		if (line >= 114 && line <= 116) {
			sabuny = 16;
		}

		else if (line >= 117 && line <= 124) {
			sabuny = 17;
		}
		else if (line >= 125 && line <= 126) {
			sabuny = 18;
		}
		else if (line >= 127 && line <= 129) {
			sabuny = 11;
		}
		else if (line == 130) {
			sabuny = 2;
		}
		else if (line == 131) {
			sabuny = -1;
		}

		else if (line == 60 && line == 61) {
			sabuny = 6;
		}

		else {
			sabuny = 0;
		}
		break;

	case 8:
		if (line >= 139 && line <= 143) {
			sabuny = 13;
		}
		else if (line == 144) {
			sabuny = -1;
		}
		else {
			sabuny = 13;
		}
		break;

	case 9:
		if (line >= 144 && line <= 145) {
			sabuny = 19;
		}
		else if (line >= 146 && line <= 151) {
			sabuny = 0;
		}
		else if (line >= 158 && line <= 159) {
			sabuny = 11;
		}
		else if (line >= 163 && line <= 165) {
			sabuny = 20;
		}
		else if (line >= 166 && line <= 170) {
			sabuny = 21;
		}
		else if (line >= 171 && line <= 173) {
			sabuny = 12;
		}
		else if (line == 144) {
			sabuny = -1;
		}
		else {
			sabuny = 2;
		}
		break;

	default:
		break;



	}



}

void Text::RieSabun()
{
	switch (date) {


	case 1:
		if (line >= 7 && line <= 9) {
			sabunr = 7;
		}
		else if (line >= 10 && line <= 12) {
			sabunr = 8;
		}

		else if (line >= 13 && line <= 15) {
			sabunr = 9;
		}
		else if (line == 5) {
			sabunr = 1;
		}
		else if (line == 9) {
			sabunr = -1;
		}
		else {
			sabunr = 0;
		}
		break;


	case 2:


		if (line >= 20 && line <= 23 || line == 29 && line <= 30) {
			sabunr = 13;
		}

		else if (line == 31) {
			sabunr = -1;
		}

		else {
			sabunr = 12;
		}
		break;

	case 3:
		if (line == 31 || line == 32) {
			sabunr = 1;
		}

		else if (line >= 35 && line <= 38) {
			sabunr = 2;
		}
		else if (line >= 39 && line <= 44 || line == 51) {
			sabunr = 3;
		}
		else if (line == 59) {
			sabunr = -1;
		}

		else {
			sabunr = 4;
		}
		break;

		case 4:
			if (RFlag == true) {
				if (line >= 59 && line <= 64) {
					sabunr = 1;
				}
				else if (line >= 65 && line <= 67) {
					sabunr = 5;
				}
				else if (line >= 69 && line <= 76) {
					sabunr = 10;
				}
				else if (line >= 77 && line <= 80) {
					sabunr = 11;
				}
				else if (line == 81) {
				sabunr = -1;
				}			
			}
			else if (RFlag == false) {
				if (line >= 101 && line <= 105) {
					sabunr = 13;
				}
				else if (line == 106) {
					sabunr = -1;
				}
				else {
					sabunr = 12;
				}
			
			}
		break;


		case 5:
			if (line >= 116 && line <= 118) {
				sabunr = 0;
			}
			else if (line == 119) {
				sabunr = -1;
			}
			else {
				sabunr = 1;
			}
			break;

		case 6:
			if (line >= 127 && line <= 132) {
				sabunr = 12;
			}

			else if (line >= 133 && line <= 139) {
				sabunr = 15;
			}
			else if (line == 144) {
				sabunr = -1;
			}
			else {
				sabunr = 14;
			}
			break;

		case 7:
			if (line >= 144 && line <= 148) {
				sabunr = 12;
			}
			else if (line == 156) {
				sabunr = -1;
			}
			else {
				sabunr = 13;
			}
			break;

		case 8:
			if (line >= 157 && line <= 159) {
				sabunr = 11;
			}
			else if (line >= 170 && line <= 174) {
				sabunr = 17;
			}
			else if (line >= 175 && line <= 179) {
				sabunr = 16;
			}
			else if (line == 180) {
				sabunr = -1;
			}
			else {
				sabunr = 10;
			}
			break;

		case 9:
			if (line >= 180 && line <= 183) {
				sabunr = 19;
			}
			else if (line >= 199 && line <= 201) {
				sabunr = 20;
			}
			else if (line == 180) {
				sabunr = -1;
			}
			else {
				sabunr = 18;
			}
			break;


	default:
		break;



	}



}


void Text::KyokoSabun()
{
	switch (date) {


	case 1:
		if (line == 16) {
			sabunk = 1;
		}
		else if (line == 17) {
			sabunk = -1;
		}
		else {
			sabunk = 0;
		}
		break;


	case 2:
		if (line >= 31 && line <= 34) {
			sabunk = 2;
		}

		else if (line >= 35 && line <= 36 ) {
			sabunk = 3;
		}

		else if (line == 37) {
			sabunk = -1;
		}

		else {
			sabunk = 0;
		}
		break;

	case 3:
		if (line == 45 && line == 52) {
			sabunk = 3;
		}

		else if (line >= 54 && line <= 57) {
			sabunk = 4;
		}

		else if (line >= 58 && line <= 63) {
			sabunk = 5;
		}

		else if (line >= 64 && line <= 67) {
			sabunk = 6;
		}

		else if (line >= 68 && line <= 70) {
			sabunk = 7;
		}

		else if (line == 71) {
			sabunk = -1;
		}

		else {
			sabunk = 0;
		}
		break;


	case 4:
		if (line >= 71 && line <= 73) {
			sabunk = 8;
		}

		else if (line >= 76 && line <= 82) {
			sabunk = 9;
		}

		else if (line == 90) {
			sabunk = -1;
		}

		else {
			sabunk = 0;
		}
		break;

	case 5:
		if (line >= 90 && line <= 100) {
			sabunk = 0;
		}


		else if (line == 104) {
			sabunk = -1;
		}

		else {
			sabunk = 10;
		}
		break;

	case 6:
		if (KFlag == true) {
			if (line >= 104 && line <= 109) {
				sabunk = 11;
			}
			else if (line == 119) {
				sabunk = -1;
			}
			else {
				sabunk = 12;
			}
			
		}
		else if (KFlag == false) {
			if (line >= 130 && line <= 137) {
				sabunk = 10;
			}
			else if (line == 138) {
				sabunk = -1;
			}
			else {
				sabunk = 0;
			}
		}
		break;


	case 7:
		if (line >= 138 && line <= 141) {
			sabunk = 13;
		}

		else if (line >= 142 && line <= 145) {
			sabunk = 14;
		}

		else if (line >= 165 && line <= 167) {
			sabunk = 18;
		}
		else if (line >= 168) {
			sabunk = 10;
		}
		else if (line == 169) {
			sabunk = -1;
		}

		else {
			sabunk = 15;
		}
		break;

	case 8:
		if (line >= 180 && line <= 181) {
			sabunk = 17;
		}

		else if (line == 182) {
			sabunk = -1;
		}

		else {
			sabunk = 16;
		}
		break;

	case 9:
		if (line == 182) {
			sabunk = 18;
		}

		else if (line >= 183 && line <= 184) {
			sabunk = 19;
		}

		else if (line == 213) {
			sabunk = -1;
		}

		else {
			sabunk = 20;
		}
		break;

	default:
		break;



	}



}

void Text::MiameSabun()
{
	switch (date) {


	case 1:
		if (Mresult == -1 && line == 11) {
			sabunm = -1;
		}
		if (Mresult == 1 && line == 19) {
			sabunm = -1;
		}
		else if (line >= 6 && line <= 10) {
			sabunm = 1;
		}
		else if (line >= 11 && line <= 10) {
			sabunm = 1;
		}
		else if (line == 5) {
			sabunm = 2;
		}
		else {
			sabunm = 0;
		}
		break;


	case 2:
		if (line >= 19 && line <= 22) {
			sabunm = 8;
		}
		if (line == 23) {
			sabunm = 12;
		}

		else if (line >= 24 && line <= 27) {
			sabunm = 9;
		}

		else if (line >= 28 && line <= 30) {
			sabunm = 13;
		}

		else if (line >= 31 && line <= 33) {
			sabunm = 10;
		}

		else if (line >= 34 && line <= 36) {
			sabunm = 11;
		}
		else if (Mresult2 == -1 && line == 32) {
			sabunm = -1;
		}
		else if (Mresult2 == 1 && line == 37) {
			sabunm = -1;
		}

		else {
			sabunm = 8;
		}
		break;

	case 3:
		if (line == 51 || line == 53) {
			sabunm = 4;
		}

		else if (line == 54) {
			sabunm = -1;
		}

		else {
			sabunm = 3;
		}
		break;


	case 4:
		if (line >= 54 && line <= 57) {
			sabunm = 6;
		}
		else if (line >= 69 && line <= 70) {
			sabunm = 15;
		}


		else if (line >= 71 && line <= 73) {
			sabunm = 17;
		}

		else if (line >= 60 && line <= 63|| line >= 65 && line <= 66) {
			sabunm = 14;
		}
		else if (line == 67) {
			sabunm = 16;
		}
		else if (line == 74) {
			sabunm = -1;
		}

		else {
			sabunm = 15;
		}
		break;

	case 5:
		if (line >= 77 && line <= 79) {
			sabunm = 5;
		}
		else if (line >= 85 && line <= 87) {
			sabunm = 1;
		}

		else if (line >= 88 && line <= 94) {
			sabunm = 0;
		}
		else if (line >= 95 && line <= 97) {
			sabunm = 2;
		}
		else if (line == 98) {
			sabunm = -1;
		}

		else {
			sabunm = 7;
		}
		break;

	case 6:
		if (line >= 98 && line <= 100) {
			sabunm = 18;
		}
		else if (line >= 124 && line <= 126) {
			sabunm = 20;
		}

		else if (line == 127) {
			sabunm = 21;
		}
		else if (line == 113) {
			sabunm = 22;
		}
		else if (line == 132) {
			sabunm = -1;
		}

		else {
			sabunm = 19;
		}
		break;

	case 7:
		if (MFlag == true) {
			if (line >= 132 && line <= 134) {
				sabunm = 23;
			}
			else if (line >= 135 && line <= 140) {
				sabunm = 24;
			}

			else if (line == 146) {
				sabunm = 2;
			}
			else if (line == 147) {
				sabunm = -1;
			}

			else {
				sabunm = 0;
			}
		}

		else if (MFlag == false) {
			if (line >= 132 && line <= 134) {
				sabunm = 23;
			}
			else if (line >= 135 && line <= 140) {
				sabunm = 24;
			}

			else if (line == 146) {
				sabunm = 2;
			}
			else if (line == 147) {
				sabunm = -1;
			}

			else {
				sabunm = 0;
			}
		}
		break;

	default:
		break;



	}



}

int Text::Return()
{

	Read("Txt/system.txt");
	int Capa;
	Capa = In[i].size();
	graph.Back(1);


	for (ii = 0; ii < Capa; ii++) {
		if (In[i][ii].c_str() != NULL) {
			DrawFormatStringToHandle(20, 380 + ii * 20, GetColor(255, 255, 255), FontHandle, "%s",In[i][ii].c_str());
		}
	}

	if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
		i++;
		ii = 0;
	}

	if (i == 2) {
		DrawFormatStringToHandle(20, 670, GetColor(255, 255, 255), FontHandle, "Next……");
	}
	if (i == 3) {
		i = 0;
		ii = 0;
		date++;
		//std::ofstream ofs("Txt/date.txt");
		//ofs << date;
		flag = false;
		return 5;
	}


	return 11;
}

int Text::Save(int select)
{
	using namespace std;
	std::string str1("Save");
	std::string str2(std::to_string(select));
	std::string str3(".txt");
	std::string filename = str1 + str2 + str3;

	std::ofstream ofs(filename);

	ofs << name << ',' << date << ',' << YFlag << ',' << RFlag << ',' << KFlag << ',' << MFlag;
	return true;

}

int Text::Load(int select)
{
	using namespace std;

	struct stat buf;


	std::string str1("Save");
	std::string str2(std::to_string(select));
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
		for (int s = 0; s< 20; s++) {
			char c = LoadIn[0].c_str()[s];
			if (c != NULL) {
				name[s] = LoadIn[0].c_str()[s];
			}
		}
		date = std::stoi(LoadIn[1].c_str());
		YFlag = std::stoi(LoadIn[2].c_str());
		RFlag = std::stoi(LoadIn[3].c_str());
		KFlag = std::stoi(LoadIn[4].c_str());
		MFlag = std::stoi(LoadIn[5].c_str());
		return 1;
	}
	else {

		// ファイルが存在しない

		
		return -1;
	}

	
	return 0;


}

int Text::Select(int GPass1, int GPass2)
{

		if (keyInput.GetIsUpdate(KEY_INPUT_RIGHT)) {
			selectNum = 1;
		}

		else if (keyInput.GetIsUpdate(KEY_INPUT_LEFT)) {
			selectNum = -1;
		}
		

	switch (selectNum) {
	
	
	case 0:

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DrawGraph(50, 500, GPass1, true);
		DrawGraph(380, 500, GPass2, true);
		break;


	case 1:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);
		DrawGraph(50, 500, GPass1, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DrawGraph(380, 500, GPass2, true);
		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
			return 1;
		}
		break;


	case -1:
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		DrawGraph(50, 500, GPass1, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);
		DrawGraph(380, 500, GPass2, true);
		if (keyInput.GetIsUpdate(KEY_INPUT_RETURN) || keyInput.GetIsUpdate(KEY_INPUT_Z) || keyInput.GetIsUpdate(KEY_INPUT_SPACE)) {
			return -1;
		}
		break;

	default:
		break;
	
	
	
	}



	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	return 0;
}

void Text::Drawdate()
{

	DrawFormatStringToHandle(550, 5, GetColor(255, 255, 255), FontHandle, "%d日目", date);

}