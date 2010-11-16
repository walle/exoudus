#ifndef ENEMY_H
#define ENEMY_H

class cEnemy : public cShip
{
    public:
            cEnemy();
            ~cEnemy();

    //private:
            int hits;
            int life;
            int speed;
            bool visible;
};

#endif
