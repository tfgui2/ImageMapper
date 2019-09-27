#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
    void resetDrawRect();

    void updateDrawRect(QPointF scenePos);

public:
    explicit MyGraphicsScene(QObject *parent = 0);

signals:

public slots:

protected:
    QGraphicsRectItem *drawRect = nullptr;
    QPointF drawRectPos;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYGRAPHICSSCENE_H
