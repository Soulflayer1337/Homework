#ifndef PROGRESSSLIDER_H
#define PROGRESSSLIDER_H

#include <QWidget>

namespace Ui {
class ProgressSlider;
}

class ProgressSlider : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressSlider(QWidget *parent = 0);
    ~ProgressSlider();

private slots:
    void on_slider_valueChanged(int value);

private:
    Ui::ProgressSlider *ui;
};

#endif // PROGRESSSLIDER_H
