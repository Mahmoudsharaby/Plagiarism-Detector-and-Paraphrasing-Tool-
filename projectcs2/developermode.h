#ifndef DEVELOPERMODE_H
#define DEVELOPERMODE_H

#include <QDialog>
#include "HS/dict.h"
namespace Ui {
class developermode;
}
class mainwindow;
class developermode : public QDialog
{
    Q_OBJECT

public:
    explicit developermode(QWidget *parent = nullptr);
    ~developermode();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Paraphrasing_tool *para;
    Ui::developermode *ui;
};

#endif // DEVELOPERMODE_H
