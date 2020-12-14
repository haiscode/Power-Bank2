#ifndef FORMMONITORING_H
#define FORMMONITORING_H

#include <QWidget>

namespace Ui {
class Formmonitoring;
}

class Formmonitoring : public QWidget
{
    Q_OBJECT

public:
    explicit Formmonitoring(QWidget *parent = nullptr);
    ~Formmonitoring();

private:
    Ui::Formmonitoring *ui;
};

#endif // FORMMONITORING_H
