#include"mainwindow.h"
#include"mythread.h"
#include<QPainter>
#include<QImage>
#include<QKeyEvent>
#include<QDebug>
#include<ctime>
#include<unistd.h>
#include<QDebug>
#include<QGraphicsscene>
#include<QGraphicsview>
#include<QSound>
MyItem::MyItem(Pika *p2,Ball *b,QGraphicsPixmapItem *r,int test)
{
	pika2=p2;
	ball=b;
	rod=r;
	t=test;
		timer1=new QTimer();
        	timer2=new QTimer();
		timer1->start(50);
        	connect(timer1,SIGNAL(timeout()),this,SLOT(ballmove()));
		timer2->start(50);
        	connect(timer2,SIGNAL(timeout()),this,SLOT(move1()));
		
}
MyItem::MyItem(Pika *p1,Pika *p2,Ball *b,QGraphicsPixmapItem *r,int test)
{
	pika1=p1;
        pika2=p2;
        ball=b;
        rod=r;
	t=test;
                timer1=new QTimer();
                timer2=new QTimer();
            	timer3=new QTimer();
	    	timer1->start(50);
                connect(timer1,SIGNAL(timeout()),this,SLOT(move1()));
                timer2->start(50);
                connect(timer2,SIGNAL(timeout()),this,SLOT(move2()));
		 timer3->start(50);
                connect(timer3,SIGNAL(timeout()),this,SLOT(ballmove()));

}


void MyItem::keyPressEvent(QKeyEvent *event)
{
	if(event->key()==Qt::Key_Up&&enter==false)
        {
			timer=new QTimer();
			enter=true;
			timer->start(50);
			connect(timer,SIGNAL(timeout()),this,SLOT(move()));
	
	//	ball->setY(ball->y()-10);
	//	ball->setPos(ball->x(),ball->y());

	}
        if(event->key()==Qt::Key_Left)
        {
		if((this->x()-10)<415)
			 this->setX(415);
		else
               		this->setX(this->x()-10);
               this->setPos(this->x(),this->y());
	//	ball->setX(ball->x()-10);
          //      ball->setPos(ball->x(),ball->y());

	}
         if(event->key()==Qt::Key_Right)
        {
		 if((this->x()+10)>820)
                         this->setX(415);
                else
                this->setX(this->x()+10);
                this->setPos(this->x(),this->y());
	
	}
	  if(event->key()==Qt::Key_Down)
	  {	  
	  }

}

void MyItem::move()
{
	time1++;
	h1=v1*time1+0.5*(time1*time1);
	this->setY(400+h1);
        this->setPos(this->x(),this->y());
       	if(this->y()>=400)
	{
		h1=0;
                time1=0;
		enter=false;
                this->setY(400);
                this->setPos(this->x(),this->y());
                timer->stop();
		delete timer;
        }

}
void MyItem::ballmove()
{
	if(t==1)
  	if(this->collidesWithItem(ball,Qt::IntersectsItemShape)&&collide==false)
                {
			QSound::play("./dataset/pika.wav");
			collide=true;
			if(this->y()>ball->y())
				vby=(-28);
			if(this->y()<ball->y())
				vby=28;
			if((this->x()+25)>=(ball->x()+40))
				vbx=(-5);
			if((this->x()+25)<=(ball->x()+40))
                        	vbx=5;
				timeb=0;
                }
	 if(pika2->collidesWithItem(ball,Qt::IntersectsItemShape)&&collide==false)
                {
			QSound::play("./dataset/pika.wav");
                        collide=true;
                        if(pika2->y()>ball->y())
                                vby=(-28);
                        if(pika2->y()<ball->y())
                                vby=28;
                        if((pika2->x()+25)>=(ball->x()+40))
                                vbx=(-5);
                        if((pika2->x()+25)<=(ball->x()+40))
                                vbx=5;
                                timeb=0;
                }
	 if(t==0)
	 if(pika1->collidesWithItem(ball,Qt::IntersectsItemShape)&&collide==false)
                {
			QSound::play("./dataset/pika.wav");
                        collide=true;
                        if(pika1->y()>ball->y())
                                vby=(-28);
                        if(pika1->y()<ball->y())
                                vby=28;
                        if((pika1->x()+25)>=(ball->x()+40))
                                vbx=(-5);
                        if((pika1->x()+25)<=(ball->x()+40))
                                vbx=5;
                                timeb=0;
                }
	 if(t==1)	
	 if((this->collidesWithItem(ball,Qt::IntersectsItemShape)==false)&&(pika2->collidesWithItem(ball,Qt::IntersectsItemShape)==false))
		collide=false;
	 
	 if(t==0)
	 if((pika1->collidesWithItem(ball,Qt::IntersectsItemShape)==false)&&(pika2->collidesWithItem(ball,Qt::IntersectsItemShape)==false))
                collide=false;

	//qDebug()<<collide2;
	timeb++;
	hby=(vby*timeb+0.5*(timeb*timeb))-(vby*(timeb-1)+0.5*((timeb-1)*(timeb-1)));
	hbx=vbx;
	if(ball->collidesWithItem(rod,Qt::IntersectsItemShape))
	{
		hbx=0;
                vbx*=(-1);
	}
	if((ball->y()+hby)>390)
	{
		ball->setY(390);
		timeb=0;
		//vby*=(-1);
		//vby0=vby;
		//current-=0.5;
		//vby+=1;
		
		vby=(-28);
	}
	else if((ball->y()+hby)<0)
	{	
		ball->setY(0);
		//timeb=0;
		//vby*=(-1);
		temp=vby+0.5*timeb;
		vby=(-temp);
		timeb=0;
	}
	else
	ball->setY(ball->y()+hby);
	if((ball->x()+hbx)>735)
	{   
	   	ball->setX(735);
		vbx*=(-1);
		//vbx+=1;
	}
	else if((ball->x()+hbx)<0)
	{        
		ball->setX(0);
		vbx*=(-1);
		//vbx-=1;
	}
	else	
	ball->setX(ball->x()+hbx);
	ball->setPos(ball->x(),ball->y());
}

void MyItem::move1()
{
	
	disx=(pika2->x())-(ball->x());	 
       	if(disx>0&&(ball->x()<350))
        {
		if((pika2->x()-5)<0)
                        pika2->setX(0);
		else
			pika2->setX(pika2->x()-5);
        }
        if(disx<0&&(ball->x()<350))
        {
		if((pika2->x()+5)>400)
                        pika2->setX(400);
		else
			pika2->setX(pika2->x()+5);
        }
	if(pika2->collidesWithItem(ball,Qt::IntersectsItemShape))
		collide2=true;
	if(ball->x()<(pika2->x()+50)||(collide2==true))
	{
		time2++;
        	h2=v2*time2+0.5*(time2*time2);
        	pika2->setY(400+h2);
        	if(pika2->y()>400)
        	{
			if(ball->x()>420)
			collide2=false;
                	h2=0;
                	time2=0;
                	pika2->setY(400);
		}
	}
	pika2->setPos(pika2->x(),pika2->y());

}

void MyItem::move2()
{

        dis=(pika1->x())-(ball->x());
        if(dis>0&&(ball->x()>410))
        {
                if((pika1->x()-5)<410)
                        pika1->setX(410);
                else
                        pika1->setX(pika1->x()-5);
        }
	else if(dis<0&&(ball->x()>410))
        {
                if((pika1->x()+5)>800)
                        pika1->setX(800);
                else
                        pika1->setX(pika1->x()+5);
        }
	else
	{
		if(pika1->x()<650)
		 pika1->setX(pika1->x()+5);
	}
        if(pika1->collidesWithItem(ball,Qt::IntersectsItemShape))
                collide3=true;
        if((ball->x()+40)<(pika1->x())||(collide3==true))
        {
                time3++;
                h3=v3*time3+0.5*(time3*time3);
                pika1->setY(400+h3);
                if(pika1->y()>400)
                {
                        if(ball->x()<300)
                        collide3=false;
                        h3=0;
                        time3=0;
                        pika1->setY(400);
                }
        }
        pika1->setPos(pika1->x(),pika1->y());

}

