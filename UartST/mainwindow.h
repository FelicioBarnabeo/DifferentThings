#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class PluginIOWindow;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    PluginIOWindow *pluginIOWindow;
    void createMenus();
    void createBar();
    QMenu *fileMenu;
    QToolBar *fileToolBar;
    QAction *openAct;
public:
    explicit MainWindow();
    ~MainWindow();

private slots:
    void openPort();

};

#endif // MAINWINDOW_H
