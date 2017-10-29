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



#include "GameOverScene.h"

namespace PMAH
{
	GameOverScene::GameOverScene(std::shared_ptr<GameData> data, unsigned int score)
		: m_Data(data), m_Score(score)
	{
	}

	void GameOverScene::init()
	{
		this->processScore();

		this->m_Data->_Assets.loadTexture("Game Over Background", GAME_OVER_SCENE_BACKGROUND_FILEPATH);
		this->m_Data->_Assets.loadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
		this->m_Data->_Assets.loadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
		this->m_Data->_Assets.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);

		this->m_Data->_Assets.loadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
		this->m_Data->_Assets.loadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
		this->m_Data->_Assets.loadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
		this->m_Data->_Assets.loadTexture("Platinum Medal", PLATINUM_MEDAL_FILEPATH);


		m_sprBackground.setTexture(this->m_Data->_Assets.getTexture("Game Over Background"));
		m_sprBackground.setScale(sf::Vector2f(SCALE, SCALE));

		m_sprGameOverContainer.setTexture(this->m_Data->_Assets.getTexture("Game Over Body"));
		m_sprGameOverContainer.setPosition(this->m_Data->_Window.getSize().x / 2 - m_sprGameOverContainer.getGlobalBounds().width / 2, this->m_Data->_Window.getSize().y / 2 - m_sprGameOverContainer.getGlobalBounds().height / 2);

		m_sprGameOverTitle.setTexture(this->m_Data->_Assets.getTexture("Game Over Title"));
		m_sprGameOverTitle.setPosition(this->m_Data->_Window.getSize().x / 2 - m_sprGameOverTitle.getGlobalBounds().width / 2, m_sprGameOverContainer.getPosition().y - (m_sprGameOverTitle.getGlobalBounds().height * 1.2f));

		m_sprRetryButton.setTexture(this->m_Data->_Assets.getTexture("Play Button"));
		m_sprRetryButton.setPosition(this->m_Data->_Window.getSize().x / 2 - m_sprRetryButton.getGlobalBounds().width / 2, m_sprGameOverContainer.getPosition().y + m_sprGameOverContainer.getGlobalBounds().height + m_sprRetryButton.getGlobalBounds().height * 0.2f);

		m_txtScore.setFont(this->m_Data->_Assets.getFont("Flappy Font"));
		m_txtScore.setString(std::to_string(m_Score));
		m_txtScore.setCharacterSize(37);
		m_txtScore.setFillColor(sf::Color::White);
		m_txtScore.setOrigin(m_txtScore.getGlobalBounds().width / 2, m_txtScore.getGlobalBounds().height / 2);
		m_txtScore.setPosition(this->m_Data->_Window.getSize().x / 10 * 7.3f, this->m_Data->_Window.getSize().y / 2.15f);

		m_txtHightScore.setFont(this->m_Data->_Assets.getFont("Flappy Font"));
		m_txtHightScore.setString(std::to_string(m_HightScore));
		m_txtHightScore.setCharacterSize(37);
		m_txtHightScore.setFillColor(sf::Color::White);
		m_txtHightScore.setOrigin(m_txtHightScore.getGlobalBounds().width / 2, m_txtHightScore.getGlobalBounds().height / 2);
		m_txtHightScore.setPosition(this->m_Data->_Window.getSize().x / 10 * 7.3f, this->m_Data->_Window.getSize().y / 1.78f);

		if (m_Score >= PLATINUM_MEDAL_SCORE)
		{
			m_sprMedal.setTexture(this->m_Data->_Assets.getTexture("Platinum Medal"));
		}
		else if (m_Score >= GOLD_MEDAL_SCORE)
		{
			m_sprMedal.setTexture(this->m_Data->_Assets.getTexture("Gold Medal"));
		}
		else if (m_Score >= SILVER_MEDAL_SCORE)
		{
			m_sprMedal.setTexture(this->m_Data->_Assets.getTexture("Silver Medal"));
		}
		else
		{
			m_sprMedal.setTexture(this->m_Data->_Assets.getTexture("Bronze Medal"));
		}
		m_sprMedal.setOrigin(m_sprMedal.getGlobalBounds().width / 2, m_sprMedal.getGlobalBounds().height / 2);
		m_sprMedal.setPosition(160, 360);

	}

	void GameOverScene::handleInput()
	{
		sf::Event event;
		while (this->m_Data->_Window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->_Window.close();
			}

			if (this->m_Data->_Input.isSpriteClicked(m_sprRetryButton, sf::Mouse::Left, this->m_Data->_Window))
			{
				this->m_Data->_Scenes.addScene(std::unique_ptr<Scene>(new GameScene(this->m_Data)), true);
			}
		}
	}

	void GameOverScene::update(float dt)
	{
	}

	void GameOverScene::draw(float dt)
	{
		this->m_Data->_Window.clear();

		this->m_Data->_Window.draw(m_sprBackground);
		this->m_Data->_Window.draw(m_sprGameOverTitle);
		this->m_Data->_Window.draw(m_sprGameOverContainer);
		this->m_Data->_Window.draw(m_sprRetryButton);
		this->m_Data->_Window.draw(m_txtScore);
		this->m_Data->_Window.draw(m_txtHightScore);
		this->m_Data->_Window.draw(m_sprMedal);

		this->m_Data->_Window.display();
	}

	void GameOverScene::processScore()
	{
		m_HightScore = 0;
		std::ifstream readFile("resources/data/hightscore.pmah");

		if (!readFile.fail())
		{
			while (!readFile.eof())
			{
				readFile >> m_HightScore;
			}
		}
		readFile.close();

		if (m_Score > m_HightScore)
		{
			m_HightScore = m_Score;
			std::ofstream writeFile("resources/data/hightscore.pmah");
			if (!writeFile.fail())
			{
				writeFile << m_HightScore;
			}
			writeFile.close();
		}
	}
}



