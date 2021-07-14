#include "qpdfwindow.h"
#include "qpdfdocument.h"
#include "qpdfview.h"
#include <QVBoxLayout>
#include <QLabel>

QPdfWindow::QPdfWindow(const QString& title, const QString& path, QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle(title);
    setWindowFlag(Qt::Window);
    setMinimumSize(800, 600);

    auto doc = new QPdfDocument(this);
    auto err = doc->load(path);
    QLabel* label = nullptr;
    QPdfView* view = nullptr;
    switch (err)
    {
    case QPdfDocument::NoError:
        view = new QPdfView;
        view->setDocument(doc);
        view->setPageMode(QPdfView::MultiPage);
        break;
    case QPdfDocument::UnknownError:
    default:
        label = new QLabel(tr("Unknown error"));
        break;
    case QPdfDocument::FileNotFoundError:
        label = new QLabel(tr("File not found %1").arg(path));
        break;
    case QPdfDocument::InvalidFileFormatError:
        label = new QLabel(tr("Invalid file format %1").arg(path));
        break;
    case QPdfDocument::IncorrectPasswordError:
        label = new QLabel(tr("Incorrect password %1").arg(path));
        break;
    case QPdfDocument::UnsupportedSecuritySchemeError:
        label = new QLabel(tr("Unsupported security scheme %1").arg(path));
        break;
    }

    auto hl = new QVBoxLayout(this);
    hl->setContentsMargins(0, 0, 0, 0);
    if (label != nullptr)
    {
        label->setAlignment(Qt::AlignCenter);
        hl->addWidget(label);
    }
    if (view != nullptr)
    {
        hl->addWidget(view);
    }
}

QPdfWindow::QPdfWindow(const QString& path, QWidget* parent)
    : QPdfWindow(path, path, parent)
{

}
