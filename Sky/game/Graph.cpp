#include "Graph.h"



Graph::Graph()
{
	titleback = LoadGraph("Img/タイトル案.png");

	circle[0] = LoadGraph("Img/circle.png");
	circle[1] = LoadGraph("Img/circle2.png");
	circle[2] = LoadGraph("Img/circle3.png");
	snow = LoadGraph("Img/nc586.mpg");
	GraphFilter(snow, DX_GRAPH_FILTER_GAUSS, 16,50);
	GraphFilter(circle[0], DX_GRAPH_FILTER_GAUSS, 8, 50);
	GraphFilter(circle[1], DX_GRAPH_FILTER_GAUSS, 8, 50);
	GraphFilter(circle[2], DX_GRAPH_FILTER_GAUSS, 8, 50);

	

	num = 0;
	back[0] = LoadGraph("Img/sky_00253.png");

	window = LoadGraph("Img/window.png");

	saveback[0] = LoadGraph("Img/Save.png");
	saveback[1] = LoadGraph("Img/Load.png");
	saveback[2] = LoadGraph("Img/SaveWi.png");

	noise = LoadGraph("Img/noi.png");

	savebar = LoadGraph("Img/Savebar.png");

	bar[0] = LoadGraph("Img/bar.png");
	UIMe[0] = LoadGraph("Img/SAVELOAD.png");
	UIMe[1] = LoadGraph("Img/Back.png");

	next = LoadGraph("Img/next.png");

	Skyback[0] = LoadGraph("Img/sky_00405.png");
	Skyback[1] = LoadGraph("Img/sky_00219.jpg");
	Skyback[2] = LoadGraph("Img/sky_00417.png");
	Skyback[3] = LoadGraph("Img/sky_00245.jpg");
	Skyback[4] = LoadGraph("Img/sky_00389.png");
	Skyback[5] = LoadGraph("Img/DSC_0007.JPG");
	Skyback[6] = LoadGraph("Img/sky_00120.png");
	Skyback[7] = LoadGraph("Img/sky_00351.png");
	Skyback[8] = LoadGraph("Img/sky_00120.png");

	Yback[0] = LoadGraph("Img/yamato_back.png");


	yamato[0] = LoadGraph("Img/yamato0.png");
	yamato[1] = LoadGraph("Img/yamato1.png");
	yamato[2] = LoadGraph("Img/yamato2.png");
	yamato[3] = LoadGraph("Img/yamato3.png");
	yamato[4] = LoadGraph("Img/yamato4.png");
	yamato[5] = LoadGraph("Img/yamato5.png");
	yamato[6] = LoadGraph("Img/yamato6.png");
	yamato[7] = LoadGraph("Img/yamato7.png");
	yamato[8] = LoadGraph("Img/yamato8.png");
	yamato[9] = LoadGraph("Img/yamato9.png");
	yamato[10] = LoadGraph("Img/yamato10.png");
	yamato[11] = LoadGraph("Img/yamato11.png");
	yamato[12] = LoadGraph("Img/yamato12.png");
	yamato[13] = LoadGraph("Img/yamato13.png");
	yamato[14] = LoadGraph("Img/yamato14.png");
	yamato[15] = LoadGraph("Img/yamato15.png");
	yamato[16] = LoadGraph("Img/yamato16.png");
	yamato[17] = LoadGraph("Img/yamato17.png");
	yamato[18] = LoadGraph("Img/yamato18.png");
	yamato[19] = LoadGraph("Img/yamato19.png");
	yamato[20] = LoadGraph("Img/yamato20.png");
	yamato[21] = LoadGraph("Img/yamato21.png");

	
	rie[0] = LoadGraph("Img/rie0.png");
	rie[1] = LoadGraph("Img/rie1.png");
	rie[2] = LoadGraph("Img/rie2.png");
	rie[3] = LoadGraph("Img/rie3.png");
	rie[4] = LoadGraph("Img/rie4.png");
	rie[5] = LoadGraph("Img/rie5.png");
	rie[6] = LoadGraph("Img/rie6.png");
	rie[7] = LoadGraph("Img/rie7.png");
	rie[8] = LoadGraph("Img/rie8.png");
	rie[9] = LoadGraph("Img/rie9.png");
	rie[10] = LoadGraph("Img/rie10.png");
	rie[11] = LoadGraph("Img/rie11.png");
	rie[12] = LoadGraph("Img/rie12.png");
	rie[13] = LoadGraph("Img/rie13.png");
	rie[14] = LoadGraph("Img/rie14.png");
	rie[15] = LoadGraph("Img/rie15.png");
	rie[16] = LoadGraph("Img/rie16.png");
	rie[17] = LoadGraph("Img/rie17.png");
	rie[18] = LoadGraph("Img/rie18.png");
	rie[19] = LoadGraph("Img/rie19.png");
	rie[20] = LoadGraph("Img/rie20.png");

	Rback[0] = LoadGraph("Img/rie_back.png");

	kyoko[0] = LoadGraph("Img/kyoko0.png");
	kyoko[1] = LoadGraph("Img/kyoko1.png");
	kyoko[2] = LoadGraph("Img/kyoko2.png");
	kyoko[3] = LoadGraph("Img/kyoko3.png");
	kyoko[4] = LoadGraph("Img/kyoko4.png");
	kyoko[5] = LoadGraph("Img/kyoko5.png");
	kyoko[6] = LoadGraph("Img/kyoko6.png");
	kyoko[7] = LoadGraph("Img/kyoko7.png");
	kyoko[8] = LoadGraph("Img/kyoko8.png");
	kyoko[9] = LoadGraph("Img/kyoko9.png");
	kyoko[10] = LoadGraph("Img/kyoko10.png");
	kyoko[11] = LoadGraph("Img/kyoko11.png");
	kyoko[12] = LoadGraph("Img/kyoko12.png");
	kyoko[13] = LoadGraph("Img/kyoko13.png");
	kyoko[14] = LoadGraph("Img/kyoko14.png");
	kyoko[15] = LoadGraph("Img/kyoko15.png");
	kyoko[16] = LoadGraph("Img/kyoko16.png");
	kyoko[17] = LoadGraph("Img/kyoko17.png");
	kyoko[18] = LoadGraph("Img/kyoko18.png");
	kyoko[19] = LoadGraph("Img/kyoko19.png");
	kyoko[20] = LoadGraph("Img/kyoko20.png");

	Kback[0] = LoadGraph("Img/kyoko_back.png");

	miame[0] = LoadGraph("Img/miame0.png");
	miame[1] = LoadGraph("Img/miame1.png");
	miame[2] = LoadGraph("Img/miame2.png");
	miame[3] = LoadGraph("Img/miame3.png");
	miame[4] = LoadGraph("Img/miame4.png");
	miame[5] = LoadGraph("Img/miame5.png");
	miame[6] = LoadGraph("Img/miame6.png");
	miame[7] = LoadGraph("Img/miame7.png");
	miame[8] = LoadGraph("Img/miame8.png");
	miame[9] = LoadGraph("Img/miame9.png");
	miame[10] = LoadGraph("Img/miame10.png");
	miame[11] = LoadGraph("Img/miame11.png");
	miame[12] = LoadGraph("Img/miame12.png");
	miame[13] = LoadGraph("Img/miame13.png");
	miame[14] = LoadGraph("Img/miame14.png");
	miame[15] = LoadGraph("Img/miame15.png");
	miame[16] = LoadGraph("Img/miame16.png");
	miame[17] = LoadGraph("Img/miame17.png");
	miame[18] = LoadGraph("Img/miame18.png");
	miame[19] = LoadGraph("Img/miame19.png");
	miame[20] = LoadGraph("Img/miame20.png");
	miame[21] = LoadGraph("Img/miame21.png");
	miame[22] = LoadGraph("Img/miame22.png");
	miame[23] = LoadGraph("Img/miame23.png");
	miame[24] = LoadGraph("Img/miame24.png");
	miame[25] = LoadGraph("Img/miame25.png");
	miame[26] = LoadGraph("Img/miame26.png");
	
	Mback[0] = LoadGraph("Img/miame_back.png");
	
	
}


Graph::~Graph()
{
}


void Graph::Title() {

	SetBackgroundColor(45,45,45);
	DrawGraph(0, 0, titleback, true);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	DrawExtendGraph(0,0,WINDOW_WIDTH,WINDOW_HEIGHT,snow,true);
	SetDrawBlendMode(DX_BLENDMODE_MULA, 255);
	if (GetMovieStateToGraph(snow) != 1) {
		PlayMovieToGraph(snow);
	}
		Circle(550, 50,true);



}

void Graph::Circle(int x, int y, bool right) {

	SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
	DrawRotaGraph2(x,y,400, 400,1.0, 90 * num,circle[0], true, false);
	DrawRotaGraph2(x,y, 250, 250, 1.2, 90 * num*-1, circle[1], true, false);
	//アングルは π ÷ 180*1　で1度


	if (right == true) {
	
		if (num < 360) {
			num += 0.00005;

		}
		else if (num == 360) {
			num = 0;
		}
	}

	else {
		if (num > -360) {
			num -= 0.00005;

		}
		else if (num == -360) {
			num = 0;
		}
	
	}

	




	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Graph::MenuCircle(int x, int y,double num) {

	SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);
	DrawRotaGraph2(x, y, 300, 300, 1.0, 3.14 / 180 * num, circle[2], true, false);
	//アングルは π ÷ 180*1　で1度
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

}

void Graph::Save(bool sl, bool select) {
	if (sl == true) {
		DrawGraph(0, 0, saveback[0], true);
	}
	else if (sl == false) {
		DrawGraph(0, 0, saveback[1], true);
	}


	if (GetMovieStateToGraph(snow) != 1) {
		PlayMovieToGraph(snow);
	}


	Circle(300, 350, false);
	SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 205);
	DrawGraph(0, 0, saveback[2], true);
	SetDrawBlendMode(DX_BLENDMODE_SUB, 105);
	DrawGraph(0, 0, noise, true);
	SetDrawBlendMode(DX_BLENDMODE_ADD, 135);
	DrawExtendGraph(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, snow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	DrawGraph(0, 650, bar[0], true);
	if (select == false) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	DrawGraph(0, 0, UIMe[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	DrawGraph(0, 150, savebar, true);
	DrawGraph(0, 250, savebar, true);
	DrawGraph(0, 350, savebar, true);
	DrawGraph(0, 450, savebar, true);
}

void Graph::Back(int mode) {

	switch (mode) {
	
	case 0:
		DrawGraph(0, 0, back[0], true);
		break;

	case 1:
		DrawGraph(0, 0, next, true);
		break;
	
	
	}


}

void  Graph::Menu(bool select) {


	if (GetMovieStateToGraph(snow) != 1) {
		PlayMovieToGraph(snow,DX_PLAYTYPE_LOOP);
	}

	
	Back(0);

	SetDrawBlendMode(DX_BLENDMODE_ADD, 250);
	DrawExtendGraph(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, snow, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	DrawGraph(0, 650, bar[0], true);
	if (select == false) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 130);
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	DrawGraph(0, 0, UIMe[0], true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void Graph::SkyBack(int date,int charanum) 
{

	switch (date) {

	case 1:
		DrawGraph(0, 0, Skyback[0], true);
		break;

	case 2:
		DrawGraph(0, 0, Skyback[1], true);
		break;

	case 3:
		DrawGraph(0, 0, Skyback[2], true);
		break;

	case 4:
		DrawGraph(0, 0, Skyback[3], true);
		break;

	case 5:
		DrawGraph(0, 0, Skyback[4], true);
		break;

	case 6:
		DrawGraph(0, 0, Skyback[5], true);
		break;

	case 7:
		DrawGraph(0, 0, Skyback[6], true);
		break;

	case 8:
		DrawGraph(0, 0, Skyback[7], true);
		break;

	case 9:
		DrawGraph(0, 0, Skyback[8], true);
		break;

	default:
		break;


	}

	switch (charanum) {

	case 0:
		DrawGraph(0, 0, Yback[0], true);
		break;

	case 1:
		DrawGraph(0, 0, Rback[0], true);
		DrawGraph(0, -20, window, true);
		break;

	case 2:
		DrawGraph(0, 0, Kback[0], true);
		DrawGraph(0, -20, window, true);
		break;

	case 3:
		DrawGraph(0, 0, Mback[0], true);
		DrawGraph(0, -20, window, true);
		break;

	default:
		break;

	}


}

void Graph::Yamato(int sabun)
{

	if (sabun != -1) {
	
		DrawGraph(0, 0, yamato[sabun], true);
	}

		



}

void Graph::Rie(int sabun)
{
	if (sabun != -1) {

		DrawGraph(0, 0, rie[sabun], true);
	}



	



}


void Graph::Kyoko(int sabun)
{


	if (sabun != -1) {
		DrawGraph(0, 0, kyoko[sabun], true);
	}
	



}

void Graph::Miame(int sabun)
{
	if (sabun != -1) {
		DrawGraph(0, 0, miame[sabun], true);
	}





}
