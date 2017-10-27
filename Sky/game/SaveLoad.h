#pragma once
#include "DxLib.h" //Çbíºâ∫ìùàÍÇ≈Ç®äËÇ¢Å@|É÷ÅE`Åj¡◊Ø
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"
#include "Graph.h"
#include "Text.h"
#include "Music.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class SaveLoad
{
public:
	SaveLoad();
	~SaveLoad();

	void Save();
	void Load();
	void SaveWin(int num);
	int SaveForm(int num);

private:
	int SaveNum;
	bool Sswitch;
	bool White;
	int X, Y;
	bool Savebu;
	int numb;
	int FontHandle;
	int LoadFlag;
	int ico;

	int date[4];
	std::vector<std::string> LoadIn;
	Graph graph;
	Text text;
};

