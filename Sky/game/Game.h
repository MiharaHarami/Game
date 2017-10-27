#pragma once
#include "DxLib.h" //�b��������ł��肢�@|�ցE`�j�ׯ
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"
#include "Text.h"
#include "Menu.h"

#include "SaveLoad.h"
#include "Graph.h"

using namespace InputDevice;

class Game
{
public:
	Game();
	~Game();


	void Window();
	


private:


	SaveLoad sl;
	Text text;
	Menu menu;
	Graph graph;
	int FontHandle;
	int mode;
	int count;
	int sabun;
	int date;

	int i, ii;
	int line;
};

