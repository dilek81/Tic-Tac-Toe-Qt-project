// main.cpp
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>
#include <QMessageBox>

class TicTacToe : public QWidget {
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);

private slots:
    void buttonClicked();

private:
    QPushButton *buttons[3][3];
    bool isXTurn;
    void checkWinner();
};

TicTacToe::TicTacToe(QWidget *parent) : QWidget(parent), isXTurn(true) {
    QGridLayout *layout = new QGridLayout;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j] = new QPushButton("", this);
            buttons[i][j]->setFixedSize(100, 100);
            layout->addWidget(buttons[i][j], i, j);
            connect(buttons[i][j], &QPushButton::clicked, this, &TicTacToe::buttonClicked);
        }
    }

    setLayout(layout);
}

void TicTacToe::buttonClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if (button->text() != "") return; // Button already clicked

    button->setText(isXTurn ? "X" : "O");
    isXTurn = !isXTurn;
    checkWinner();
}

void TicTacToe::checkWinner() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (buttons[i][0]->text() == buttons[i][1]->text() && buttons[i][1]->text() == buttons[i][2]->text() && buttons[i][0]->text() != "") {
            QMessageBox::information(this, "Winner", QString("%1 Wins!").arg(buttons[i][0]->text()));
            return;
        }

        if (buttons[0][i]->text() == buttons[1][i]->text() && buttons[1][i]->text() == buttons[2][i]->text() && buttons[0][i]->text() != "") {
            QMessageBox::information(this, "Winner", QString("%1 Wins!").arg(buttons[0][i]->text()));
            return;
        }
    }

    if (buttons[0][0]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][2]->text() && buttons[0][0]->text() != "") {
        QMessageBox::information(this, "Winner", QString("%1 Wins!").arg(buttons[0][0]->text()));
        return;
    }

    if (buttons[0][2]->text() == buttons[1][1]->text() && buttons[1][1]->text() == buttons[2][0]->text() && buttons[0][2]->text() != "") {
        QMessageBox::information(this, "Winner", QString("%1 Wins!").arg(buttons[0][2]->text()));
        return;
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TicTacToe window;
    window.show();
    return app.exec();
}

