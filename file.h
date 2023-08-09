

#ifndef FILE_H
#define FILE_H

#include <QString>

enum FileCmd { FileNone, FileLoad, FileSave, FileInsert };

class System;

bool fileCommand(const QString&, FileCmd, System&);

#endif
