#pragma once

#include "DxLib.h" //�b��������ł��肢�@|�ցE`�j�ׯ
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"
#include "Graph.h"
#include "Music.h"


using namespace InputDevice;

class Title
{
public:
	Title();
	~Title();


	int title();
	Graph graph;
	Music music;


	int button;

private:
	int titleback;
	int font;
	int tx, adx;
};

