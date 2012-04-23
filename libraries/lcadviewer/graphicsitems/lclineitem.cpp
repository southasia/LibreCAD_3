#include "graphicsitems/lclineitem.h"

LCLineItem::LCLineItem(lc::LinePtr l) : LCGraphicsItem(), _line(l) {
}


QRectF LCLineItem::boundingRect() const {
    return QRectF(_line->start().x(),
                  _line->start().y(),
                  _line->end().x() - _line->start().x(),
                  _line->end().y() - _line->start().y()).normalized();
}

void LCLineItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {

    LCGraphicsItem::paint(_line, painter, option, widget);

    painter->drawLine(
        QPointF(_line->start().x(), _line->start().y()),
        QPointF(_line->end().x(), _line->end().y())
    );
}

QPainterPath LCLineItem::shape() const {
    QPainterPath path;
    path.moveTo(_line->start().x(), _line->start().y());
    path.lineTo(_line->end().x(), _line->end().y());
    return path;
}

const lc::CADEntityPtr LCLineItem::entity() const {
    return _line;
}