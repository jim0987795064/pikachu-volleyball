#include"mainwindow.h"
#include"mythread.h"
#include<QApplication>
#include<QGraphicsscene>
#include<QGraphicsview>
#include<QGraphicsPixmapItem>
#include<QDebug>
#include<QGraphicsTextItem>
int main(int argc,char *argv[])
{
	QApplication a(argc,argv);
        /*QGraphicsScene *scene1=new QGraphicsScene();
        QGraphicsView *view1=new QGraphicsView(scene1);
        QGraphicsTextItem *text1=new QGraphicsTextItem();
        text1->setPlainText("One Player Press 1，Computer Fight Press 2");
        text1->setPos(200,500);
	scene1->setSceneRect(0,0,1000,1000);
        view1->setFixedSize(850,550);
	MyItem *ini=new MyItem();
	ini->setFlag(QGraphicsItem::ItemIsFocusable);
        ini->setFocus();
	scene1->addItem(ini);
	scene1->addItem(text1);
	view1->show();*/
	qsrand(QTime::currentTime().msec());
	int t=qrand()%2;
	qDebug()<<t;
	if(t==0)
	{
	QGraphicsScene *scene=new QGraphicsScene();
        QGraphicsView *view=new QGraphicsView(scene);
        scene->setSceneRect(0,0,1000,1000);
        view->setFixedSize(850,550);
	Ball *ball=new Ball();
	Pika *pika1=new Pika();
	Pika *pika2=new Pika();
	QGraphicsPixmapItem *background=new QGraphicsPixmapItem();
	QGraphicsPixmapItem *rod=new QGraphicsPixmapItem();
	MyItem *computer=new MyItem(pika1,pika2,ball,rod,t);
        background->setPixmap(QPixmap("./dataset/background3.png"));
        background->setX(0);
        background->setY(0);
        pika1->setPixmap(QPixmap("./dataset/pikachu_right.png"));
        pika1->setX(725);
	pika1->setY(400);
        ball->setPixmap(QPixmap("./dataset/pokeball3.png"));
        ball->setX(725);
	ball->setY(50);
	pika2->setPixmap(QPixmap("./dataset/pikachu_left.png"));
	pika2->setX(20);
	pika2->setY(399);
	rod->setX(257);
	rod->setY(243);
	rod->setPixmap(QPixmap("./dataset/rod.png"));
	scene->addItem(computer);
	scene->addItem(background);
	scene->addItem(ball);
	scene->addItem(pika1);
	scene->addItem(pika2);
	scene->addItem(rod);
	view->show();
	}
	if(t==1)
        {
        QGraphicsScene *scene=new QGraphicsScene();
        QGraphicsView *view=new QGraphicsView(scene);
        scene->setSceneRect(0,0,1000,1000);
        view->setFixedSize(850,550);
        Ball *ball=new Ball();
        Pika *pika2=new Pika();
        QGraphicsPixmapItem *background=new QGraphicsPixmapItem();
        QGraphicsPixmapItem *rod=new QGraphicsPixmapItem();
        MyItem *pika1=new MyItem(pika2,ball,rod,t);
        background->setPixmap(QPixmap("./dataset/background3.png"));
        background->setX(0);
        background->setY(0);
        pika1->setFlag(QGraphicsItem::ItemIsFocusable);
        pika1->setFocus();
        pika1->setPixmap(QPixmap("./dataset/pikachu_right.png"));
        pika1->setX(725);
        pika1->setY(400);
        ball->setFlag(QGraphicsItem::ItemIsFocusable);
        ball->setFocus();
        ball->setPixmap(QPixmap("./dataset/pokeball3.png"));
        ball->setX(725);
        ball->setY(50);
        pika2->setPixmap(QPixmap("./dataset/pikachu_left.png"));
        pika2->setX(20);
        pika2->setY(399);
        rod->setX(257);
        rod->setY(243);
        rod->setPixmap(QPixmap("./dataset/rod.png"));
        scene->addItem(background);
        scene->addItem(ball);
        scene->addItem(pika1);
        scene->addItem(pika2);
        scene->addItem(rod);
        view->show();
        }

return a.exec();
}
