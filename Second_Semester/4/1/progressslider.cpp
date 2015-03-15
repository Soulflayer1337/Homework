#include "progressslider.h"
#include "ui_progressslider.h"

ProgressSlider::ProgressSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressSlider)
{
    ui->setupUi(this);
}

ProgressSlider::~ProgressSlider()
{
    delete ui;
}

void ProgressSlider::on_slider_valueChanged(int value)
{
    ui->progressBar->setValue(value);
}
