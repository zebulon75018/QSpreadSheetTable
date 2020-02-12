#ifndef MYWEBPAGE_H
#define MYWEBPAGE_H

#include <QWebPage>

class MyWebPage : public QWebPage
{
    Q_OBJECT
public:
    explicit MyWebPage(QWidget *parent = nullptr);

signals:

public slots:

protected:
    virtual void javaScriptConsoleMessage(const QString & message, int lineNumber, const QString & sourceID);

};

#endif // MYWEBPAGE_H
