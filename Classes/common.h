﻿
// đường dẫn tệp lưu trử hình ảnh của nhân vật knight. Hình đầu tiên có stt là 0
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#define KNIGHT_RATIO_H 0.8f
#define HERO_POS_X 400
#define ROCK_MONSTER_RATIO_H 0.45f
#define SPHERICAL_MONTER_RATIO_H 0.8f
#define SPHERICAL_MONTER_FLAPPY1_RATIO_H 0.2f
#define SKULL_MONSTER_RATIO_H 0.25f
#define BOSS_RATIO_H 2.2f
#define DRAGON_RATIO 2.0f
#define SKILL1_BOSS_RATIO_H 0.4f
#define GROUND1_POS_Y_RATIO 0.10f
#define GROUND2_POS_Y_RATIO 0.5f
#define BTN_PLAYGAME_RATIO 0.7f
#define BTN_PAUSEGAME_RATIO 2.0f
#define FLY_HEIGHT 80.0f
#define HP_ICON_RATIO 1.0f
#define BTN_ATK_RATIO 2.0f

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define KNIGHT_RATIO_H 0.4f
#define HERO_POS_X 400
#define ROCK_MONSTER_RATIO_H 0.2f
#define SPHERICAL_MONTER_RATIO_H 0.4f
#define SPHERICAL_MONTER_FLAPPY1_RATIO_H 0.1f
#define SKULL_MONSTER_RATIO_H 0.1f
#define BOSS_RATIO_H 1.0f
#define DRAGON_RATIO 1.0f
#define SKILL1_BOSS_RATIO_H 0.2f
#define GROUND1_POS_Y_RATIO 0.10f
#define GROUND2_POS_Y_RATIO 0.5f
#define BTN_PLAYGAME_RATIO 0.3f
#define BTN_PAUSEGAME_RATIO 1.0f
#define FLY_HEIGHT 50.0f
#define HP_ICON_RATIO 0.5f
#define BTN_ATK_RATIO 2.0f

#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#define COMBO1_NUMBER 5
#define COMBO2_NUMBER 20

#define KNIGHT_PATH "res/actor/hero/knight/"

#define KNIGHT_IDLE2_NUMBER 1
#define KNIGHT_IDLE2_FRAME_NUMBER 37
#define KNIGHT_IDLE2_PATH_FORMAT "res/actor/hero/knight/idle_2/idle_2_%d.plist"
#define KNIGHT_IDLE2_0_FRAME_NAME_FORMAT "idle_2_0_%d.png"

#define KNIGHT_RUN2_NUMBER 1
#define KNIGHT_RUN2_FRAME_NUMBER 25
#define KNIGHT_RUN2_PATH_FORMAT "res/actor/hero/knight/run_shield/run_shield_%d.plist"
#define KNIGHT_RUN2_0_FRAME_NAME_FORMAT "run_shield_0_%d.png"

#define KNIGHT_HIT_NUMBER 1
#define KNIGHT_HIT_FRAME_NUMBER 35
#define KNIGHT_HIT_PATH_FORMAT "res/actor/hero/knight/hit/hit_%d.plist"
#define KNIGHT_HIT_0_FRAME_NAME_FORMAT "hit_0_%d.png"

#define KNIGHT_DEAD_NUMBER 1
#define KNIGHT_DEAD_FRAME_NUMBER 48
#define KNIGHT_DEAD_PATH_FORMAT "res/actor/hero/knight/dead/dead_%d.plist"
#define KNIGHT_DEAD_0_FRAME_NAME_FORMAT "dead_0_%d.png"

#define KNIGHT_ATTACK1_NUMBER 1
#define KNIGHT_ATTACK1_FRAME_NUMBER 43
#define KNIGHT_ATTACK1_PATH_FORMAT "res/actor/hero/knight/sword_attack/sword_attack_%d.plist"
#define KNIGHT_ATTACK1_0_FRAME_NAME_FORMAT "sword_attack_0_%d.png"

#define KNIGHT_ATTACK2_NUMBER 1
#define KNIGHT_ATTACK2_FRAME_NUMBER 43
#define KNIGHT_ATTACK2_PATH_FORMAT "res/actor/hero/knight/shield_attack/shield_attack_%d.plist"
#define KNIGHT_ATTACK2_0_FRAME_NAME_FORMAT "shield_attack_0_%d.png"

// monter
#define SPHERICALMONTER_PATH "res/actor/enemy/spherical_monter/monster1.plist"

#define SPHERICALMONTER_IDLE_NUMBER 1
#define SPHERICALMONTER_IDLE_FRAME_NUMBER 2
#define SPHERICALMONTER_IDLE_FRAME_NAME_FORMAT "idle%d.png"

#define SPHERICALMONTER_JUMP_NUMBER 1
#define SPHERICALMONTER_JUMP_FRAME_NUMBER 2
#define SPHERICALMONTER_JUMP_FRAME_NAME_FORMAT "jump%d.png"

#define SPHERICALMONTER_HIT_NUMBER 1
#define SPHERICALMONTER_HIT_FRAME_NUMBER 1
#define SPHERICALMONTER_HIT_FRAME_NAME_FORMAT "hit%d.png"

// flappy monster
#define SPHERICALMONTER_FLAPPY1_PATH "res/actor/enemy/spherical_monter/monster2.plist"

#define SPHERICALMONTER_FLAPPY1_IDLE_NUMBER 1
#define SPHERICALMONTER_FLAPPY1_IDLE_FRAME_NUMBER 4
#define SPHERICALMONTER_FLAPPY1_IDLE_FRAME_NAME_FORMAT "fly_%d.png"

#define SPHERICALMONTER_FLAPPY1_HIT_NUMBER 1
#define SPHERICALMONTER_FLAPPY1_HIT_FRAME_NUMBER 2
#define SPHERICALMONTER_FLAPPY1_HIT_FRAME_NAME_FORMAT "hit_%d.png"

// skull monster
#define SKULLMONSTER_PATH "res/actor/enemy/rock_monster/monster2.plist"

#define SKULLMONSTER_IDLE_NUMBER 1
#define SKULLMONSTER_IDLE_FRAME_NUMBER 2
#define SKULLMONSTER_IDLE_FRAME_NAME_FORMAT "idle%d.png"

#define SKULLMONSTER_HIT_NUMBER 1
#define SKULLMONSTER_HIT_FRAME_NUMBER 1
#define SKULLMONSTER_HIT_FRAME_NAME_FORMAT "hit%d.png"

// rock monster

#define ROCKMONSTER_PATH "res/actor/enemy/rock_monster/rock-monster.png"

// boss
#define BOSS0_PATH "res/actor/enemy/boss/test2.plist"

#define BOSS_IDLE_NUMBER 1
#define BOSS_IDLE_FRAME_NUMBER 8
#define BOSS_IDLE_FRAME_NAME_FORMAT "stand_%d.png"

#define BOSS_RUN_NUMBER 1
#define BOSS_RUN_FRAME_NUMBER 8
#define BOSS_RUN_FRAME_NAME_FORMAT "move_%d.png"

#define BOSS_HIT_NUMBER 1
#define BOSS_HIT_FRAME_NUMBER 1
#define BOSS_HIT_FRAME_NAME_FORMAT "hit1_%d.png"

#define BOSS_DEAD_NUMBER 1
#define BOSS_DEAD_FRAME_NUMBER 16
#define BOSS_DEAD_FRAME_NAME_FORMAT "die1_%d.png"

#define BOSS_ATTACK2_NUMBER 1
#define BOSS_ATTACK2_FRAME_NUMBER 31
#define BOSS_ATTACK2_FRAME_NAME_FORMAT "attack2_%d.png"

// dragon
#define DRAGON_PATH "res/actor/enemy/boss2/dragon.plist"
		
#define DRAGON_RUN1_NUMBER 1
#define DRAGON_RUN1_FRAME_NUMBER 20
#define DRAGON_RUN1_FRAME_NAME_FORMAT "dragon%d.png"
	

// file backgound
#define BACKGROUND_PATH "res/bg/forest/bg_forest.png"
#define MAP_TILE_MOSSY_PATH "res/map_tile/mossy/tile_0.plist"


// tên game
#define GAME_TITLE "Slash Beat"
#define GAME_TITLE_SIZE 200

// res font
#define FONT_ARIAL_PATH "fonts/arial.ttf"
#define FONT_MARKERFELT_PATH "fonts/Marker Felt.ttf"
