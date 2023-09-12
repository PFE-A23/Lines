#include "drwScene.h"
#include "drwTimelineWidget.h"
#include <QApplication>
#include <QScrollArea>

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  drwScene scene;
  drwTimelineWidget widget;
  widget.SetScene(&scene);
  widget.setMinimumSize(800, 300);
  // widget.show();

  QScrollArea *area = new QScrollArea();
  area->setWidget(&widget);
  area->show();

  return a.exec();
}
