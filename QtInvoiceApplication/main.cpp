#include "QtInvoiceApplication.h"
#include <QtWidgets/QApplication>
#include <QSizeGrip>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtInvoiceApplication w;
    QSizeGrip* sizeGrip = new QSizeGrip(&w);
    //sizeGrip->setFixedSize(16, 16);
    //sizeGrip->move(w.width() - sizeGrip->width(), w.height() - sizeGrip->height());


    //w.setWindowFlags(sizeGrip, Qt::AlignBottom | Qt::AlignRight);
    w.show();
    return a.exec();
}
