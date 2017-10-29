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



#include "Pipe.h"

namespace PMAH
{
	Pipe::Pipe(std::shared_ptr<GameData> data)
		: m_Data(data)
	{
		m_LandHeight = this->m_Data->_Assets.getTexture("Land").getSize().y;
		m_PipeSpawnYOffset = 0;
	}

	void Pipe::spawnBottomPipe()
	{
		sf::Sprite sprite(this->m_Data->_Assets.getTexture("Pipe Up"));

		sprite.setPosition(this->m_Data->_Window.getSize().x, this->m_Data->_Window.getSize().y - sprite.getGlobalBounds().height - m_PipeSpawnYOffset);

		m_PipeSprites.push_back(sprite);
	}

	void Pipe::spawnTopPipe()
	{
		sf::Sprite sprite(this->m_Data->_Assets.getTexture("Pipe Down"));

		sprite.setPosition(this->m_Data->_Window.getSize().x, 0 - m_PipeSpawnYOffset);

		m_PipeSprites.push_back(sprite);
	}

	void Pipe::spawnInvisiblePipe()
	{
		sf::Sprite sprite(this->m_Data->_Assets.getTexture("Pipe Down"));

		sprite.setPosition(this->m_Data->_Window.getSize().x, 0 - m_PipeSpawnYOffset);
		sprite.setColor(sf::Color(0, 0, 0, 0));

		m_PipeSprites.push_back(sprite);
	}

	void Pipe::spawnScoringPipe()
	{
		sf::Sprite sprite(this->m_Data->_Assets.getTexture("Scoring Pipe"));

		sprite.setPosition(this->m_Data->_Window.getSize().x, 0);


		m_ScoringPipes.push_back(sprite);
	}

	void Pipe::movePipes(float dt)
	{
		for (unsigned short int i = 0; i < m_PipeSprites.size(); i++)
		{
			if (m_PipeSprites.at(i).getPosition().x < 0 - m_PipeSprites.at(i).getGlobalBounds().width)
			{
				m_PipeSprites.erase(m_PipeSprites.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;
				m_PipeSprites.at(i).move(-movement, 0);
			}
		}

		for (unsigned short int i = 0; i < m_ScoringPipes.size(); i++)
		{
			if (m_ScoringPipes.at(i).getPosition().x < 0 - m_ScoringPipes.at(i).getGlobalBounds().width)
			{
				m_ScoringPipes.erase(m_ScoringPipes.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;
				m_ScoringPipes.at(i).move(-movement, 0);
			}
		}

	}
	void Pipe::drawPipes()
	{
		for (unsigned short int i = 0; i < m_PipeSprites.size(); i++)
		{
			this->m_Data->_Window.draw(m_PipeSprites.at(i));
		}
	}
	void Pipe::randomisePipeYOffset()
	{
		m_PipeSpawnYOffset = rand() % (m_LandHeight + 1);
	}
	const int Pipe::getYOffset() const
	{
		return m_PipeSpawnYOffset;
	}
	const std::vector<sf::Sprite>& Pipe::getSprites() const
	{
		return m_PipeSprites;
	}
	std::vector<sf::Sprite>& Pipe::getScoringSprites()
	{
		return m_ScoringPipes;
	}
}

