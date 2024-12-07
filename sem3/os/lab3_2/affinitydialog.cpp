#include "affinitydialog.h"
#include "ui_affinitydialog.h"

AffinityDialog::AffinityDialog(DWORD mask)
    : QDialog()
    , ui(new Ui::AffinityDialog)
{
    ui->setupUi(this);
    mask_ = mask;

    ui->checkBox_0->setChecked((mask & (1 << 0)));
    ui->checkBox_1->setChecked((mask & (1 << 1)));
    ui->checkBox_2->setChecked((mask & (1 << 2)));
    ui->checkBox_3->setChecked((mask & (1 << 3)));
    ui->checkBox_4->setChecked((mask & (1 << 4)));
    ui->checkBox_5->setChecked((mask & (1 << 5)));
    ui->checkBox_6->setChecked((mask & (1 << 6)));
    ui->checkBox_7->setChecked((mask & (1 << 7)));
    ui->checkBox_8->setChecked((mask & (1 << 8)));
    ui->checkBox_9->setChecked((mask & (1 << 9)));
    ui->checkBox_10->setChecked((mask & (1 << 10)));
    ui->checkBox_11->setChecked((mask & (1 << 11)));
    ui->checkBox_12->setChecked((mask & (1 << 12)));
    ui->checkBox_13->setChecked((mask & (1 << 13)));
    ui->checkBox_14->setChecked((mask & (1 << 14)));
    ui->checkBox_15->setChecked((mask & (1 << 15)));
}

AffinityDialog::~AffinityDialog() {
    delete ui;
}

void AffinityDialog::on_pushButton_cancel_clicked() {
    reject();
}


void AffinityDialog::on_pushButton_set_clicked() {
    mask_ = 0;
    mask_ |= (ui->checkBox_0->isChecked() << 0);
    mask_ |= (ui->checkBox_1->isChecked() << 1);
    mask_ |= (ui->checkBox_2->isChecked() << 2);
    mask_ |= (ui->checkBox_3->isChecked() << 3);
    mask_ |= (ui->checkBox_4->isChecked() << 4);
    mask_ |= (ui->checkBox_5->isChecked() << 5);
    mask_ |= (ui->checkBox_6->isChecked() << 6);
    mask_ |= (ui->checkBox_7->isChecked() << 7);
    mask_ |= (ui->checkBox_8->isChecked() << 8);
    mask_ |= (ui->checkBox_9->isChecked() << 9);
    mask_ |= (ui->checkBox_10->isChecked() << 10);
    mask_ |= (ui->checkBox_11->isChecked() << 11);
    mask_ |= (ui->checkBox_12->isChecked() << 12);
    mask_ |= (ui->checkBox_13->isChecked() << 13);
    mask_ |= (ui->checkBox_14->isChecked() << 14);
    mask_ |= (ui->checkBox_15->isChecked() << 15);

    accept();
}

DWORD AffinityDialog::mask() const {
    return mask_;
}

