/*
    Copyright (C) 2014 Sialan Labs
    http://labs.sialan.org

    Kaqaz is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Kaqaz is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>

class Kaqaz;
class RepositoryPrivate;
class Repository : public QObject
{
    Q_OBJECT
public:
    Repository( Kaqaz *kaqaz );
    ~Repository();

    Q_INVOKABLE QString insert( const QString & path );
    Q_INVOKABLE QString getPath( const QString & id );
    Q_INVOKABLE QString repositoryPath();

    Q_INVOKABLE QString copyImageToRepository(const QString & path, int size );
    Q_INVOKABLE QString copyAudioToRepository(const QString & path );

public slots:
    void deleteFile( const QString & f );

private:
    QString generateID( const QString & path );

private:
    RepositoryPrivate *p;
};

#endif // REPOSITORY_H
