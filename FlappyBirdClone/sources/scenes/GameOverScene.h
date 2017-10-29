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
#include "../manager/SceneManager.h"
#include "GameScene.h"
#include "../Game.h"
#include "../common.h"

#include <sstream>
#include <iostream>
#include <fstream>


namespace PMAH
{
	class GameOverScene : public Scene
	{
	public:

		GameOverScene(std::shared_ptr<GameData> data, unsigned int score);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:

		void processScore();

		std::shared_ptr<GameData> m_Data;

		sf::Sprite m_sprBackground;
		sf::Sprite m_sprGameOverTitle;
		sf::Sprite m_sprGameOverContainer;
		sf::Sprite m_sprRetryButton;
		sf::Sprite m_sprMedal;

		sf::Text m_txtScore;
		sf::Text m_txtHightScore;

		unsigned int m_Score;
		unsigned int m_HightScore;

	};
}

