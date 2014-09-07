
#ifndef __GAMEBOARD_H
#define __GAMEBOARD_H

#include "Ball.h"
#include "Bumper.h"
#include "GameBoard.h"
#include "Paddle.h"

#include "GameObject.h"
#include "ObjectFactory.h"

#include <vector>


class GameBoard : public GameObject
{
public:
   GameBoard(ObjectFactory * factory);
   ~GameBoard();

   void HandleInput(std::vector<InputEvent> input_events);
   void Update(std::vector<GameObject *> object_list, float dt);
   void Render(float dt);

private:
   Bumper * topBumper;
   Bumper * bottomBumper;
   Paddle * paddleA;
   Paddle * paddleB;
   Ball   * ball;
};

#endif __GAMEBOARD_H
