#include "quotes.h"
#include "ui_quotes.h"
#include <QGridLayout>
#include <QMessageBox>

Quotes::Quotes(QWidget *parent) :
    QWidget(parent),
    nextButton(new QPushButton("Next")),
    quoteText(new QTextEdit),
    rating(new QLineEdit("Rating")),
    webView(new QWebView),
    ui(new Ui::Quotes)
{
    ui->setupUi(this);

    QGridLayout *windowLayout = new QGridLayout;
    rating->setReadOnly(true);
    quoteText->setReadOnly(true);
    windowLayout->addWidget(rating, 0, 0, 1, 2);
    windowLayout->addWidget(nextButton, 0, 2);
    windowLayout->addWidget(quoteText, 1, 0, 4, 3);
    nextButton->setEnabled(false);

    setLayout(windowLayout);
    setFixedSize(400, 300);
    setWindowTitle("Best quotes(2011)");
    webView->load(QUrl("http://bash.im/bestyear/2007"));

    connect(webView, SIGNAL(loadFinished(bool)), this, SLOT(loadQuotes()));
    connect(nextButton, SIGNAL(clicked()), this, SLOT(nextQuote()));
}

Quotes::~Quotes()
{
    delete ui;
}

void Quotes::nextQuote()
{
    QString text;
    do
    {
        quoteIterator++;
        if (quoteIterator == quotesBlocks.end())
            quoteIterator = quotesBlocks.begin();
        text = quoteIterator->findFirst("div[class=text]").toPlainText();
    }
    while (text.isEmpty());

    quoteText->clear();
    quoteText->insertPlainText(text);
    rating->setText(quoteIterator->findFirst("span[class=rating-o]").toPlainText());
}

void Quotes::loadQuotes()
{
    if (!nextButton->isEnabled())
    {
        quotesBlocks = webView->page()->mainFrame()->findAllElements("div[class=quote]").toList();
        quoteIterator = --quotesBlocks.end();
        nextQuote();
        nextButton->setEnabled(true);
    }
}
