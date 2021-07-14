### Description
Qt pdf display control based on pdfium  

No dependence  

Compile with vs2019, Qt5.15.2  

Fork from [qt-lbas/qtpdf](https://github.com/qt-labs/qtpdf) The following changes can also be made:
- Use cmake instead
- Fixed pdfium version to avoid compilation problems caused by pdfium upgrade
- Combine QtPdf and QtWidgets
- Remove the relevant code of the qt module, modify the name of the generated file to qpdf, to avoid the same name as the file in the Qt SDK


### Usage

```c++
#include <qpdfwindow.h>
QPdfWindow win("path_to_pdf_file.pdf");
win.show();
```


### Why not use QtPdf and QtWidgets in Qt SDK?
- The pdfviewer sample code in 5.15.2 failed to run

### qt-labs/qtpdf build steps
- Install Python3
- Install perl
- Modify qtpdf/src/3rdparty/gyp2pri.py:121 to
```Python
      For the key, the value in variables.items():
```
- Python and perl are added to environment variables
- cd %qtpdf%
- qmake
- nmake