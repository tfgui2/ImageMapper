#include "myarear.h"
#include <QDebug>

MyArea::MyArea(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

QString MyArea::toString()
{
    QString key = "K";
    QRect r = this->rect();

    QString str = QString("<area target=\"\" alt=\"%1\" shape=\"rect\" coords=\"%2,%3,%4,%5\" onclick=\"sendClick('%6');\">")
            .arg(key)
            .arg(r.left()).arg(r.top()).arg(r.right()).arg(r.bottom())
            .arg(key);

    QStringList strlist;
    strlist << "<area";



    return str;
}

void MyArea::fromString(QString str)
{
    QStringList strlist = str.split(' ');
    qDebug() << strlist;
}

QVariant MyArea::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemSelectedHasChanged)
    {
        qDebug() << "selected" << value;
    }

    return QGraphicsItem::itemChange(change, value);
}
