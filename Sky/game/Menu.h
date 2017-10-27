#pragma once

#include "DxLib.h" //‚b’¼‰º“ˆê‚Å‚¨Šè‚¢@|ƒÖE`jÁ×¯
#include <math.h>
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"
#include "Graph.h"
#include "Music.h"
#include "Text.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>



class Menu
{
public:
	Menu();
	~Menu();
	int Win();


private:


	Text text;
	Music music;
	Graph graph;
	double angle;
	int button;
	int FontHandle;
	bool White;
	bool Savebu;


	int stageselect;
	int stagenum[4];
	double stageangle[4];
	double baseangle;
	int X, Y;
	int Rannum;
};

