#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "myarear.h"
#include "enum.h"

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MyGraphicsScene(QObject *parent = 0);

signals:

public slots:
    void setMode(EditMode mode) { editmode = mode; }

protected:
    QGraphicsRectItem *drawRect = nullptr;
    QPointF drawRectPos;
    void resetDrawRect();
    void updateDrawRect(QPointF scenePos);


    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QList<MyArea*> areas;
    EditMode editmode;
    void addArea(QRectF r);
};

#endif // MYGRAPHICSSCENE_H
