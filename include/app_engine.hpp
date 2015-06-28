#ifndef _APP_ENGINE_HPP_
#define _APP_ENGINE_HPP_

#include <QQmlApplicationEngine>

class ApplicationEngine : public QQmlApplicationEngine {
    Q_OBJECT
public:
    ApplicationEngine();
    static QUrl homeUrl();
};

#endif // _APP_ENGINE_HPP_