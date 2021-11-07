#pragma once

#include <QWidget>

#include <QCheckBox>
#include <QComboBox>
#include <QSlider>
#include <QSpinBox>

#include "../GUICommon.h"

class GeneralTab : public QWidget
{
public:
  GeneralTab(QWidget* parent = nullptr);

  int getThreadLimit() const;
  int getPredictionTime() const;
  int getFrameOffset() const;
  int getMaxAutoReroll() const;
  double getMinAdvancesFactor() const;
  double getMaxAdvancesFactor() const;
  bool getRestorePreviousWindowGeometry() const;

  void setThreadLimit(const int threadLimit);
  void setPredictionTime(const int predictionTime);
  void setFrameOffset(const int frameDelay);
  void setMaxAutoReroll(const int maxAutoReroll);
  void setMinAdvancesFactor(const double factor);
  void setMaxAdvancesFactor(const double factor);
  void setRestorePreviousWindowGeometry(const bool restoreGeometry);

private:
  QComboBox* m_cmbThreadLimit;
  QSpinBox* m_spbPredictionsTime;
  QSpinBox* m_spbFrameOffset;
  QSpinBox* m_spbMaxAutoReroll;
  QSlider* m_sldMinAdvancesFactor;
  QSlider* m_sldMaxAdvancesFactor;
  QCheckBox* m_chkRestorePreviousWindowGeometry;
};
