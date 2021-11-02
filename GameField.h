#pragma once
#include <vector>
#include "BaseApp.h"
#include "Figure.h"

class GameField
{
private:

	int									_width;
	int									_height;
	size_t								_point;
	std::vector<std::vector<wchar_t>>	_staticField;

public:
	GameField();
	virtual ~GameField();

																// Set size the game field
	void								setSizeWindow(int width, int height);
	bool								updateCollision(Figure & figure);

	size_t								getPoint();

	void								integrateField(const Figure & figure);
	void								destroyLineFigure(const Figure & figure);

	void								update(float deltaTime);

	void								draw(BaseApp & _baseApp);
	void								drawStaticFieldFigure(BaseApp & _baseApp);
};

