#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEnginePage>
#include <QTimer>

struct SElementId;

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
    void on_m_getList_clicked();

    void on_m_today_clicked();

    void on_m_addPrj_clicked();

    void on_m_submit_clicked();

    void secCnt();

    void on_m_tableWidget_cellDoubleClicked(int row, int column);

protected:
    void htmlReader(QString html);

    static QString generateJsSelectFunction(const SElementId & elem, const int index);
    static QString generateJsFunction(const SElementId & elem);

    // callback methods (parsing), later on to be merged into one
    // and pass caller element to be able to determine
    // the target element for update
    void jsCallbackCostlist(const QVariant &v);
    void jsCallbackProject(const QVariant &v);
    void jsCallbackSubProject(const QVariant &v);
    void jsCallbackActivity(const QVariant &v);

    // callback methods (select index), later on to be merged into one
    // and pass caller element to be able to determine
    // the target element for update
    void jsCallbackSelectCostlist(const QVariant &v);
    void jsCallbackSelectProject(const QVariant &v);
    void jsCallbackSelectSubProject(const QVariant &v);
    void jsCallbackSelectActivity(const QVariant &v);

public slots:
    void pageLoadFinished(bool b);

    void slotAuthentication(const QUrl &requestUrl, QAuthenticator *authenticator);

    void slotComboIndexChangedCosts(int index);
    void slotComboIndexChangedProjects(int index);
    void slotComboIndexChangedSubProjects(int index);
    void slotComboIndexChangedActivity(int index);

    void slotComboIndexChanged(const QString & text);
    void slotComboIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    QWebEnginePage m_page;

    int m_costInd = -1;
    int m_projInd = -1;
    int m_subpInd = -1;
    int m_actiInd = -1;

    static const QMap<QString, SElementId> s_lists;
    static QString s_username;
    static QString s_password;

    QTimer m_cntTimer;
};

#endif // MAINWINDOW_H
