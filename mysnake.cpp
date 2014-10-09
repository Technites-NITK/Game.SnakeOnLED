#include<iostream>
#include<cstdlib>
#include<windows.h>
#include<queue>
#include<conio.h>


using namespace std;

enum Direction {RIGHT,LEFT,UP,DOWN};



class Snake
{
	queue<int* > SnakeSegment;

	Direction direction;
	int* head;
	int length;
  int face[8][32];
  int x,y,fruit_count,flag;
	
  bool isColliding(int head_x,int head_y,Direction direction)
  {
  	//cout<<direction<<endl;
  	//cout<<"x="<<head_x<<endl<<"y="<<head_y<<endl;
  
         if(direction==RIGHT)
         {
          if(face[head_y][head_x+1]==1)
		  return true;
		  else
		  return false;	
         }
		 if(direction==LEFT)
		 {
		 	if(face[head_y][head_x-1]==1){
		 	//	cout<<"head_x-1 is"<<head_x<<endl<<"value is "<<face[head_y][head_x-1]<<endl;
		  return true;
	       }
		  else
		  return false;
		 }
		 if(direction==UP)
		 {
		 	if(face[head_y-1][head_x]==1)
		  return true;
		  else
		  return false;
		 }
		 if(direction==DOWN)
		 {
		 	if(face[head_y+1][head_x]==1)
		  {
		  //	cout<<"Collided!"<<endl<<"x="<<head_x<<endl<<"y="<<head_y+1<<endl;
		  	//cout<<face[head_y+1][head_x]<<endl;
		  	return true;
		  }
		  else
		  return false;
		 } 
    	
  }	
  
  
  void fruit()
  {
  	
  	x=rand()%32;
  	y=rand()%8;
  	fruit_count++;
  	if(fruit_count==1)
  	{
  		if(face[y][x]==1)
  	    fruit();
  	    else
  	    face[y][x]=2;
  	}
  	
  	else
  	{
  		if(flag)
  		{
  				if(face[y][x]==1)
  	             fruit();
  	            else
  	            face[y][x]=2;
  	            
  	            flag=1;
  		}
  	}
  	
  }
  
  bool hasEaten()
  {
  	flag=!flag;
  	if(*SnakeSegment.back()==2)
  	return true;
  	else
  	return false;
  	
  	
  }
  
  
 public: void snakeInit()
  {
  	int x,y;
  	
  	for(int i=0;i<8;i++)
  	{
  		for(int j=0;j<32;j++)
  		face[i][j]=0;
  	}
  
	 
	  x=(rand()%25)+3,y=(rand()%2)+3;

  	  
  	 
  	 // cout<<"x="<<x<<"y="<<y;
  	
	  SnakeSegment.push(face[y]+x);
  	*SnakeSegment.back()=1;
  	
  	direction=static_cast <Direction>(rand()%4);
  	
 	switch(direction)
	  {
	  		case UP:
		   
		
			SnakeSegment.push(&face[y-1][x]);
			*SnakeSegment.back()=1;
			SnakeSegment.push(&face[y-2][x]);
			*SnakeSegment.back()=1;			
		 
		
			break;
		
		
		case DOWN:
		     
	
			SnakeSegment.push(&face[y+1][x]);
			*SnakeSegment.back()=1;
			SnakeSegment.push(&face[y+2][x]);
			*SnakeSegment.back()=1;
		
		
		
		
		break;
		
		
		case RIGHT:
		     
	
			SnakeSegment.push(&face[y][x+1]);
			*SnakeSegment.back()=1;
			SnakeSegment.push(&face[y][x+2]);
			*SnakeSegment.back()=1;
		
		
	
		break;
		
		case LEFT:
		 
			SnakeSegment.push(&face[y][x-1]);
			*SnakeSegment.back()=1;
			SnakeSegment.push(&face[y][x-2]);
			*SnakeSegment.back()=1;
		
	
		break;
    
	  	
	  } 
	  	/*for(int k=0;k<8;k++)
  {
  	for(int l=0;l<32;l++)
  	cout<<face[k][l];
  	cout<<endl;
  } 
	  */
  
  	length=3;
  	head=SnakeSegment.back();
  	if(direction==RIGHT)
  	snakeMove(x+2,y,RIGHT);
  	else if(direction==LEFT)
  	snakeMove(x-2,y,LEFT);
  	else if(direction==UP)
  	snakeMove(x,y-2,UP);
  	else if(direction==DOWN)
  	snakeMove(x,y+2,DOWN);
  	
  }
  
 /* void getInput(int head_x)
  {
  	//convert the key input into direction
    if (0<=head_x<=7)
  	{
  	    if(kbhit())// check if keyboard key is pressed
            {
             switch(getch())
             {
             case 'w':direction=UP;
             break;
             case 's':direction=DOWN;
             break; 
             case 'a':direction=LEFT;
             break;
             case 'd':direction=RIGHT;
             break;	//player 1 control
  	}
  }
}
  	
  	if(8<=head_x<=15)
  	{//player 2 control
  	if(kbhit())// check if keyboard key is pressed
            {
             switch(getch())
             {
             case 'w':direction=UP;
             break;
             case 's':direction=DOWN;
             break; 
             case 'a':direction=LEFT;
             break;
             case 'd':direction=RIGHT;
             break;	//player 1 control
  	}
  }
    }
    
    if(16<=head_x<=23)
    {
    	//player 3 control
    	if(kbhit())// check if keyboard key is pressed
            {
             switch(getch())
             {
             case 'w':direction=UP;
             break;
             case 's':direction=DOWN;
             break; 
             case 'a':direction=LEFT;
             break;
             case 'd':direction=RIGHT;
             break;	//player 1 control
  	}
  }
    }
    
    if(24<=head_x<=31)
    {
    	//player 4 control
    	if(kbhit())// check if keyboard key is pressed
            {
             switch(getch())
             {
             case 'w':direction=UP;
             break;
             case 's':direction=DOWN;
             break; 
             case 'a':direction=LEFT;
             break;
             case 'd':direction=RIGHT;
             break;	//player 1 control
  	}
  }
    }
    	
  }
  
 */ 
  void snakeMove(int head_x,int head_y,Direction direction)
  {
  	int count=0,old_direction;
  	fruit_count=0;
  	bool go= true;
  	while(go)
  	{
  		
  	
Sleep ( 500 );
  		
    old_direction=direction;
  	
  	//getInput(head_x);
  	if(kbhit())// check if keyboard key is pressed
            {
             switch(getch())
             {
             case 'w':direction=UP;
             if(old_direction==DOWN)
             direction=DOWN;
             break;
             case 's':direction=DOWN;
             if(old_direction==UP)
             direction=UP;
             break; 
             case 'a':direction=LEFT;
             if(old_direction==RIGHT)
             direction=RIGHT;
             break;
             case 'd':direction=RIGHT;
             if(old_direction==LEFT)
             direction=LEFT;
             break;	//player 1 control
  	}
  }
  	
  		if(isColliding(head_x,head_y,direction)||(head_y==0&&direction==UP)||(head_y==7&&direction==DOWN))
  	{
  		cout<<"game over";
  		go=false;
  		break;
  	}
  	
    switch(direction)
    {
    	case UP:
		  // if(old_direction != DOWN )
		//{
			
			SnakeSegment.push(&face[head_y-1][head_x]);
			
			if(!hasEaten())
			{
			*SnakeSegment.back()=1;
			*SnakeSegment.front()=0;
			SnakeSegment.pop();
	        }
		
		else
		{
			
			*SnakeSegment.back()=1;
		}
	
		head_y=head_y-1;
//	}
	

		break;
		
		
		
		
		
		
		
		case DOWN:
			
	//	      if(old_direction != UP)
	//	{
			SnakeSegment.push(&face[head_y+1][head_x]);
			if(!hasEaten())
			{
			*SnakeSegment.back()=1;
			*SnakeSegment.front()=0;
			SnakeSegment.pop();
		   }
		  
		   
		
		else
		{
		  	
			*SnakeSegment.back()=1;
		}
	  
		head_y=head_y+1;
	//  }
	  

	  
		break;
		
		
		
		
		
		
		
		
		
		
		
		case RIGHT:
	//	     if(old_direction != LEFT)
	//	{
			if(head_x==31)
			{
				SnakeSegment.push(&face[head_y][0]);
				head_x=0;
			}
			else 
			{
				SnakeSegment.push(&face[head_y][head_x+1]);
				head_x=head_x+1;
			}
			if(!hasEaten())
			{
			*SnakeSegment.back()=1;
			*SnakeSegment.front()=0;
			SnakeSegment.pop();
		   }
		 
		
		else
		{
			
			
			*SnakeSegment.back()=1;
		}
	
		//head_x=head_x+1;
//	}
	

		break;
		
		
		
		
		
		
		
		case LEFT:
//		  if(old_direction != RIGHT)
//		{
				if(head_x==0)
			{
				SnakeSegment.push(&face[head_y][31]);
				head_x=31;
			}
			else 
			{
				SnakeSegment.push(&face[head_y][head_x-1]);
				head_x=head_x-1;
			}
			
			if(!hasEaten())
			{
			
			*SnakeSegment.back()=1;
			*SnakeSegment.front()=0;
			SnakeSegment.pop();
		    }
		  
		
		else
		{
			
			
			*SnakeSegment.back()=1;
		}
	
	
		break;
		
  }
		
    
    head=SnakeSegment.back();
    count++;
  	if(count%20==0)
  	{
      fruit();  	
  	}
  	
  
  for(int k=0;k<8;k++)
  {
  	for(int l=0;l<32;l++)
  	{
  		if(l%8==0)
  		cout<<"  ";
  	   cout<<face[k][l];	
  	}
  	
  	cout<<endl;
  }
  
  cout<<endl<<endl;
}
}
};

int main()
{
	Snake saap;
//	Direction direction;
  //   int head_x,head_y;
	saap.snakeInit();

//saap.snakeMove(3,2,direction);


	
}



