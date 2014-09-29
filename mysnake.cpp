#include<iostream>
#include<queue>
using namespace std;

enum Direction {RIGHT,LEFT,UP,DOWN};
//
class Snake
{
	queue<int> SnakeSegment;

	Direction direction;
	int head,length;
	int face[8][32];
	
  bool isColliding()
  {
  	if(head==1)
  	return true;
  	
  	else
  	return false;
  }	
  
  
  void fruit()
  {
  	int x,y;
  	x=rand()%32;
  	y=rand()%8;
  	face[x][y]=2;
  }
  
  bool hasEaten()
  {
  	if(head==2)
  	return true;
  	else
  	return false;
  }
  
  
 public: void snakeInit()
  {
  	SnakeSegment.push(face[3][0]);
  	SnakeSegment.back()=1;
  	SnakeSegment.push(face[3][1]);
  	SnakeSegment.back()=1;
  	SnakeSegment.push(face[3][2]);
  	SnakeSegment.back()=1;
  	length=3;
  	direction=RIGHT;
  	head=SnakeSegment.back();
  }
  
  void getInput(int head_x)
  {
  	//convert the key input into direction
    if (0<=head_x<=7)
  	{
  		//player 1 control
  	}
  	
  	if(8<=head_x<=15)
  	{//player 2 control
    }
    
    if(16<=head_x<=23)
    {
    	//player 3 control
    }
    
    if(24<=head<=31)
    {
    	//player 4 control
    }
    	
  }
  
  
  void snakeMove(int head_x,int head_y,Direction direction)
  {
  	int count=0;
  	bool go= true;
  	while(go)
  	{
  		
  		
  		
  	if(isColliding()||(head_y==0&&direction==UP)||(head_y==8&&direction==DOWN))
  	{
  		cout<<"game over";
  		go=false;
  		break;
  	}
  	
  	getInput(head_x);
  	
    switch(direction)
    {
    	case UP:
		   if(direction != DOWN && !hasEaten())
		{
			SnakeSegment.push(face[head_x][head_y-1]);
			SnakeSegment.back()=1;
			SnakeSegment.front()=0;
			SnakeSegment.pop();
		} 
		
		else if (direction !=DOWN && hasEaten())
		{
			SnakeSegment.push(face[head_x][head_y-1]);
			SnakeSegment.back()=1;
		}
		
		head_y=head_y-1;
		break;
		
		
		case DOWN:
		      if(direction != UP && !hasEaten())
		{
			SnakeSegment.push(face[head_x][head_y+1]);
			SnakeSegment.back()=1;
			SnakeSegment.front()=0;
			SnakeSegment.pop();
		} 
		
		else if (direction !=UP && !hasEaten())
		{
			SnakeSegment.push(face[head_x][head_y+1]);
			SnakeSegment.back()=1;
		}
		head_y=head_y+1;
		break;
		
		
		case RIGHT:
		     if(direction != LEFT && !hasEaten())
		{
			SnakeSegment.push(face[head_x-1][head_y]);
			SnakeSegment.back()=1;
			SnakeSegment.front()=0;
			SnakeSegment.pop();
		} 
		
		else if (direction !=LEFT && hasEaten())
		{
			SnakeSegment.push(face[head_x-1][head_y]);
			SnakeSegment.back()=1;
		}
		head_x=head_x-1;
		break;
		
		case LEFT:
		  if(direction != RIGHT && !hasEaten())
		{
			SnakeSegment.push(face[head_x+1][head_y]);
			SnakeSegment.back()=1;
			SnakeSegment.front()=0;
			SnakeSegment.pop();
		} 
		
		else if (direction !=DOWN && hasEaten())
		{
			SnakeSegment.push(face[head_x+1][head_y]);
			SnakeSegment.back()=1;
		}
		head_x=head_x+1;
		break;
    }
    head=SnakeSegment.back();
    count++;
  	if(count%5==0)
  	fruit();
  }
}
};

int main()
{
	//Snake saap;
	//saap.snakeInit();
//	Direction direction=RIGHT;
//	saap.snakeMove(3,2,direction);


	
}
