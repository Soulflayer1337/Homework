#pragma once

#include <QGraphicsObject>
#include <QVector>

class GameClass;

/**
 * \brief The Landscape class is a model of a landscape
 */
class Landscape : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Landscape();

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

    /// \brief sets the height of the window.
    void setHeight(int height);

    /// \brief sets the field by using the vector of vertecies.
    /// The size of the vector is the width of the new field.
    void setField(const QVector<int> &newField);
    const QVector<int> &getField() const;

    void setHeightAt(int position, uint value);
    int getHeightAt(int position) const;

    /// \brief returns the width of the field.
    int getWidth() const;
    int getHeight() const;

private:
    QPainterPath path_;
    QVector<int> field_;
    int height_;
};
