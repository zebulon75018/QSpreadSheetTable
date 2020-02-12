#include "mywebpage.h"
#include <QDebug>

MyWebPage::MyWebPage(QWidget *parent) : QWebPage(parent)
{

}
void MyWebPage::javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID)
{
   qDebug() << message;
}
