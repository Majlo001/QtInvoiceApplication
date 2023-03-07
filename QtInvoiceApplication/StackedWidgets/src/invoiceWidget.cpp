#include "invoiceWidget.h"

InvoiceWidget::InvoiceWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::invoiceWidgetClass)
{
	ui->setupUi(this);

	scrollArea = ui->scrollArea;
	scrollArea->setWidgetResizable(true);
	//scrollArea->setWidget(scrollWidget);
	scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

InvoiceWidget::~InvoiceWidget(){
	delete ui;
}
