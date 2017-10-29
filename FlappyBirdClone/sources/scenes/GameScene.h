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



#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../manager/Scene.h"
#include "../scenes/GameOverScene.h"
#include "../objects/Bird.h"
#include "../objects/Pipe.h"
#include "../objects/Land.h"
#include "../utility/GameText.h"
#include "../physic/Collision.h"
#include "../efects/Flash.h"
#include "../Game.h"
#include "../common.h"

#include <sstream>
#include <iostream>

namespace PMAH
{
	class GameScene : public Scene
	{
	public:

		GameScene(std::shared_ptr<GameData> data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		std::shared_ptr<GameData> m_Data;

		sf::Sprite m_sprBackground;
		Pipe *m_pPipe;
		Land *m_pLand;
		Bird *m_pBird;

		Flash *m_pFlash;

		GameText *m_pGameText;

		Collision m_Collision;

		sf::Clock m_Clock;

		GameStates m_GameStates;

		unsigned int m_Score;

		sf::SoundBuffer m_HitSoundBuffer;
		sf::SoundBuffer m_PointSoundBuffer;
		sf::SoundBuffer m_WingSoundBuffer;

		sf::Sound m_HitSound;
		sf::Sound m_PointSound;
		sf::Sound m_WingSound;

	};
}

