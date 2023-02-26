#pragma once

#include <QWidget>
#include "ui_dashboardWidget.h"

class DashboardWidget : public QWidget
{
	//Q_OBJECT

public:
	DashboardWidget(QWidget *parent = nullptr);
	~DashboardWidget();

private:
	Ui::Form *ui;
};
