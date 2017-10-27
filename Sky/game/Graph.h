#pragma once
#include "DxLib.h" //Çbíºâ∫ìùàÍÇ≈Ç®äËÇ¢Å@|É÷ÅE`Åj¡◊Ø
#include "CommonSettings.h"
#include "InputDevice.h"
#include "ColorList.h"


using namespace CommonSettings;

class Graph
{
public:
	Graph();
	~Graph();

	void Title();
	void Circle(int x,int y,bool right);
	void MenuCircle(int x, int y,double num);
	void Back(int mode);
	void Save(bool sl,bool select);
	void Menu(bool select);
	void SkyBack(int date,int charanum);
	void Yamato(int sabun);
	void Rie(int sabun);
	void Kyoko(int sabun);
	void Miame(int sabun);


private:
	int titleback;
	int circle[3];
	int snow;
	int titleico;
	double num;

	int back[10];
	int saveback[3];
	int noise;
	int bar[2];
	int UIMe[2];

	int savebar;

	int window;
	int next;
	int Yback[3];
	int Rback[3];
	int Kback[3];
	int Mback[3];
	int Skyback[10];
	int yamato[30];
	int rie[30];
	int kyoko[30];
	int miame[30];
	
};

