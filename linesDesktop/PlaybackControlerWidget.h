#ifndef __PlaybackControlerWidget_h_
#define __PlaybackControlerWidget_h_

#include <QIcon>
#include <QWidget>

class LinesCore;
class QHBoxLayout;
class QLineEdit;
class QSlider;
class QCheckBox;
class QSpacerItem;
class QLabel;
class QToolButton;

class PlaybackControlerWidget : public QWidget {

  Q_OBJECT

public:
  PlaybackControlerWidget(LinesCore *lc, QWidget *parent = 0);
  ~PlaybackControlerWidget();

  void SetHideFrameRate(bool hide);

private slots:

  // Ui-connected slots
  void OnCurrentFrameSliderValueChanged(int value);
  void OnFrameRateSliderValueChanged(int value);
  void PlayPauseButtonClicked();

  // Controler-connected slots
  void PlaybackStartStopSlot(bool isStart);
  void UpdateUi();
  void UpdateCurrentFrame();

private:
  void SetupUi();
  int IndexFromFrameRate(int ms);

  LinesCore *m_lines;
  static const int NumberOfFrameRates;
  static const int AvailableFrameRates[9];

  QHBoxLayout *mainLayout;
  QLineEdit *currentFrameLineEdit;
  QSlider *currentFrameSlider;
  QToolButton *playPauseButton;
  QIcon playIcon;
  QIcon pauseIcon;
  QSpacerItem *postLoopSpacer;
  QSlider *frameRateSlider;
  QLineEdit *frameRateLineEdit;
  QLabel *fpsLabel;
};

#endif
