#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit MyGraphicsScene(QObject *parent = 0);

signals:

public slots:

protected:
    QGraphicsRectItem *drawRect = nullptr;
    QPointF drawRectPos;
    void resetDrawRect();
    void updateDrawRect(QPointF scenePos);


    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYGRAPHICSSCENE_H
