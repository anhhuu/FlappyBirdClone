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



#include "Land.h"

namespace PMAH
{
	Land::Land(std::shared_ptr<GameData> data)
		:m_Data(data)
	{
		sf::Sprite sprite(this->m_Data->_Assets.getTexture("Land"));
		sf::Sprite sprite2(this->m_Data->_Assets.getTexture("Land"));

		sprite.setPosition(0, this->m_Data->_Window.getSize().y - sprite.getGlobalBounds().height);

		sprite2.setPosition(sprite2.getGlobalBounds().width, this->m_Data->_Window.getSize().y - sprite2.getGlobalBounds().height);

		m_LandSprites.push_back(sprite);
		m_LandSprites.push_back(sprite2);
	}

	void Land::moveLand(float dt)
	{
		for (unsigned int short i = 0; i < m_LandSprites.size(); i++)
		{
			float movement = LAND_MOVEMENT_SPEED * dt;

			m_LandSprites.at(i).move(-movement, 0.0f);

			if (m_LandSprites.at(i).getPosition().x < 0 - m_LandSprites.at(i).getGlobalBounds().width + 0.5f)
			{
				sf::Vector2f position(this->m_Data->_Window.getSize().x, m_LandSprites.at(i).getPosition().y);
				m_LandSprites.at(i).setPosition(position);
			}
		}
	}

	void Land::drawLand()
	{
		for (unsigned int short i = 0; i < m_LandSprites.size(); i++)
		{
			this->m_Data->_Window.draw(m_LandSprites.at(i));
		}
	}
	const std::vector<sf::Sprite>& Land::getSprites() const
	{
		return m_LandSprites;
	}
}

