#include "GameField.h"

GameField::GameField()
{
	/*code here*/
}

GameField::~GameField()
{
	/*code here*/
}

void GameField::setSizeWindow(int width, int height)
{
	_width			= width;
	_height			= height;

	_staticField	= std::vector<std::vector<wchar_t>>(_height - 1, std::vector<wchar_t>(_width - 1, '.'));
}

bool GameField::updateCollision(Figure & figure)
{
	Point position = figure.getPosition();
	for (const Point& point : figure.getBody())
	{
		if (point.x + position.x < 1 || point.x + position.x > _width - 1)
			return true;
		if (point.y + position.y < 1 || point.y + position.y > _height - 1)
			return true;
		if (_staticField[point.y + position.y - 1][point.x + position.x - 1] != '.')
			return true;
	}
	return false;
}

size_t GameField::getPoint()
{
	return _point;
}

void GameField::integrateField(const Figure & figure)
{
	Point position = figure.getPosition();
	for (const Point& point : figure.getBody())
	{
		_staticField[point.y + position.y - 1][point.x + position.x - 1] = 0x25D8;
	}
}

void GameField::destroyLineFigure(const Figure & figure)
{
	for (size_t i = 0; i < _staticField.size(); ++i)
	{
		bool fullRow = true;
		int count = 0;
		for (size_t j = 0; j < _staticField[i].size(); ++j)
		{
			if (_staticField[i][j] != '.')
				++count;
			if (_staticField[j].size() == count)
				fullRow = true;
			else
				fullRow = false;
		}

		if (fullRow)
		{
			_point += 5;
			for (size_t j = i; j > 0; --j)
			{
				_staticField[j] = _staticField[j - 1];
			}
			_staticField[0] = std::vector<wchar_t>(_width - 1, '.');
		}
	}
}

void GameField::update(float deltaTime)
{
	/*code here*/
}

void GameField::draw(BaseApp & _baseApp)
{
	for (int i = 0; i <= _width; ++i)
	{
		_baseApp.SetChar(i, 0, '#');
		_baseApp.SetChar(i, _height, '#');

		for (int j = 0; j <= _height; ++j)
		{
			_baseApp.SetChar(0, j, '#');
			_baseApp.SetChar(_width, j, '#');

			if (i < _width && j < _height)
				_baseApp.SetChar(i + 1, j + 1, ' ');
		}
	}
}

void GameField::drawStaticFieldFigure(BaseApp & _baseApp)
{
																		// Draw static field
	for (int y = 0; y < _staticField.size(); ++y)
	{
		for (int x = 0; x < _staticField[y].size(); ++x)
		{
			_baseApp.SetChar(x + 1, y + 1, _staticField[y][x]);
		}
	}
}
