#ifndef MYAREAR_H
#define MYAREAR_H

#include <QGraphicsRectItem>

class MyArea : public QGraphicsRectItem
{
public:
    explicit MyArea(QGraphicsItem *parent = 0);
    QString toString();
    void fromString(QString str);

protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);


};

#endif // MYAREAR_H
