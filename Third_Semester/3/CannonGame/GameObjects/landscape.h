#pragma once

#include <QObject>
#include <QVector>

class GameClass;

class Landscape : public QObject
{
    Q_OBJECT
public:
    explicit Landscape(GameClass *parent);

    void setHeight(int height);

    void setField(const QVector<int> &newField);
    const QVector<int> &getField() const;

    void setHeightAt(int position, uint value);
    int getHeightAt(int position) const;

    int getWidth() const;
    int getHeight() const;
private:
    GameClass *gameClass_;
    QVector<int> field_;
    int height_;
};
