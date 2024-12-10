#include <QApplication>
#include <QWindow>
#include <QStyle>
#include <QScreen>



int main(int argc, char **argv) {
  QApplication app(argc, argv);
  QWindow w;
  w.setHeight(500);
  w.setWidth(400);
  w.setGeometry(
    QStyle::alignedRect(
        Qt::LeftToRight,
        Qt::AlignCenter,
        w.size(),
        app.primaryScreen()->geometry()
    )
);
  w.show();
  
  return app.exec();
}