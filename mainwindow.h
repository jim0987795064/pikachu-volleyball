#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"pika.h"
#include<QTimer>
#include<QThread>
#include<QGraphicsscene>
#include<QGraphicsview>
#include<QGraphicsPixmapItem>
#include<QTime>
#include<QtMath>
class MyItem:public QThread,public Pika//public QObject,public Pika
{
	Q_OBJECT
	public :
		void keyPressEvent(QKeyEvent *event);
		void mousePressEvent(QMouseEvent *event);
		//void paintEvent();
		MyItem(Pika *p2,Ball *b,QGraphicsPixmapItem *q,int t);
		MyItem(Pika *p1,Pika *p2,Ball *b,QGraphicsPixmapItem *q,int test);
		MyItem()
		{}
		bool one=false,two=false;
	private:
		bool enter=false,collide=false,collide2=false,collide3=false;
		Pika *pika1,*pika2;
		Ball *ball;
		int t,time1=0,time2=0,time3=0,timeb=0;
		qreal h1=0,h2=0,h3=0,hby=0,hbx=0,vby=0,vby0=0,vbx=(0),disx,dis,temp;
		qreal const v1=(-20),v2=(-20),v3=(-20);
		QTimer *timer,*timer1,*timer2,*timer3;
		QGraphicsPixmapItem *rod;
	public slots:
		void move();
		void ballmove();
		void move1();
		void move2();
};
#endif
