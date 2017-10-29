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

#include "SceneManager.h"

namespace PMAH
{
	void SceneManager::addScene(std::unique_ptr<Scene> newScene, bool isReplacing)
	{
		this->m_IsAdding = true;
		this->m_IsReplacing = isReplacing;

		this->m_NewScene = std::move(newScene);
	}

	void SceneManager::removeScene()
	{
		this->m_IsRemoving = true;
	}

	void SceneManager::processSceneChanges()
	{
		if (this->m_IsRemoving && !this->m_Scenes.empty())
		{
			this->m_Scenes.pop();

			if (!this->m_Scenes.empty())
			{
				this->m_Scenes.top()->resume();
			}

			this->m_IsRemoving = false;
		}

		if (this->m_IsAdding)
		{
			if (!this->m_Scenes.empty())
			{
				if (this->m_IsReplacing)
				{
					this->m_Scenes.pop();
				}
				else
				{
					this->m_Scenes.top()->pause();
				}
			}

			this->m_Scenes.push(std::move(this->m_NewScene));
			this->m_Scenes.top()->init();
			this->m_IsAdding = false;
		}
	}

	std::unique_ptr<Scene>& SceneManager::getActiveScene()
	{
		return this->m_Scenes.top();
	}
}

