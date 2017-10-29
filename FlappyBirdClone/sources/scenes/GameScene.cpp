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



#include "GameScene.h"


namespace PMAH
{
	GameScene::GameScene(std::shared_ptr<GameData> data)
		: m_Data(data)
	{
	}

	void GameScene::init()
	{

		if (!m_HitSoundBuffer.loadFromFile(HIT_SOUND_FILEPATH))
		{
			std::cout << "Error loading Hit Sound Effect" << std::endl;
		}

		if (!m_PointSoundBuffer.loadFromFile(POINT_SOUND_FILEPATH))
		{
			std::cout << "Error loading Point Sound Effect" << std::endl;
		}

		if (!m_WingSoundBuffer.loadFromFile(WING_SOUND_FILEPATH))
		{
			std::cout << "Error loading Wing Sound Effect" << std::endl;
		}

		m_HitSound.setBuffer(m_HitSoundBuffer);
		m_PointSound.setBuffer(m_PointSoundBuffer);
		m_WingSound.setBuffer(m_WingSoundBuffer);

		this->m_Data->_Assets.loadTexture("Game Background", GAME_SCENE_BACKGROUND_FILEPATH);

		this->m_Data->_Assets.loadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
		this->m_Data->_Assets.loadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
		this->m_Data->_Assets.loadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
		this->m_Data->_Assets.loadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);

		this->m_Data->_Assets.loadTexture("Pipe Up", PIPE_UP_FILEPATH);
		this->m_Data->_Assets.loadTexture("Pipe Down", PIPE_DOWN_FILEPATH);

		this->m_Data->_Assets.loadTexture("Land", LAND_FILEPATH);

		this->m_Data->_Assets.loadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);

		this->m_Data->_Assets.loadFont("Flappy Font", FLAPPY_FONT);

		m_sprBackground.setTexture(this->m_Data->_Assets.getTexture("Game Background"));
		m_sprBackground.setScale(sf::Vector2f(SCALE, SCALE));

		m_pBird = new Bird(this->m_Data);
		m_pPipe = new Pipe(this->m_Data);
		m_pLand = new Land(this->m_Data);
		m_pFlash = new Flash(this->m_Data);
		m_pGameText = new GameText(this->m_Data);

		m_Score = 0;
		m_pGameText->updateScore(m_Score);

		m_GameStates = GameStates::Ready;

	}

	void GameScene::handleInput()
	{
		sf::Event event;
		while (this->m_Data->_Window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->m_Data->_Window.close();
			}

			if (this->m_Data->_Input.isSpriteClicked(m_sprBackground, sf::Mouse::Left, this->m_Data->_Window))
			{
				if (m_GameStates != GameStates::Over)
				{
					m_GameStates = GameStates::Playing;
					m_pBird->tap();
					m_WingSound.play();
				}
			}
		}
	}

	void GameScene::update(float dt)
	{
		if (m_GameStates != GameStates::Over)
		{
			m_pBird->animate(dt);
			m_pLand->moveLand(dt);
		}
		if (m_GameStates == GameStates::Playing)
		{
			m_pPipe->movePipes(dt);

			if (m_Clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{
				m_pPipe->randomisePipeYOffset();

				m_pPipe->spawnInvisiblePipe();
				m_pPipe->spawnBottomPipe();
				m_pPipe->spawnTopPipe();
				m_pPipe->spawnScoringPipe();

				m_Clock.restart();
			}

			m_pBird->update(dt);

			//Land Collision
			std::vector<sf::Sprite> landSprites = m_pLand->getSprites();
			for (unsigned int short i = 0; i < landSprites.size(); i++)
			{
				sf::FloatRect landBox = landSprites.at(i).getGlobalBounds();
				if (m_Collision.checkSpriteCollision(m_pBird->getSprite(), 0.9, landSprites.at(i), 1.0f))
				{
					m_GameStates = GameStates::Over;

					m_Clock.restart();

					m_HitSound.play();
				}
			}

			//Pipe Collision
			std::vector<sf::Sprite> pipeSprites = m_pPipe->getSprites();
			for (unsigned int short i = 0; i < pipeSprites.size(); i++)
			{
				if (m_Collision.checkSpriteCollision(m_pBird->getSprite(), 0.7f, pipeSprites.at(i), 1.0f))
				{
					m_GameStates = GameStates::Over;
					m_Clock.restart();
					m_HitSound.play();
				}
			}

			//Pipescore Colision
			if (m_GameStates == GameStates::Playing)
			{
				std::vector<sf::Sprite> &scoringPipes = m_pPipe->getScoringSprites();
				for (unsigned int short i = 0; i < scoringPipes.size(); i++)
				{
					if (m_Collision.checkSpriteCollision(m_pBird->getSprite(), 0.625f, scoringPipes.at(i), 0.95f))
					{
						m_Score++;
						m_pGameText->updateScore(m_Score);
						scoringPipes.erase(scoringPipes.begin() + i);
						m_PointSound.play();
					}
				}
			}
		}

		if (m_GameStates == GameStates::Over)
		{
			m_pFlash->show(dt);
			if (m_Clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS)
			{
				this->m_Data->_Scenes.addScene(std::unique_ptr<Scene>(new GameOverScene(this->m_Data, m_Score)), true);
			}
		}
	}

	void GameScene::draw(float dt)
	{
		this->m_Data->_Window.clear();

		this->m_Data->_Window.draw(m_sprBackground);

		m_pBird->draw();
		m_pPipe->drawPipes();
		m_pLand->drawLand();
		m_pFlash->draw();
		m_pGameText->draw();

		this->m_Data->_Window.display();
	}
}



