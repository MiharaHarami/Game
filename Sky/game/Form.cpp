#include <stdio.h>
#include "Form.h"


Form::Form()
{
	SetMainWindowText(CommonSettings::GAME_TITLE);//ウィンドウのタイトル
	Scene = 0;
}

Form::~Form()
{
}

bool Form::Update()
{ 

	switch (Scene) {
	
	case 0:
		Scene = title.title();
			break;

	case 1:
		return false;
		break;

	
	case 2:
		Scene = sl.SaveForm(0);
		//セーブ&ロード画面
		break;

	case 3:
		Scene = text.Tu();
		//チュートリアル
		break;

	case 4:
		Scene = text.Tu2();
		//チュートリアル2
		break;

	case 5:
		Scene = menu.Win();
		//選択画面
		break;

	case 6:
		Scene = sl.SaveForm(1);
		//セーブロード
		break;

	case 7:
		Scene = text.Yamato();
		break;

	case 8:
		Scene = text.Rie();
		break;

	case 9:
		Scene = text.Kyoko();
		break;

	case 10:
		Scene = text.Miame();
		break;

	case 11:
		Scene = text.Return();
		break;
	

	default:
		break;
	
	}
	

	return true;
}

