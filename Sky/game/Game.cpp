#include "Game.h"



Game::Game()
{

	FontHandle = LoadFontDataToHandle("Font/�}������.dft", 0);
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
		//�`���[�g���A��
		break;

	case 1:	
		mode = text.Tu2();
		//�`���[�g���A��2
		break;

	case 2:
		mode = menu.Win();
		//�I�����
		break;

	case 3:
		mode = sl.SaveForm(1);
		//�Z�[�u���[�h
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





	

