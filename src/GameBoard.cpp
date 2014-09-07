
#include "Ball.h"
#include "Bumper.h"
#include "Cartesian.h"
#include "GameBoard.h"
#include "Paddle.h"

#include "ObjectFactory.h"

#include <vector>


GameBoard::GameBoard(ObjectFactory * factory)
{
   factory->AddObject(this);
   this->id = GameObject::IdGameBoard;

   // Could do the following in a resource loader e.g. in a tagged text file
   Cartesian position, velocity, size;

   //this->scorekeeper = new Scorekeeper(factory);

   position.x = 320;
   position.y = 50;
   size.x = 620;
   size.y = 25;
   this->topBumper = new Bumper(factory, position, size);

   position.x = 320;
   position.y = 430;
   size.x = 620;
   size.y = 25;
   this->bottomBumper = new Bumper(factory, position, size);

   position.x = 25;
   position.y = 240;
   velocity.x = 0;
   velocity.y = 10;
   size.x = 10;
   size.y = 100;
   this->paddleA = new Paddle(factory, position, velocity, size);

   position.x = 615;
   position.y = 240;
   velocity.x = 0;
   velocity.y = 10;
   size.x = 10;
   size.y = 100;
   this->paddleB = new Paddle(factory, position, velocity, size);

   position.x = 200;
   position.y = 200;
   velocity.x = 5;
   velocity.y = 5;
   size.x = 10;
   size.y = 10;
   this->ball    = new Ball(factory, position, velocity, size);
}


GameBoard::~GameBoard()
{

}


void GameBoard::HandleInput(std::vector<InputEvent> input_events)
{
   // Doesn't react to input
}


void GameBoard::Update(std::vector<GameObject *> object_list, float dt)
{


}


void GameBoard::Render(float dt)
{


}
