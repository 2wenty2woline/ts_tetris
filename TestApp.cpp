// Copyright 2009-2014 Blam Games, Inc. All Rights Reserved.

#include "TestApp.h"

void TestApp::initField()
{
	_gameField.setSizeWindow(16, 21);
}

void TestApp::initGui()
{
	/*code here*/
}

TestApp::TestApp() : Parent(100, 80), _figure(Point(5,1)), _nextFigure(Point(19, 8))/*gui*/
{
	_screenPoint	= 0;
	_endGame		= false;

	this->initField();
	this->initGui();
}

TestApp::~TestApp()
{
	/*code here*/
}

void TestApp::KeyPressed(int btnCode)
{
																		// The last step of the figure
	_figure.setLastPosition();
	switch (btnCode)
	{
																		// A 97
	case 75:
		_figure.moveLeft();
		break;
																		// D 100
	case 77:
		_figure.moveRight();
		break;
																		// W 119 S 115
	case 80:
		_figure.moveDown();
		break;
																		// Space
	case 32:
		_figure.rotateFigure();
		break;
	}

																		// Reboot position of the figure
	if (_gameField.updateCollision(_figure))
	{
		_figure.setStepBack();
	}
}

																		// Render game class
void TestApp::UpdateF(float deltaTime)
{
	if (_endGame)
	{
		exit(0);
	}
	this->render();
	this->update(deltaTime);
}
																		/// Update game
void TestApp::update(float deltaTime)
{
	this->updateFigure(deltaTime);
	this->updateField();
	this->updateGui();
}

void TestApp::updateFigure(float deltaTime)
{
	_figure.update(deltaTime);																
																		// Set last position of the figure
	if (_gameField.updateCollision(_figure))
	{
		_figure.setStepBack();
		_gameField.integrateField(_figure);
		_gameField.destroyLineFigure(_figure);

		_screenPoint	= _gameField.getPoint();

		_figure			= _nextFigure;
		_figure.setPosition(Point(5, 1));
		_nextFigure		= Figure(Point(19, 8));
		if (_gameField.updateCollision(_figure))
		{
			_endGame	= true;
		}
	}
}

void TestApp::updateField()
{
	/* code here */
}

void TestApp::updateGui()
{
	/* code here */
}

void TestApp::renderFigure()
{
	_figure.draw(*this);
	_figure.setLastPosition();
}

void TestApp::renderField()
{
	_gameField.draw(*this);
	_gameField.drawStaticFieldFigure(*this);
}

void TestApp::renderGUI()
{
																		// gui score & figure
	_gameGUI.render(*this);
	_nextFigure.draw(*this);
	_gameGUI.renderPoint(*this, _screenPoint);
}

																		/// Render Game
void TestApp::render()
{
	this->renderField();
	this->renderFigure();
	this->renderGUI();
}
