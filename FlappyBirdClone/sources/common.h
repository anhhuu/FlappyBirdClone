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

#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 682
#define GAME_TITLE "Flappy Bird"
#define FLAPPY_BIRD_ICON_PATH "resources/textures/FlappyBirdIcon.png"
#define SCALE 0.6666f


#define SPLASH_SCENE_SHOW_TIME 2.0f

#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/textures/SplashBackground.png"
#define MAIN_MENU_SCENE_BACKGROUND_FILEPATH "resources/textures/Sky.png"
#define GAME_SCENE_BACKGROUND_FILEPATH "resources/textures/Sky.png"
#define GAME_OVER_SCENE_BACKGROUND_FILEPATH "resources/textures/Sky.png"

#define BIRD_FRAME_1_FILEPATH "resources/textures/Bird01.png"
#define BIRD_FRAME_2_FILEPATH "resources/textures/Bird02.png"
#define BIRD_FRAME_3_FILEPATH "resources/textures/Bird03.png"
#define BIRD_FRAME_4_FILEPATH "resources/textures/Bird04.png"

#define GAME_TITLE_FILEPATH "resources/textures/Title.png"
#define PLAY_BUTTON_FILEPATH "resources/textures/PlayButton.png"

#define LAND_FILEPATH "resources/textures/Land.png"

#define PIPE_UP_FILEPATH "resources/textures/PipeUp.png"
#define PIPE_DOWN_FILEPATH "resources/textures/PipeDown.png"
#define SCORING_PIPE_FILEPATH "resources/textures/InvisibleScoringPipe.png"

#define GAME_OVER_TITLE_FILEPATH "resources/textures/GameOverTitle.png"
#define GAME_OVER_BODY_FILEPATH "resources/textures/GameOverBody.png"

#define BRONZE_MEDAL_FILEPATH "resources/textures/BronzeMedal.png"
#define GOLD_MEDAL_FILEPATH "resources/textures/GoldMedal.png"
#define PLATINUM_MEDAL_FILEPATH "resources/textures/PlatinumMedal.png"
#define SILVER_MEDAL_FILEPATH "resources/textures/SilverMedal.png"

#define FLAPPY_FONT "resources/fonts/FlappyFont.ttf"

#define HIT_SOUND_FILEPATH "resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "resources/audio/Wing.wav"


#define PIPE_MOVEMENT_SPEED 250.0f
#define PIPE_SPAWN_FREQUENCY 1.5f
#define LAND_MOVEMENT_SPEED 250.0f

#define BIRD_ANIMATION_DURATION 0.4f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f

#define FLASH_EFFECTS_SPEED_AFTER_DIE 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define BRONZE_MEDAL_SCORE 0
#define SILVER_MEDAL_SCORE 10
#define GOLD_MEDAL_SCORE 20
#define PLATINUM_MEDAL_SCORE 50  

