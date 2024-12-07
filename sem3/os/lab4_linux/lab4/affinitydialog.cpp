#include "affinitydialog.h"
#include "ui_affinitydialog.h"
#include <sched.h>

AffinityDialog::AffinityDialog(cpu_set_t mask)
    : QDialog()
    , ui(new Ui::AffinityDialog) {
    ui->setupUi(this);
    mask_ = mask;

    ui->checkBox_0->setChecked(CPU_ISSET(0, &mask));
    ui->checkBox_1->setChecked(CPU_ISSET(1, &mask));
    ui->checkBox_2->setChecked(CPU_ISSET(2, &mask));
    ui->checkBox_3->setChecked(CPU_ISSET(3, &mask));
    ui->checkBox_4->setChecked(CPU_ISSET(4, &mask));
    ui->checkBox_5->setChecked(CPU_ISSET(5, &mask));
    ui->checkBox_6->setChecked(CPU_ISSET(6, &mask));
    ui->checkBox_7->setChecked(CPU_ISSET(7, &mask));
}

AffinityDialog::~AffinityDialog() {
    delete ui;
}

void AffinityDialog::on_pushButton_cancel_clicked() {
    reject();
}

void AffinityDialog::on_pushButton_set_clicked() {
    CPU_ZERO(&mask_);

    if (ui->checkBox_0->isChecked()) CPU_SET(0, &mask_);
    if (ui->checkBox_1->isChecked()) CPU_SET(1, &mask_);
    if (ui->checkBox_2->isChecked()) CPU_SET(2, &mask_);
    if (ui->checkBox_3->isChecked()) CPU_SET(3, &mask_);
    if (ui->checkBox_4->isChecked()) CPU_SET(4, &mask_);
    if (ui->checkBox_5->isChecked()) CPU_SET(5, &mask_);
    if (ui->checkBox_6->isChecked()) CPU_SET(6, &mask_);
    if (ui->checkBox_7->isChecked()) CPU_SET(7, &mask_);

    accept();
}

cpu_set_t AffinityDialog::mask() const {
    return mask_;
}
