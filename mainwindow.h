#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLabel>
#include "imagechangehistory.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_As_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void updateZoomStatus(float value);

    void updateStatusBar(QString status, QColor statusColor);

    void on_actionSelect_triggered(bool checked);

    void on_actionCrop_triggered();

    void on_actionRegion_Of_Interest_triggered();

    void enableCropAndROI(QRect& selectionRect);

    void on_actionContrast_triggered();

private:
    Ui::MainWindow *ui;

protected:
    ImageChangeHistory *imageChangeHistory;
    QLabel *percentageZoomLabel;

    void connectSignalsAndSlots();
};

#endif // MAINWINDOW_H
