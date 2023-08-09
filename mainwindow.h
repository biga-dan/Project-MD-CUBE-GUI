
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "system.h"
#include <QMainWindow>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
class QTimer;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void fileOpen();
    void fileInsert();
    void fileSave();
    void fileSaveAs();
    void start();
    void setRestLen();
    void setCenter();
    void forceComboChanged(int);
    void forceCheckBoxChanged(int);
    void editDelete();
    void editDuplicate();
    void editSelectAll();
    void stateRestore();
    void stateReset();
    void stateSave();
    void about();
    void aboutQt();
    void editButtonClicked();
    void massButtonClicked();
    void springButtonClicked();
    void fixedMassChanged(int);
    void showSpringsChanged(int);
    void adaptiveTimeStepChanged(int);
    void gridSnapChanged(int);
    void northChanged(int);
    void southChanged(int);
    void eastChanged(int);
    void westChanged(int);
    void collideChanged(int);
    void massValueChanged(double);
    void elasticityValueChanged(double);
    void kSpringValueChanged(double);
    void kDampValueChanged(double);
    void forceValueChanged(double);
    void miscValueChanged(double);
    void viscosityValueChanged(double);
    void stickinessValueChanged(double);
    void timeStepValueChanged(double);
    void precisionValueChanged(double);
    void gridSnapValueChanged(int);
    void tick();
    void updateControls();

private slots:
    void on_saveButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

protected:
    void closeEvent(QCloseEvent*) override;

private:
    void setCurrentFile(const QString&);
    void updateForceControls();
    void readSettings();
    void writeSettings();
    std::unique_ptr<Ui::MainWindow> ui;
    void overwriteFile();
    int force_;
    QString fileName_;
    QString currentDirectory_;
    System system_;
    System savedSystem_;
    QTimer* timer_;
};
#endif // MAINWINDOW_H
