#include "GameGUI.h"

GameGUI::GameGUI()
{
	/*code here*/
}

GameGUI::~GameGUI()
{
	/*code here*/
}

void GameGUI::renderField(BaseApp & baseApp)
{
	for (int i = 0; i <= 16; ++i)
	{
		baseApp.SetChar(i, 21, '#');
		baseApp.SetChar(i, 25, '#');

		for (int j = 21; j <= 25; ++j)
		{
			baseApp.SetChar(0,  j, '#');
			baseApp.SetChar(16, j, '#');

			if (i < 16 && j < 25)
				baseApp.SetChar(i + 1, j + 1, ' ');
		}
	}

	for (int i = 16; i <= 24; ++i)
	{
		baseApp.SetChar(i, 0,  '#');
		baseApp.SetChar(i, 21, '#');
		baseApp.SetChar(i, 25, '#');

		for (int j = 0; j <= 25; ++j)
		{
			baseApp.SetChar(25, j, '#');

			if (i < 24 && j < 25)
				baseApp.SetChar(i + 1, j + 1, ' ');
		}
	}
}

void GameGUI::renderScore(BaseApp & baseApp)
{
	baseApp.SetChar(3,  23, '>');
	baseApp.SetChar(5,  23, 'S');
	baseApp.SetChar(6,  23, 'c');
	baseApp.SetChar(7,  23, 'o');
	baseApp.SetChar(8,  23, 'r');
	baseApp.SetChar(9,  23, 'e');
	baseApp.SetChar(10, 23, ':');
}

void GameGUI::renderPoint(BaseApp & baseApp, size_t scorPoint)
{
	std::string point = std::to_string(scorPoint);
	for (size_t i = 0; i < point.size(); ++i)
	{
		if (scorPoint < 999)
		{
			baseApp.SetChar(12, 23, point.at(0));

			if (scorPoint >= 10)
				baseApp.SetChar(13, 23, point.at(1));
			if (scorPoint >= 100)
				baseApp.SetChar(14, 23, point.at(2));
		}
		else
		{
			baseApp.SetChar(12, 23, '9');
			baseApp.SetChar(13, 23, '9');
			baseApp.SetChar(14, 23, '9');
		}
	}
}

void GameGUI::render(BaseApp & baseApp)
{
	renderField(baseApp);
	renderScore(baseApp);
}