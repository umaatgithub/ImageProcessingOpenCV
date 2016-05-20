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
    //Constructor and Destructor
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //Slots for tool bar actions
    void on_actionNew_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionSave_As_triggered();
    void on_actionZoom_In_triggered();
    void on_actionZoom_Out_triggered();
    void on_actionSelect_triggered(bool checked);
    void on_actionCrop_triggered();
    void on_actionRegion_Of_Interest_triggered();
    void on_actionContrast_triggered();


    void updateZoomStatus(float value);                         //Slot to update the zoom value displayed in status bar
    void updateStatusBar(QString status, QColor statusColor);   //Slot to display temporary messages in status bar
    void enableCropAndROI(QRect* selectionRect);                //Slot to enable crop and ROI tool bar action

private:
    Ui::MainWindow *ui;                          //Pointer to mainwindow ui

protected:
    ImageChangeHistory *imageChangeHistory;     //Pointer to ImageChangeHistory for storing images
    QLabel *percentageZoomLabel;                //Status bar label for displaying image zoom

    void connectSignalsAndSlots();              //Connect all signals and slots
};

#endif // MAINWINDOW_H
