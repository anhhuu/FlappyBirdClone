//
// Flappy Bird Clone Game Source Code
// Copyright (c) 2017 panhhuu.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 



#pragma once

#include <SFML/Graphics.hpp>
#include "../manager/Scene.h"
#include "GameScene.h"

#include "../common.h"
#include "../Game.h"

#include <iostream>
#include <sstream>

namespace PMAH
{
	class MainMenuScene : public Scene
	{
	public:

		MainMenuScene(std::shared_ptr<GameData> data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		std::shared_ptr<GameData> m_Data;

		sf::Sprite m_sprBackground;
		sf::Sprite m_sprTitle;
		sf::Sprite m_sprPlayButton;

	};
}

