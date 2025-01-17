#pragma once

#include <QWizard>

#include <vector>

#include <QCheckBox>
#include <QFuture>
#include <QKeyEvent>
#include <QLabel>
#include <QProgressDialog>
#include <QVector>

#include "../../Common/CommonTypes.h"
#include "../GUICommon.h"
#include "AutoRerollSeedData.h"
#include "SeedFinderPassPage.h"

class SeedFinderWizard : public QWizard
{
  Q_OBJECT

public:
  enum pageID
  {
    Start = 0,
    Instructions,
    SeedFinderPass,
    // This number is set to arbirtrarilly high to allow to create new finder pass pages on the fly,
    // but kept high enough so that it will never be hit normally before getting the seed finder
    // done
    End = 1000
  };

  SeedFinderWizard(QWidget* parent, const GUICommon::gameSelection game,
                   const AutoRerollSeedData autoRerollSeedData = AutoRerollSeedData());
  ~SeedFinderWizard();

  void accept() override;
  void reject() override;
  void keyPressEvent(QKeyEvent* event) override;

  std::vector<u32> getSeeds() const;

  static int numberPass;

signals:
  void onUpdateSeedFinderProgress(const long value);
  void onSeedFinderPassDone();

private:
  void nextSeedFinderPass();
  void pageChanged();
  void seedFinderPassDone();

  SeedFinderPassPage* getSeedFinderPassPageForGame();

  bool m_seedFinderDone = false;
  std::vector<u32> m_seeds;
  QVector<SeedFinderPassPage*> m_passPages;
  const GUICommon::gameSelection m_game;
  const AutoRerollSeedData m_autoRerollSeedData;
  bool m_cancelSeedFinderPass;
  QFuture<void> m_seedFinderFuture;
};

class StartPage : public QWizardPage
{
public:
  StartPage(QWidget* parent, const GUICommon::gameSelection game);

  int nextId() const override;
  QCheckBox* m_chkSkipInstructionPage;
};

class InstructionsPage : public QWizardPage
{
public:
  InstructionsPage(QWidget* parent, const GUICommon::gameSelection game);

  int nextId() const override;

private:
  QLabel* m_lblGameInstructions;
};

class EndPage : public QWizardPage
{
public:
  EndPage(QWidget* parent, const bool sucess, const GUICommon::gameSelection game, u32 seed = 0);

  int nextId() const override;

private:
  QLabel* m_lblResult;
};
