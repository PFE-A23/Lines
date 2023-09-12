#ifndef __ExportDialog_h_
#define __ExportDialog_h_

#include "ui_ExportDialog.h"
#include <QDialog>

class ExportDialog : public QDialog {

  Q_OBJECT

public:
  ExportDialog(QString &path, int width, int height, QWidget *parent = 0);
  ~ExportDialog();

  void GetResolution(QSize &res);
  QString GetFileName();
  bool IsExportingAlpha();

private slots:

  void on_browseButton_clicked();

private:
  Ui::ExportDialog ui;
};

#endif
