#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include <QFileSystemWatcher>

class FileWatcher : public QFileSystemWatcher
{
    Q_OBJECT;
public slots:
    void StartWatching(const QString& filename);
    void StopWatching(const QString& filename);
};

#endif // FILEWATCHER_H
