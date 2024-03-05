#pragma once

class Player {
    private:
        unsigned int score{};
        unsigned int level{};
        unsigned int mode{};
    public:
        Player(unsigned int, unsigned int, unsigned int);
        void setScore(unsigned int);
        void setLevel(unsigned int);
        void setMode(unsigned int);
        unsigned int getScore();
        unsigned int getLevel();
        unsigned int getMode();
        void printPlayer();
};

