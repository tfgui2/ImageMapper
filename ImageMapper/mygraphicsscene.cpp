#include "mygraphicsscene.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

MyGraphicsScene::MyGraphicsScene(QObject *parent) : QGraphicsScene(parent)
{

}

void MyGraphicsScene::updateDrawRect(QPointF scenePos)
{
    if (drawRect) {
        QRectF r;
        r.setTopLeft(drawRectPos);
        r.setBottomRight(scenePos);
        QRectF nr = r.normalized();
        drawRect->setRect(nr);
    }
}

void MyGraphicsScene::resetDrawRect()
{
    if (drawRect) {
        removeItem(drawRect);
        delete drawRect;
        drawRect = nullptr;
    }
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    resetDrawRect();
    drawRectPos = event->scenePos();
    drawRect = new QGraphicsRectItem(QRectF());
    addItem(drawRect);
}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF scenePos = event->scenePos();
    updateDrawRect(scenePos);
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF scenePos = event->scenePos();
    updateDrawRect(scenePos);

    // create area
    resetDrawRect();
}
