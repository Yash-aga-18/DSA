#ifndef HERO_H
#define HERO_H

class Hero {
public:
    char name[100];
    int health;
    char level;

    // basic functions (declaration only)
    void setHealth(int h);
    int getHealth();

    void setLevel(char l);
    char getLevel();
};

#endif
