#include "mygraphicsscene.h"
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

MyGraphicsScene::MyGraphicsScene(QObject *parent) : QGraphicsScene(parent)
{
    editmode = Select;
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
    if (editmode == Draw) {
        resetDrawRect();
        drawRectPos = event->scenePos();
        drawRect = new QGraphicsRectItem(QRectF());
        addItem(drawRect);
        return;
    }

    QGraphicsScene::mousePressEvent(event);
}

void MyGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (editmode == Draw) {
        QPointF scenePos = event->scenePos();
        updateDrawRect(scenePos);
        return;
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void MyGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (editmode == Draw) {
        QPointF scenePos = event->scenePos();
        updateDrawRect(scenePos);

        if (drawRect) {
            QRectF r = drawRect->rect();
            addArea(r);
        }

        // create area
        resetDrawRect();
        return;
    }

    QGraphicsScene::mouseReleaseEvent(event);
}

void MyGraphicsScene::addArea(QRectF r)
{
    MyArea *a = new MyArea;
    a->setRect(r);
    areas.append(a);
    addItem(a);
}
