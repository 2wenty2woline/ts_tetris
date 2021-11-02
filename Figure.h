#pragma once
#include <vector>
#include "BaseApp.h"

struct Point
{
public:
	Point(int _x = 0, int _y = 0);

	int								x;
	int								y;
};

class Figure
{
private:

	Point							_position;
	Point							_lastPositon;
	std::vector<std::vector<Point>>	_figurePoint;
	size_t							_rotateFigureStatus;
	size_t							_rotateFigureBack;

	float							_timeUpdate;
	float							_timeUpdateMax;

	void							initFigure();

public:
	Figure(Point position);
	virtual ~Figure();

	void							moveLeft();
	void							moveRight();
	void							moveDown();
	void							rotateFigure();

	std::vector<std::vector<Point>>	createRandFigure();

	void							setLastPosition();
	void							setStepBack();
	void							setPosition(Point position);

	const std::vector<Point>&		getBody() const;
	Point							getPosition()const;

	void							update(float deltaTime);
	void							draw(BaseApp& baseApp);
};

