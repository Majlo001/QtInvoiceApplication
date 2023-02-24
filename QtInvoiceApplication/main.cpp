#include "QtInvoiceApplication.h"
#include <QtWidgets/QApplication>
#include <QSizeGrip>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtInvoiceApplication w;
    //QGridLayout* layout = new QGridLayout(&w);
    //QSizeGrip* sizeGrip = new QSizeGrip(&w);


    //layout->addWidget(sizeGrip, 0, Qt::AlignBottom | Qt::AlignRight);
    //layout->addWidget(sizeGrip, 0,0,1,1, Qt::AlignBottom | Qt::AlignRight);


    //w.setLayout(layout);
    w.show();
    return a.exec();
}
