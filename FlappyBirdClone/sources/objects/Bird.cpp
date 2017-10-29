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



#include "Bird.h"

namespace PMAH
{
	Bird::Bird(std::shared_ptr<GameData> data)
		: m_Data(data)
	{
		m_AnimationIterator = 0;

		m_AnimationFrame.push_back(this->m_Data->_Assets.getTexture("Bird Frame 1"));
		m_AnimationFrame.push_back(this->m_Data->_Assets.getTexture("Bird Frame 2"));
		m_AnimationFrame.push_back(this->m_Data->_Assets.getTexture("Bird Frame 3"));
		m_AnimationFrame.push_back(this->m_Data->_Assets.getTexture("Bird Frame 4"));

		m_BirdSprite.setTexture(m_AnimationFrame.at(m_AnimationIterator));
		m_BirdSprite.setPosition(this->m_Data->_Window.getSize().x / 4 - m_BirdSprite.getGlobalBounds().width, m_Data->_Window.getSize().x / 2 - m_BirdSprite.getGlobalBounds().height);
		m_BirdState = BIRD_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f(m_BirdSprite.getGlobalBounds().width / 2.0f, m_BirdSprite.getGlobalBounds().height / 2.0f);

		m_BirdSprite.setOrigin(origin);

		m_Rotation = 0;
	}

	void Bird::draw()
	{
		this->m_Data->_Window.draw(m_BirdSprite);
	}
	void Bird::animate(float dt)
	{
		if (m_Clock.getElapsedTime().asSeconds() > (BIRD_ANIMATION_DURATION * 1 / (float)m_AnimationFrame.size()))
		{
			if (m_AnimationIterator < m_AnimationFrame.size() - 1)
			{
				m_AnimationIterator++;
			}
			else
			{
				m_AnimationIterator = 0;
			}
			m_BirdSprite.setTexture(m_AnimationFrame.at(m_AnimationIterator));

			m_Clock.restart();
		}
	}

	void Bird::update(float dt)
	{
		if (m_BirdState == BIRD_STATE_FALLING)
		{
			m_BirdSprite.move(0, GRAVITY * dt);
			m_Rotation += ROTATION_SPEED * dt;
			if (m_Rotation > 25.0f)
			{
				m_Rotation = 25.0f;
			}
			m_BirdSprite.setRotation(m_Rotation);
		}
		else if (m_BirdState == BIRD_STATE_FLYING)
		{
			m_BirdSprite.move(0, -FLYING_SPEED * dt);
			m_Rotation -= ROTATION_SPEED * dt;
			if (m_Rotation < -25.0f)
			{
				m_Rotation = -25.0f;
			}
			m_BirdSprite.setRotation(m_Rotation);
		}
		if (m_MovementClock.getElapsedTime().asSeconds() > FLYING_DURATION)
		{
			m_MovementClock.restart();
			m_BirdState = BIRD_STATE_FALLING;
		}
	}

	void Bird::tap()
	{
		m_MovementClock.restart();
		m_BirdState = BIRD_STATE_FLYING;
	}
	const sf::Sprite & Bird::getSprite() const
	{
		return m_BirdSprite;
	}
}

