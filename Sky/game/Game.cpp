#include "Game.h"



Game::Game()
{

	FontHandle = LoadFontDataToHandle("Font/マメロン.dft", 0);
	mode = 0;
	date = 1;
	i = 0;
	ii = 0;
	sabun = 0;
	line = 0;

}


Game::~Game()
{
}



void Game::Window() {




		switch (mode) {
	
	case 0:		
		mode = text.Tu();
		//チュートリアル
		break;

	case 1:	
		mode = text.Tu2();
		//チュートリアル2
		break;

	case 2:
		mode = menu.Win();
		//選択画面
		break;

	case 3:
		mode = sl.SaveForm(1);
		//セーブロード
		break;

	case 4:
		mode = text.Yamato();
		break;

	case 5:
		mode = text.Rie();
		break;

	case 6:
		mode = text.Kyoko();
		break;

	case 7:
		mode = text.Miame();
		break;

	case 8:
		mode = text.Return();
		break;

	default:
		break;
	
		}


			
		
}





	

