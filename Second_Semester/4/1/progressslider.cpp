#include "progressslider.h"
#include "ui_progressslider.h"

progressSlider::progressSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::progressSlider)
{
    ui->setupUi(this);
}

progressSlider::~progressSlider()
{
    delete ui;
}

void progressSlider::on_slider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}
