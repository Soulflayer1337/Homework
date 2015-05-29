#ifndef QUOTES_H
#define QUOTES_H

#include <QWidget>
#include <QWebView>
#include <QWebElement>
#include <QWebFrame>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>

namespace Ui {
class Quotes;
}

class Quotes : public QWidget
{
    Q_OBJECT

public:
    explicit Quotes(QWidget *parent = 0);
    ~Quotes();

private slots:
    void nextQuote();
    void loadQuotes();

private:
    QPushButton *nextButton;
    QTextEdit *quoteText;
    QLineEdit *rating;

    QWebView *webView;
    QList<QWebElement> quotesBlocks;
    QList<QWebElement>::iterator quoteIterator;

    Ui::Quotes *ui;
};

#endif // QUOTES_H
