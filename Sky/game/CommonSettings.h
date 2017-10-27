#pragma once
namespace CommonSettings {
	//解像度
	constexpr int WINDOW_WIDTH = 600;
	constexpr int WINDOW_HEIGHT = 700;

	//fps(60以上は垂直同期を切ってください。)
	constexpr int FRAME_RATE = 60;

	constexpr char* GAME_TITLE = "Sky[]"; //Unicode文字セット利用時はwchar_tに。
};