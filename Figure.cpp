#include "Figure.h"

void Figure::initFigure()
{
	_figurePoint		= this->createRandFigure();
}

Figure::Figure(Point position)
{
	_position				= position;
	_timeUpdateMax			= 1.f;
	_timeUpdate				= _timeUpdateMax;
	_rotateFigureStatus		= 0;
	_rotateFigureBack		= 0;
	this->initFigure();
}

Figure::~Figure()
{
	/*some code*/
}

void Figure::moveLeft()
{
	_position.x--;
}

void Figure::moveRight()
{
	_position.x++;
}

void Figure::moveDown()
{
	_timeUpdate				= 10.f;
}

void Figure::rotateFigure()
{
	++_rotateFigureStatus;
	if (_rotateFigureStatus >= _figurePoint.size())
	{
		_rotateFigureStatus = 0;
	}
}

std::vector<std::vector<Point>> Figure::createRandFigure()
{
	switch (rand() % 7)
	{
	case 0:															// I
		return
		{ 
			{ Point(0,0), Point(1,0), Point(2,0), Point(3,0) },
			{ Point(1,0), Point(1,1), Point(1,2), Point(1,3) } 
		};
		break;
	case 1:															// O
		return
		{
			{ Point(0,0), Point(1,0), Point(1,1), Point(0,1) } 
		};
		break;
	case 2:															// T
		return
		{ 
			{ Point(0,0), Point(1,0), Point(2,0), Point(1,1) },
			{ Point(1,0), Point(1,1), Point(1,2), Point(0,1) },
			{ Point(0,1), Point(1,1), Point(2,1), Point(1,0) },
			{ Point(0,0), Point(0,1), Point(0,2), Point(1,1) } 
		};
		break;
	case 3:															// S
		return
		{
			{ Point(1,0), Point(2,0), Point(0,1), Point(1,1) },
			{ Point(1,0), Point(1,1), Point(2,1), Point(2,2) }
		};
		break;
	case 4:															// Z
		return
		{
			{ Point(0,0), Point(1,0), Point(1,1), Point(2,1) },
			{ Point(1,0), Point(1,1), Point(0,1), Point(0,2) }
		};
		break;
	case 5:															// L
		return
		{
			{ Point(0,0), Point(0,1), Point(0,2), Point(1,2) },
			{ Point(0,1), Point(0,0), Point(1,0), Point(2,0) },
			{ Point(1,0), Point(2,0), Point(2,1), Point(2,2) },
			{ Point(2,1), Point(2,2), Point(1,2), Point(0,2) }
		};
		break;
	case 6:															// J
		return
		{
			{ Point(2,0), Point(2,1), Point(2,2), Point(1,2) },
			{ Point(2,1), Point(2,0), Point(1,0), Point(0,0) },
			{ Point(1,0), Point(0,0), Point(0,1), Point(0,2) },
			{ Point(0,1), Point(0,2), Point(1,2), Point(2,2) }
		};
		break;
	}
}

void Figure::setLastPosition()
{
	_lastPositon		= _position;
	_rotateFigureBack	= _rotateFigureStatus;
}

void Figure::setStepBack()
{
	_position			= _lastPositon;
	_rotateFigureStatus = _rotateFigureBack;
}

void Figure::setPosition(Point position)
{
	_position			= position;
}

const std::vector<Point>& Figure::getBody() const
{
	return _figurePoint[_rotateFigureStatus];
}

Point Figure::getPosition() const
{
	return _position;
}

void Figure::update(float deltaTime)
{
	_timeUpdate			+= deltaTime;
	if (_timeUpdate <= _timeUpdateMax) return;
	_timeUpdate			= 0;
	++_position.y;
}

void Figure::draw(BaseApp & baseApp)
{
	for (const Point& point : _figurePoint[_rotateFigureStatus])
	{
		baseApp.SetChar(point.x + _position.x, 
						point.y + _position.y, 0x25D8);
	}
}

																// Struct
Point::Point(int _x, int _y) : x(_x), y(_y)
{

}
