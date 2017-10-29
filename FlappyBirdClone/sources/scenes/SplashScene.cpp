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



#include "SplashScene.h"


namespace PMAH
{
	SplashState::SplashState(std::shared_ptr<GameData> data)
		: m_Data(data)
	{
	}

	void SplashState::init()
	{
		this->m_Data->_Assets.loadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);
		m_sprBackground.setTexture(this->m_Data->_Assets.getTexture("Splash State Background"));
		m_sprBackground.setScale(sf::Vector2f(SCALE, SCALE));

	}

	void SplashState::handleInput()
	{
		sf::Event event;
		while (this->m_Data->_Window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->_Window.close();
			}
		}
	}

	void SplashState::update(float dt)
	{
		if (m_Clock.getElapsedTime().asSeconds() > SPLASH_SCENE_SHOW_TIME)
		{
			this->m_Data->_Scenes.addScene(std::unique_ptr<Scene>(new MainMenuScene(this->m_Data)), true);
		}

	}

	void SplashState::draw(float dt)
	{
		this->m_Data->_Window.clear();

		this->m_Data->_Window.draw(m_sprBackground);

		this->m_Data->_Window.display();
	}
}

