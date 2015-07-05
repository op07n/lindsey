#include "app_engine.hpp"

#include <QCoreApplication>
#include <QObject>
#include <QUrl>
#include <QStringList>

ApplicationEngine::ApplicationEngine()
{ 
    load(QUrl("qrc:/lindsey_window.qml"));
    
    rootObject = rootObjects().first();
    
    const QUrl homeUrl = ApplicationEngine::homeUrl();
    QMetaObject::invokeMethod(rootObject, "setHomeUrl", Q_ARG(QVariant, homeUrl));
    QMetaObject::invokeMethod(rootObject, "loadUrl", Q_ARG(QVariant, homeUrl));
}

QUrl ApplicationEngine::homeUrl()
{
    QUrl ret;
    QStringList args(qApp->arguments());
    args.takeFirst();
    Q_FOREACH (const QString& arg, args) {
        if (arg.startsWith(QLatin1Char('-')))
             continue;
        ret = QUrl::fromUserInput(arg);
        if (ret.isValid())
            return ret;
    }
    
    return QUrl(QStringLiteral("http://www.kipr.org"));
}

void ApplicationEngine::callScrollUp()
{
  QMetaObject::invokeMethod(rootObject, "scrollUp");
}

void ApplicationEngine::callScrollDown()
{
  QMetaObject::invokeMethod(rootObject, "scrollDown");
}