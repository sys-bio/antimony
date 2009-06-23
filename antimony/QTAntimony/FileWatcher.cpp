#include "FileWatcher.h"

void FileWatcher::StartWatching(const QString& filename)
{
    addPath(filename);
}

void FileWatcher::StopWatching(const QString& filename)
{
    removePath(filename);
}
