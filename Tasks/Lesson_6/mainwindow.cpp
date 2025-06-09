#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , userIsTypingSecondNumber(false)
{
    ui->setupUi(this);

    connect(ui->pb_0, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_1, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_2, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_3, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_4, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_5, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_6, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_7, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_8, &QPushButton::released, this, &MainWindow::digitPressed);
    connect(ui->pb_9, &QPushButton::released, this, &MainWindow::digitPressed);

    connect(ui->pb_sqrt, &QPushButton::released, this, &MainWindow::unaryOperationPressed);

    connect(ui->pb_add, &QPushButton::released, this, &MainWindow::binaryOperationPressed);
    connect(ui->pb_subtract, &QPushButton::released, this, &MainWindow::binaryOperationPressed);
    connect(ui->pb_multiply, &QPushButton::released, this, &MainWindow::binaryOperationPressed);
    connect(ui->pb_divide, &QPushButton::released, this, &MainWindow::binaryOperationPressed);
    connect(ui->pb_power, &QPushButton::released, this, &MainWindow::binaryOperationPressed);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed()
{
    QPushButton * button = (QPushButton*)sender();
    QString currentLabelText = ui->label->text();
    QString newLabel;

    if (userIsTypingSecondNumber || (currentLabelText == "0" && button->text() != "."))
    {
        newLabel = button->text();
        userIsTypingSecondNumber = false;
    }
    else
    {
        if(currentLabelText.contains('.') && button->text() == "0")
        {
            newLabel = currentLabelText + button->text();
        }
        else
        {
            newLabel = currentLabelText + button->text();
        }
    }

    double labelNumber = newLabel.toDouble();
    ui->label->setText(QString::number(labelNumber, 'g', 15));
}

void MainWindow::on_pb_decimal_released()
{
    if (!ui->label->text().contains('.')) {
        ui->label->setText(ui->label->text() + ".");
    }
}

void MainWindow::unaryOperationPressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->objectName() == "pb_sqrt")
    {
        labelNumber = ui->label->text().toDouble();
        if (labelNumber >= 0) {
            labelNumber = std::sqrt(labelNumber);
            newLabel = QString::number(labelNumber,'g',15);
        } else {
            newLabel = "Error";
        }
        ui->label->setText(newLabel);
    }
}


void MainWindow::on_pb_clear_released()
{
    // Ensure all operation buttons are unchecked
    ui->pb_add->setChecked(false);
    ui->pb_subtract->setChecked(false);
    ui->pb_multiply->setChecked(false);
    ui->pb_divide->setChecked(false);
    ui->pb_power->setChecked(false);

    userIsTypingSecondNumber = false;
    firstNumber = 0; // Reset firstNumber to 0
    ui->label->setText("0"); // Set display to 0
}

void MainWindow::on_pb_equals_released()
{
    double result = 0.0;
    double secondNumber = ui->label->text().toDouble();

    // Check which operator button was previously checked
    if (ui->pb_add->isChecked())
    {
        result = firstNumber + secondNumber;
    }
    else if (ui->pb_subtract->isChecked())
    {
        result = firstNumber - secondNumber;
    }
    else if (ui->pb_multiply->isChecked())
    {
        result = firstNumber * secondNumber;
    }
    else if (ui->pb_divide->isChecked())
    {
        if (secondNumber == 0) {
            ui->label->setText("Error: Div by 0");
            on_pb_clear_released(); // Reset state after error
            return;
        }
        result = firstNumber / secondNumber;
    }
    else if (ui->pb_power->isChecked())
    {
        result = std::pow(firstNumber, secondNumber);
    }
    // If no operation is checked, display current number (e.g., if "=" pressed repeatedly)
    else {
        result = secondNumber;
    }


    ui->label->setText(QString::number(result, 'g', 15));

    // After calculation, uncheck all operation buttons
    ui->pb_add->setChecked(false);
    ui->pb_subtract->setChecked(false);
    ui->pb_multiply->setChecked(false);
    ui->pb_divide->setChecked(false);
    ui->pb_power->setChecked(false);

    userIsTypingSecondNumber = false; // Reset for a new calculation chain
    // Keep the result in firstNumber if the user wants to continue operations with it
    firstNumber = result;
}

void MainWindow::binaryOperationPressed()
{
    QPushButton * button = (QPushButton*) sender();

    // Only store firstNumber and clear display IF we are not already typing the second number
    // This prevents clearing the second number if an operator is pressed consecutively (e.g. 5 + +)
    if (!userIsTypingSecondNumber)
    {
        firstNumber = ui->label->text().toDouble();
        ui->label->setText("0"); // Clear the display
    }

    // Uncheck all other binary operation buttons
    ui->pb_add->setChecked(false);
    ui->pb_subtract->setChecked(false);
    ui->pb_multiply->setChecked(false);
    ui->pb_divide->setChecked(false);
    ui->pb_power->setChecked(false);

    // Set the current operation button as checked
    button->setChecked(true);

    // Indicate that the user is now expected to type the second number
    userIsTypingSecondNumber = true;
}
