#ifndef DEFS_H
#define DEFS_H

const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 700;
const int PLAYER_SPEED = 15;
const int BULLET_SPEED = 15;
const int ENEMY_SPEED = 10;
const int ENEMY_SPAWN_RATE = 3;
const int MAX_ENEMIES = 1000;
const int ENERGY_MAX = 100;
const int ENERGY_DECREASE_DURATION = 5000;
const int ENERGY_RECOVER_DELAY = 5000;
const int ENERGY_RECOVER_DURATION = 5000;
const int MAX_HEALTH = 20;
const Uint32 EXPLOSION_DURATION = 200;
const Uint32 BULLET_COOLDOWN = 100; // Thời gian chờ giữa 2 phát bắn (ms)
const Uint32 BLINK_DURATION = 500;  // Thời gian nhấp nháy (mỗi lần 500ms)

int highScore = 0;
int backgroundY = 0;
int playerHealth = MAX_HEALTH;
int playerEnergy = 100;
bool energyDepleting = false;
bool isBlinking = true;
bool energyRecoveryDelay = false;
Uint32 lastBulletTime = 0;
Uint32 energyDepleteStart = 0;
Uint32 energyRecoverStart = 0;
Uint32 startBlinkTime = 0;
Uint32 recoverStart = 0;

std::vector<std::pair<SDL_Rect, int>> enemies;
std::vector<SDL_Rect> bullets;
struct Explosion {
    SDL_Rect rect;
    Uint32 startTime;
};
std::vector<Explosion> explosions;

bool running = true;
bool moveLeft = false, moveRight = false, shooting = false;

int score = 0;
const int START_MENU = 0;
const int IN_GAME = 1;
const int GAME_OVER = 2;
int gameState = START_MENU;

#endif // DEFS_H
