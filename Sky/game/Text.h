#pragma once

#include "DxLib.h" //Ｃ直下統一でお願い　|ω・`）ﾁﾗｯ
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"
#include "Graph.h"
#include "Random.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static int date;
static char name[20];
static int dateline;

class Text
{
public:
	Text();
	~Text();
	int Tu();
	int Tu2();
	void Read(const std::string & fileName);
	void Come();
	void ComBox(bool exit);
	int Yamato();
	int Rie();
	int Kyoko();
	int Miame();
	void YLine();
	void RLine();
	void KLine();
	void MLine();
	void LineLoad();
	void DateLoad();
	void YamatoSabun();
	void RieSabun();
	void KyokoSabun();
	void MiameSabun();
	int Return();
	int Save(int select);
	int Load(int select);
	int Select(int GPass1,int GPass2);
	void Drawdate();

	std::vector<std::vector<std::string>> In;
	std::vector<std::string> SaveIn;
	std::vector<std::string> LoadIn;
	std::vector<std::string> WriteIn;
	//動的配列


private:



	Graph graph;
	Random Rand;


	int Capac;
	int mode;
	int kb;
	int kbmode;
	int FontHandle;
	int Rannum;
	bool NewLine;
	std::string str;


	int i,ii;
	int j, jj;
	int bar;
	int count;
	int line;
	int sabuny;
	int sabunr;
	int sabunk;
	int sabunm;
	int flag;
	int result;
	bool YFlag;
	bool RFlag;
	bool KFlag;
	bool MFlag;
	bool Sweet;

	bool right;
	bool decision;
	bool o;
	bool oo;
	bool miuo;
	int select[4];
	int selectNum;
	int Yresult;
	int Mresult;
	int Mresult2;
};

