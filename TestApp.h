// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#pragma once

#include <vector>
#include <string>
#include "BaseApp.h"
#include "GameField.h"
#include "Figure.h"
#include "GameGUI.h"

class TestApp : public BaseApp
{
	typedef BaseApp Parent;

private:
																// Game field
	GameField				_gameField;
	Figure					_figure;
	Figure					_nextFigure;
	GameGUI					_gameGUI;

	size_t					_screenPoint;						/*gui*/
	bool					_endGame;

	void					initField();
	void					initGui();

public:
	TestApp();
	virtual ~TestApp();



	virtual void			KeyPressed(int btnCode);
	virtual void			UpdateF(float deltaTime);

	void					update(float deltaTime);
	void					updateFigure(float deltaTime);
	void					updateField();
	void					updateGui();

	void					renderFigure();
	void					renderField();
	void					renderGUI();
	void					render();

};
