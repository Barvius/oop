#pragma once

class Shape {
protected:
	int x;
	int y;
	int speedX=0;
	int speedY=0;
	float color[3];
public:
	//Shape(int nX, int nY);
	//virtual ~Shape() {};
	//void setX(int X);
	//void setY(int Y);
	//int getX();
	//int getY();
	virtual void Move(int,int) = 0;
	virtual void Draw() = 0;
	virtual int GetSize() = 0;
	virtual int GetPosX() = 0;
	virtual int GetPosY() = 0;
	virtual void SetSpeedX(int) = 0;
	virtual void SetSpeedY(int) = 0;
	virtual int GetSpeedX() = 0;
	virtual int GetSpeedY() = 0;
};
