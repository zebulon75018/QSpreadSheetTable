#include "mainwindow.h"
#include "qspreadsheettable.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QSpreadSheetTable *sw =new QSpreadSheetTable(this);
    this->setCentralWidget(sw);
}

MainWindow::~MainWindow()
{

}
