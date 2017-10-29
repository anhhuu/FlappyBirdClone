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



#include "GameText.h"
#include <string>

namespace PMAH
{
	GameText::GameText(std::shared_ptr<GameData> data)
		: m_Data(data)
	{
		m_txtScore.setFont(this->m_Data->_Assets.getFont("Flappy Font"));
		m_txtScore.setString("0");
		m_txtScore.setCharacterSize(80);
		m_txtScore.setFillColor(sf::Color::White);
		m_txtScore.setOrigin(m_txtScore.getGlobalBounds().width / 2, m_txtScore.getGlobalBounds().height / 2);
		m_txtScore.setPosition(this->m_Data->_Window.getSize().x / 2, this->m_Data->_Window.getSize().y / 20);
	}

	void GameText::draw()
	{
		this->m_Data->_Window.draw(m_txtScore);
	}

	void GameText::updateScore(int score)
	{
		m_txtScore.setString(std::to_string(score));
	}
}

