#ifndef AFFINITYDIALOG_H
#define AFFINITYDIALOG_H

#include <QDialog>
#include <sys/types.h>
#include <sched.h>

namespace Ui {
class AffinityDialog;
}

class AffinityDialog : public QDialog {
    Q_OBJECT

public:
    explicit AffinityDialog(cpu_set_t mask);
    ~AffinityDialog();

    cpu_set_t mask() const;
    void setMask(cpu_set_t newMask);

private slots:
    void on_pushButton_cancel_clicked();
    void on_pushButton_set_clicked();

private:
    Ui::AffinityDialog *ui;
    cpu_set_t mask_;
};

#endif // AFFINITYDIALOG_H
