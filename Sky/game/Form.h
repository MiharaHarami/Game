#pragma once

#include "DxLib.h" //Çbíºâ∫ìùàÍÇ≈Ç®äËÇ¢Å@|É÷ÅE`Åj¡◊Ø
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"
#include "Title.h"
#include "Music.h"
#include "Menu.h"
#include "Game.h"
#include "SaveLoad.h"
#include "Text.h"
#include "Graph.h"


class Form
{
public:
	Form();
	~Form();

	bool Update();
	Title title;
	Game game;
	SaveLoad sl;
	Menu menu;
	Text text;
	Graph graph;

private:

	int Scene;

	int FontHandle;
	int mode;
	int count;
	int sabun;
	int date;

	int i, ii;
	int line;

};
//---------------------------------------------------------------------------