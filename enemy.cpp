#include "globals.h"

cEnemy::cEnemy()
{
    hits = 0;
    sprite.load( "data/sprites/enemy" );
    visible = false;
}

cEnemy::~cEnemy()
{

}
