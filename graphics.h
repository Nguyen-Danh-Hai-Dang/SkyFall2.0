#ifndef GRAPHICS
#define GRAPHICS
#include "defs.h"
struct Graphics{
// Biến toàn cục
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* backgroundTexture = nullptr;
SDL_Texture* playerTexture = nullptr;
SDL_Texture* enemyTextures[3] = {nullptr, nullptr, nullptr};
SDL_Texture* bulletTexture = nullptr;
SDL_Texture* explosionTexture = nullptr;
SDL_Texture* startMenuImage = nullptr;
SDL_Texture* gameOverImage = nullptr;
TTF_Font* font = nullptr;
Mix_Chunk* shootSound = nullptr;
Mix_Chunk* explosionSound = nullptr;
Mix_Music* bgMusic = nullptr;
SDL_Color textColor = {255, 255, 255, 255};
SDL_Rect player = {SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 160, 100, 100};
SDL_Rect startButtonRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT - 100, 200, 50};
SDL_Rect RestartButtonRect = {SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT - 350, 200, 50};

SDL_Texture* loadTexture(const char* path) {
    SDL_Surface* surface = IMG_Load(path);
    if (!surface) {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
SDL_Texture* renderText(const std::string& text) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
void init() {
    SDL_Init(SDL_INIT_VIDEO);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            std::cerr << "SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    srand(time(0));
    window = SDL_CreateWindow("Mini Airplane Shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    backgroundTexture = loadTexture("background.png");
    playerTexture = loadTexture("player.png");
    enemyTextures[0] = loadTexture("enemy1.png");
    enemyTextures[1] = loadTexture("enemy2.png");
    enemyTextures[2] = loadTexture("enemy3.png");
    bulletTexture = loadTexture("bullet.png");
    explosionTexture = loadTexture("explosion.png");
    startMenuImage = loadTexture("start_menu.png");
    gameOverImage = loadTexture("game_over.png");
    font = TTF_OpenFont("arial.ttf", 24);
    shootSound = Mix_LoadWAV("shootSound.wav");
    explosionSound = Mix_LoadWAV("explosionSound.wav");
    bgMusic = Mix_LoadMUS("bgMusic.mp3");

}
void resetGame() {
    playerHealth = MAX_HEALTH;
    playerEnergy = 100;
    score = 0;
    enemies.clear();
    bullets.clear();
    explosions.clear();
    player = {SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 160, 100, 100};
    energyDepleting = false;
    energyRecoveryDelay = false;
    energyDepleteStart = 0;
    energyRecoverStart = 0;
    backgroundY = 0;
}
void closeAudio() {
    Mix_FreeMusic(bgMusic);
    Mix_FreeChunk(shootSound);
    Mix_CloseAudio();
}
void cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void renderButton(const std::string& text, SDL_Rect rect);
void shoot();
void Start_Menu();
void In_Game();
void Game_Over();
void handleEvents();
void update();
void render();
};

#endif
