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



#include "MainMenuScene.h"

namespace PMAH
{
	MainMenuScene::MainMenuScene(std::shared_ptr<GameData> data)
		: m_Data(data)
	{
	}

	void MainMenuScene::init()
	{
		this->m_Data->_Assets.loadTexture("Main Menu Background", MAIN_MENU_SCENE_BACKGROUND_FILEPATH);
		this->m_Data->_Assets.loadTexture("Game Title", GAME_TITLE_FILEPATH);
		this->m_Data->_Assets.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		m_sprBackground.setTexture(this->m_Data->_Assets.getTexture("Main Menu Background"));
		m_sprBackground.setScale(sf::Vector2f(SCALE, SCALE));

		m_sprTitle.setTexture(this->m_Data->_Assets.getTexture("Game Title"));
		m_sprTitle.setPosition((SCREEN_WIDTH / 2) - (m_sprTitle.getGlobalBounds().width / 2), (m_sprTitle.getGlobalBounds().height) / 2);

		m_sprPlayButton.setTexture(this->m_Data->_Assets.getTexture("Play Button"));
		m_sprPlayButton.setPosition((SCREEN_WIDTH / 2) - (m_sprPlayButton.getGlobalBounds().width / 2), SCREEN_HEIGHT / 2);
	}

	void MainMenuScene::handleInput()
	{
		sf::Event event;
		while (this->m_Data->_Window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->_Window.close();
			}

			if (this->m_Data->_Input.isSpriteClicked(m_sprPlayButton, sf::Mouse::Left, this->m_Data->_Window))
			{
				this->m_Data->_Scenes.addScene(std::unique_ptr<Scene>(new GameScene(this->m_Data)), true);
			}
		}
	}

	void MainMenuScene::update(float dt)
	{
	}

	void MainMenuScene::draw(float dt)
	{
		this->m_Data->_Window.clear();

		this->m_Data->_Window.draw(m_sprBackground);
		this->m_Data->_Window.draw(m_sprTitle);
		this->m_Data->_Window.draw(m_sprPlayButton);

		this->m_Data->_Window.display();
	}
}

