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
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 



#include "Game.h"

#include "scenes/SplashScene.h"


namespace PMAH
{
	Game::Game(int width, int height, std::string title)
	{
		srand(time(nullptr));
		this->m_Data->_Window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
		this->m_Data->_Scenes.addScene(std::unique_ptr<Scene>(new SplashState(this->m_Data)));

		sf::Image icon;
		icon.loadFromFile(FLAPPY_BIRD_ICON_PATH);
		this->m_Data->_Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		this->run();
	}
	void Game::run()
	{
		float newTime, frameTime, interpolation;

		float currentTime = this->m_Clock.getElapsedTime().asSeconds();

		float accumulator = 0.0f;

		while (this->m_Data->_Window.isOpen())
		{
			this->m_Data->_Scenes.processSceneChanges();

			newTime = this->m_Clock.getElapsedTime().asSeconds();

			frameTime = newTime - currentTime;

			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			accumulator += frameTime;
			while (accumulator >= dt)
			{
				this->m_Data->_Scenes.getActiveScene()->handleInput();
				this->m_Data->_Scenes.getActiveScene()->update(dt);
				accumulator -= dt;
			}

			interpolation = accumulator / dt;
			this->m_Data->_Scenes.getActiveScene()->draw(interpolation);
		}
	}
}

