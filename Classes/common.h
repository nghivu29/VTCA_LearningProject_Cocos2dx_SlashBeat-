
// đường dẫn tệp lưu trử hình ảnh của nhân vật knight. Hình đầu tiên có stt là 0
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define KNIGHT_RATIO_H 0.8f
#define HERO_POS_X 400
#define ROCK_MONSTER_RATIO_H 0.45f
#define SPHERICAL_MONTER_RATIO_H 0.8f
#define GROUND1_POS_Y_RATIO 0.10f
#define GROUND2_POS_Y_RATIO 0.5f

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define KNIGHT_RATIO_H 0.35f
#define HERO_POS_X 400
#define ROCK_MONSTER_RATIO_H 0.2f
#define SPHERICAL_MONTER_RATIO_H 0.4f
#define GROUND1_POS_Y_RATIO 0.10f
#define GROUND2_POS_Y_RATIO 0.5f

#endif // CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID


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

// file backgound
#define BACKGROUND_PATH "res/bg/forest/bg_forest.png"


// tên game
#define GAME_TITLE "Slash Beat"
#define GAME_TITLE_SIZE 200

// res font
#define FONT_ARIAL_PATH "fonts/arial.ttf"
#define FONT_MARKERFELT_PATH "fonts/Marker Felt.ttf"
