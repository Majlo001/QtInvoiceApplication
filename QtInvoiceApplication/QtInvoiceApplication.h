#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtInvoiceApplication.h"


class QtInvoiceApplication : public QMainWindow
{
    Q_OBJECT

public:
    QtInvoiceApplication(QWidget *parent = nullptr);
    ~QtInvoiceApplication();

private:
    Ui::MainWindow *ui;
};


//ui
//QSizeGrip* sizeGrip = new QSizeGrip(styleSheet);
//sizeGrip->setFixedSize(16, 16);
//horizontalLayout->addWidget(sizeGrip, 0, Qt::AlignBottom | Qt::AlignRight);