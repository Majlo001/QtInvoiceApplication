#include "dashboardWidget.h"

DashboardWidget::DashboardWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::Form)
{
	ui->setupUi(this);
}

DashboardWidget::~DashboardWidget()
{}
