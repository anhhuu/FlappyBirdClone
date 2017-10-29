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



#include "AssetManager.h"

namespace PMAH
{
	void AssetManager::loadTexture(std::string name, std::string fileName)
	{
		sf::Texture texture;
		if (texture.loadFromFile(fileName))
		{
			this->m_Textures[name] = texture;
		}
	}

	sf::Texture& AssetManager::getTexture(std::string name)
	{
		return this->m_Textures.at(name);
	}

	void AssetManager::loadFont(std::string name, std::string fileName)
	{
		sf::Font font;
		if (font.loadFromFile(fileName))
		{
			this->m_Fonts[name] = font;
		}
	}

	sf::Font& AssetManager::getFont(std::string name)
	{
		return this->m_Fonts.at(name);
	}
}

