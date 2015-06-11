#ifndef QUIZ_H
#define QUIZ_H



// minimum 16-bit unsigned int 2D vector
typedef struct {
    uint_fast16_t x;
    uint_fast16_t y;
} vec2ui;


// at least 16-bit int 2D vector
typedef struct {
    uint_fast16_t x;
    uint_fast16_t y;
} vec2i;


// simple integer rectangle type
typedef struct {
    vec2i offset;
    vec2i bounds;

    uint_fast16_t top() { return offset.y; }
    uint_fast16_t bot() { return offset.y + bounds.y; }
    uint_fast16_t left() { return offset.x; }
    uint_fast16_t right() { return offset.x + bounds.x; }

    uint_fast16_t width() { return bounds.x; }
    uint_fast16_t height() { return bounds.y; }

    bool contains(vec2i a) { return (a.x >= offset.x && a.x < right()) && 
                                    (a.y >= offset.y && a.y < bot()); }
} rect;


struct enemy{
    vec2i pos;
};

struct star {
    vec2i pos;
};


int init();
void run();

void skipMenu(bool);
void setDifficulty(int);
void setTime(int);

void applyColorscheme(short fg, short bg);
void winResize(int &orig_x, int &orig_y);
void setFrame();
void enemyAI();
void moveStars();

void drawEnergyBar(int);

#endif
