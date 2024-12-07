#ifndef AFFINITYDIALOG_H
#define AFFINITYDIALOG_H

#include <QDialog>
#include <windows.h>

namespace Ui {
class AffinityDialog;
}

class AffinityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AffinityDialog(DWORD mask);
    ~AffinityDialog();

    DWORD mask() const;
    void setMask(DWORD newMask);

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_set_clicked();

private:
    Ui::AffinityDialog *ui;
    DWORD mask_;
};

#endif // AFFINITYDIALOG_H
