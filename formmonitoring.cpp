#include "formmonitoring.h"
#include "ui_formmonitoring.h"

Formmonitoring::Formmonitoring(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formmonitoring)
{
    ui->setupUi(this);
}

Formmonitoring::~Formmonitoring()
{
    delete ui;
}
