#ifndef PROGRESSSLIDER_H
#define PROGRESSSLIDER_H

#include <QWidget>

namespace Ui {
class progressSlider;
}

class progressSlider : public QWidget
{
    Q_OBJECT

public:
    explicit progressSlider(QWidget *parent = 0);
    ~progressSlider();

private slots:
    void on_slider_valueChanged(int value);

private:
    Ui::progressSlider *ui;
};

#endif // PROGRESSSLIDER_H
