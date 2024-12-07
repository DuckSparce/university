#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "order.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    unsigned int getLength() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    Material getMaterial() const;
    unsigned int getCount() const;
    void fillForOrder(Order* order);

private slots:
    void on_pushButton_accept_clicked();
    void on_pushButton_cancel_clicked();

private:
    void deduceMaterial();
    Ui::AddDialog *ui;

    unsigned int length;
    unsigned int width;
    unsigned int height;
    Material material;
    unsigned int count;
};

#endif // DIALOG_H
