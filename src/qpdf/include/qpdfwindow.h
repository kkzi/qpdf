#pragma once


#include "qtpdfglobal.h"
#include <QtWidgets/QWidget.h>


class Q_PDF_EXPORT QPdfWindow : public QWidget
{
    Q_OBJECT

public:
    QPdfWindow(const QString& title, const QString& path, QWidget* parent = nullptr);
    QPdfWindow(const QString& path, QWidget* parent = nullptr);
};
