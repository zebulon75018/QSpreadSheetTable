#include "mywebpage.h"
#include "qspreadsheettable.h"
#include <QtWebKit/QWebView>
#include <QtGui/QVBoxLayout>
#include <QtCore/QUrl>

#define  QPSREADSHEET 1

QSpreadSheetTable::QSpreadSheetTable(QWidget *parent) : QWidget(parent)
{

   QWebView *webView  = new QWebView(this);
   MyWebPage *p = new MyWebPage();
   QVBoxLayout *layout = new QVBoxLayout(this);
   this->setLayout(layout);
   layout->addWidget(webView);
   //webView->setUrl(QUrl("https://bossanova.uk/jexcel/v2/"));
   webView->setPage(p);
    QWebSettings* settings = webView->settings();

    //settings->ssetAttribute(QWebSettings::AllowRunningInsecureContent, true);
    settings->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    settings->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
    settings->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,true);

#ifdef QPSREADSHEET
   webView->setHtml("<html>\
                    <script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/3.1.1/jquery.min.js'></script>\
                    <script src='https://cdnjs.cloudflare.com/ajax/libs/jexcel/2.1.0/js/jquery.jexcel.min.js'></script>\
                    <link rel='stylesheet' href='https://cdnjs.cloudflare.com/ajax/libs/jexcel/2.1.0/css/jquery.jexcel.min.css' type='text/css' />\
                    <div id='my'></div>\
                    <script>\
                    console.log('toto'); \
                    data = [\
                        ['jExcel', 'Jquery spreadsheet, javascript spreadsheet, jquery', 181],\
                        ['Handsontable', 'Another nice javascript spreadsheet plugin', 9284],\
                        ['Datatables', 'DataTables is a table enhancing plug-in for the jQuery library.', 5164],\
                    ];\
                    $('#my').jexcel({ data:data, colWidths: [ 300, 80, 100 ] });\
                    </script>\
                    </html>");
#else
   webView->setUrl(QUrl("http://localhost:5000"));
#endif
}

void	QSpreadSheetTable::setColumnCount(int columns)
{
   this->_nbColumns = columns;
}

