#pragma once

#include "BaseApp.h"

class GameGUI
{
private:

public:
	GameGUI();
	virtual ~GameGUI();

	void			renderField(BaseApp& baseApp);
	void			renderScore(BaseApp& baseApp);
	void			renderPoint(BaseApp& baseApp, size_t scorPoint);
	void			render(BaseApp& baseApp);
};

