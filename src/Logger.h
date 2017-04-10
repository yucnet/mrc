#ifndef LOGGER_H
#define LOGGER_H 1

#include "Arduino.h"


class Logger {
public:

    Logger(String domain);

    enum LOGLEVEL { ERROR, WARNING, INFO };

    static unsigned long usTime;
    static unsigned long usTimeSinceLastCall;

    void resetTime();

    void time(String eventName);

    void error(String text,
               bool   test = false);

    void warning(String text,
                 bool   test = false);

    void info(String text,
              bool   test = false);

    void info(unsigned char *text,
              bool           test = false);

private:

    void log(LOGLEVEL lvl,
             String   text,
             bool     test = false);

    void log(LOGLEVEL       lvl,
             unsigned char *text,
             bool           test = false);

    String domain;
};

#endif // ifndef LOGGER_H