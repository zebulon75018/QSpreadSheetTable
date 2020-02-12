#ifndef QSPREADSHEETTABLE_H
#define QSPREADSHEETTABLE_H

#include <QWidget>


class QSpreadSheetTable : public QWidget
{
    Q_OBJECT
public:
    explicit QSpreadSheetTable(QWidget *parent = nullptr);

    void	setColumnCount(int columns);
signals:

public slots:

private:
    int _nbColumns;
};

#endif // QSPREADSHEETTABLE_H
